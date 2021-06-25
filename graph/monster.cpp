//https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>

typedef long double ld;
#define int long long

#define gcd            __gcd
#define endl           "\n"
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define f              first
#define s              second
#define lb             lower_bound
#define ub             upper_bound
#define ins            insert
#define sz(x)          (int)(x).size()
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.f << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NITIN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int n,m;
char a[1001][1001];
bool vis[1001][1001];
int dist[1001][1001];
pair<int,int> par[1001][1001];
int dist_a[1001][1001];
int si,sj;
int ei=-1,ej=-1;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void solve() {
    cin>>n>>m;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                si = i;
                sj = j;
            } else if (a[i][j] == 'M') {
                v.push_back({i, j});
            }
        }
    }
    //multisource bfs
    queue<pair<int,int>>q;
    for(auto &c:dist) {
        for (auto &d:c) {
            d = inf;
        }
    }
    for(auto &c:dist_a) {
        for (auto &d:c) {
            d = inf;
        }
    }
    for(auto &c:v) {
        q.push(c);
        vis[c.f][c.s] = true;
        dist[c.f][c.s] = 0;
    }
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = p.f + dx[k];
            int nj = p.s + dy[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && a[ni][nj] != '#') {
                q.push({ni, nj});
                vis[ni][nj] = true;
                dist[ni][nj] = dist[p.f][p.s] + 1;
            }
        }
    }
    //normal bfs
    memset(vis,false,sizeof vis);
    memset(par,-1,sizeof par);
    q.push({si,sj});
    dist_a[si][sj]=0;
    vis[si][sj]=true;
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = p.f + dx[k];
            int nj = p.s + dy[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && !vis[ni][nj] && a[ni][nj] != '#') {
                q.push({ni, nj});
                vis[ni][nj] = true;
                par[ni][nj]=p;
                dist_a[ni][nj] = dist_a[p.f][p.s] + 1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(dist[i][j]>dist_a[i][j]){
                    ei=i;
                    ej=j;
                    break;
                }
            }
        }
    }
    if(ei==-1){
        cout<<"NO"<<endl;
        return;
    }
    string ans;
    pair<int,int>curr={ei,ej};
    while(curr!=pair<int,int>{si,sj}) {
        pair<int, int> p = par[curr.f][curr.s];
        if (p.f == curr.f) {
            if (p.s > curr.s) {
                ans += 'L';
            } else {
                ans += 'R';
            }
        } else {
            if (p.f > curr.f) {
                ans += 'U';
            } else {
                ans += 'D';
            }
        }
        curr = p;
    }
    cout<<"YES"<<endl;
    cout<<ans.length()<<endl;
    reverse(all(ans));
    for(auto &c:ans){
        cout<<c;
    }
    cout<<endl;

}

int32_t main() {
    nitin;

    solve();
}