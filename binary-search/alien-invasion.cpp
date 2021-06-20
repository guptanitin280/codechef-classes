//https://www.codechef.com/problems/ALIENIN
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


int n;
double d;
double a[100001];
//it return if we can shoot down the spaceships if the cool down time is tme
bool f(double tme) {
    double curr = a[0] + tme;
    for (int i = 1; i < n; i++) {
        if (a[i] + d >= curr) {
            curr = max(curr, a[i]);
            curr += tme;
        } else {
            return false;
        }
    }
    return true;
}
void solve() {
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    double l=0; // returns one
    double r=1e10; // returns zero
    for(int i=0;i<=100;i++){ //**************
        double mid=(l+r)/2;
        if(f(mid)){
            l=mid;
        }else{
            r=mid;
        }
    }
    cout<<fixed<<setprecision(10)<<l<<endl;
}

int32_t main() {
    nitin;
    w(t)
        solve();
}