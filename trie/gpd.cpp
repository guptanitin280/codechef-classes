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

map<int,int>root;

struct node {
    int left = 0, right = 0;
    int cnt = 0;
};
node a[9000001];
int ptr=2;
struct p_trie{
    p_trie() {
        root[0] = 1;
    }
    void insert(int par_id,int curr_id,int k){
        root[curr_id]=ptr++;
        int par_node=root[par_id];
        int curr_node=root[curr_id];
        for(int i=30;i>=0;i--){
            if((k&(1ll<<i))) {
                a[curr_node].left = a[par_node].left;
                a[curr_node].right = ptr++;
                curr_node = a[curr_node].right;
                par_node = a[par_node].right;
            }else{
                a[curr_node].right=a[par_node].right;
                a[curr_node].left=ptr++;
                curr_node=a[curr_node].left;
                par_node=a[par_node].left;
            }
            a[curr_node].cnt=a[par_node].cnt+1;
        }
    }
    int max_xor(int id,int k){
        int curr=root[id];
        int ans=0;
        for(int i=30;i>=0;i--){
            if((k&(1ll<<i))){
                if(a[curr].left){
                    ans|=(1ll<<i);
                    curr=a[curr].left;
                }else{
                    curr=a[curr].right;
                }
            }else{
                if(a[curr].right){
                    ans|=(1ll<<i);
                    curr=a[curr].right;
                }else{
                    curr=a[curr].left;
                }
            }
        }
        return ans;
    }
    int min_xor(int id,int k){
        int curr=root[id];
        int ans=0;
        for(int i=30;i>=0;i--){
            if((k&(1ll<<i))){
                if(a[curr].right){
                    curr=a[curr].right;
                }else{
                    ans|=(1ll<<i);
                    curr=a[curr].left;
                }
            }else{
                if(a[curr].left){
                    curr=a[curr].left;
                }else{
                    ans|=(1ll<<i);
                    curr=a[curr].right;
                }
            }
        }
        return ans;
    }
};

void solve() {
    int n,q;
    cin>>n>>q;
    int r,key;
    cin>>r>>key;
    p_trie t;
    t.insert(0,r,key);
    for(int i=0;i<n-1;i++){
        int u,v,k;
        cin>>u>>v>>k;
        t.insert(v,u,k);
    }
    int last=0;
    while(q--) {
        int type;
        cin >> type;
        type ^= last;
        if (type == 0) {
            int v, u, k;
            cin >> v >> u >> k;
            v ^= last;
            u ^= last;
            k ^= last;
            t.insert(v, u, k);
        } else {
            int v, k;
            cin >> v >> k;
            v ^= last;
            k ^= last;
            int min_xor = t.min_xor(v, k);
            int max_xor = t.max_xor(v, k);
            cout << min_xor << " " << max_xor << endl;
            last = min_xor ^ max_xor;
        }
    }

}

int32_t main() {
    nitin;

    solve();
}