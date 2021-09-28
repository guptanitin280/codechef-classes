#include <bits/stdc++.h>
// 1. bs
#define int long long
#define cf(i, a, b)       for(int i=a;i<=b;i++)
#define cb(i, a, b)       for(int i=a;i<=b;i--)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;
int n,k;
double a[100001],b[100001];
bool good(double mid)
{
    vector<double>v;
    for(int i=0;i<n;i++)
    {
        v.push_back(a[i]-mid*b[i]);
    }
    sort(v.begin(),v.end(),greater<double>());
    double sum=0;
    for(int i=0;i<k;i++)
        sum+=v[i];
    return sum>=0;
}
int32_t main() {
    nitin;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    double s=0;
    double e=1e10+1;
    for(int i=0;i<=100;i++)
    {
        double m=(s+e)/2;
        if(good(m)) s=m;
        else e=m;
    }
    cout<<setprecision(20)<<fixed<<s<<endl;
    return 0;
}