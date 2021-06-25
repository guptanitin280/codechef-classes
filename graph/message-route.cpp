//https://cses.fi/problemset/task/1667
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
vector<int>v[100001];
bool vis[100001];
int par[100001];
int dist[100001];
void bfs(int source) {
    vis[source] = true;
    queue<int> q;
    q.push(source);
    for (auto &c:dist) {
        c = inf;
    }
    dist[source] = 0;
    memset(par, -1, sizeof par);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto &c:v[node]) {
            if (!vis[c]) {
                par[c] = node;
                dist[c] = dist[node] + 1;
                q.push(c);
                vis[c] = true;
            }
        }
    }
}
void solve() {
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(0);
    if(!vis[n-1]){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<dist[n-1]+1<<endl;
    int curr=n-1;
    vector<int>path;
    while(curr!=-1){
        path.push_back(curr);
        curr=par[curr];
    }
    reverse(all(path));
    for(auto &c:path){
        cout<<c+1<<" ";
    }
    cout<<endl;
}

int32_t main() {
    nitin;

    solve();
}