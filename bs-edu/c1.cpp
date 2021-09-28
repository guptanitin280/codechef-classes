#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
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
int n;
double x[100000];
double v[100000];
bool good(double m)
{
    double ss=-1e18;
    double se=+1e18;
    for(int i=0;i<n;i++)
    {
        double s=x[i]-m*v[i];
        double e=x[i]+m*v[i];
        if(s>=ss && e<=se)
        {
            ss=s;
            se=e;
        }
        else if(e<ss || s>se)
        {
            return false;
        }
        else{
            ss=max(ss,s);
            se=min(se,e);
        }
    }
    return true;
}
int32_t main() {
    nitin;
    cin>>n;
    counter(n)
    {
        cin>>x[i]>>v[i];
    }
    double s=0;
    double e=1e10;
    for(int i=0;i<70;i++)
    {
        double mid=(s+e)/2;
        if(good(mid))
            e=mid;
        else
            s=mid;
    }
    cout<<deci(e,10)<<endl;
    return 0;
}