//https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>

typedef long double ld;
//#define int long long

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

int dp[100001];
int s_dp[100001];
void solve() {
    int n,x;
    cin>>n>>x;
    int cost[n+1],pages[n+1];
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i =1;i<=n;i++){
        cin>>pages[i];
    }
    for(int i=1;i<=n;i++){
        memset(s_dp,0,sizeof dp);
        for(int j=0;j<=x;j++){
            s_dp[j]=max(s_dp[j],dp[j]);
            if(j>=cost[i])
                s_dp[j]=max(s_dp[j],dp[j-cost[i]]+pages[i]);
        }
        for(int j=0;j<=x;j++){
            dp[j]=s_dp[j];
        }
    }
    cout<<*max_element(dp,dp+x+1)<<endl;


}

int32_t main() {
    nitin;

    solve();
}