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
int n,d;
int a[100001];
int l,r;
bool poss(double val)
{
    double pre[n+1];
    pre[0]=0;
    for(int i=1;i<=n;i++)
    {
        pre[i]=a[i-1]-val;
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]+=pre[i-1];
    }
    double m[n+1];
    int index[n+1];
    index[0]=0;
    m[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(m[i-1]<=pre[i])
        {
            index[i]=index[i-1];
            m[i]=m[i-1];
        }
        else{
            index[i]=i;
            m[i]=pre[i];
        }
    }
    for(int i=d;i<=n;i++)
    {
        if(pre[i]>=m[i-d])
        {
            r=i;
            l=index[i-d]+1;
            return true;
        }
    }
    return false;
}
int32_t main() {
    nitin;
    cin>>n>>d;
    for(int i=0;i<n;i++) cin>>a[i];
    double s=-1;
    double e=101;
    for(int i=0;i<=100;i++)
    {
        double m=(s+e)/2;
        if(poss(m))
            s=m;
        else
            e=m;
    }
    cout<<l<<" "<<r<<endl;
    return 0;
}