// https://www.codechef.com/LRNDSA04/problems/EURON/
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
int a[100001];
void merge(int l,int mid,int r) {
    vector<int> v;
    int p = l;
    int q = mid + 1;
    while (p <= mid && q <= r) {
        if (a[p] <= a[q]) {
            v.push_back(a[p++]);
        } else {
            v.push_back(a[q++]);
        }
    }
    while (p <= mid) v.push_back(a[p++]);
    while (q <= r) v.push_back(a[q++]);
    int i = 0;
    int j = l;
    while (j <= r) {
        a[j++] = v[i++];
    }
}
int solve(int l,int r){
    if(l>=r){
        return 0;
    }
    int mid=(l+r)/2;
    int left=solve(l,mid);
    int right=solve(mid+1,r);
    int curr=0;
    for(int i=l;i<=mid;i++){
        int s=mid;
        int e=r+1;
        while(s+1<e){
            int middle=(s+e)/2;
            if(a[middle]<a[i]){
                s=middle;
            }else{
                e=middle;
            }
        }
        curr+=(s-mid);
    }
    merge(l,mid,r);
    return left+right+curr;
}

void solve() {
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(0,n-1)<<endl;
}

int32_t main() {
    nitin;

    solve();
}