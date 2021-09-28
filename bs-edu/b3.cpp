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
bool good(int mid,int n,int x,int y)
{
    return (mid/x+mid/y)>=n;
}
int32_t main() {
    nitin;
    int n,x,y;
    cin>>n>>x>>y;
    if(x>y)
        swap(x,y);
    int l=0;
    int r=y*n;
    for(int i=0;i<100;i++)
    {
        int mid=(l+r)/2;
        if(good(mid,n-1,x,y))
            r=mid;
        else
            l=mid;
    }
    cout<<r+x<<endl;
    return 0;
}