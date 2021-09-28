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
int n;
int a[100001];
int first(int val)
{
    int s=0;
    int e=n+1;
    while (s+1<e)
    {
        int mid=(s+e)/2;
        if(a[mid]<val)
            s=mid;
        else
            e=mid;
    }
    return e;
}
int second(int val)
{
    int s=0;
    int e=n+1;
    while(s+1<e)
    {
        int mid=(s+e)/2;
        if(a[mid]<=val)
            s=mid;
        else
            e=mid;
    }
    return s;
}
int32_t main() {
    nitin;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i+1];
    sort(a+1,a+n+1);
    w(t)
    {
        int l,r;
        cin>>l>>r;
        //        cout<<second(r)<<" "<<first(l)<<endl;
        cout<<second(r)-first(l)+1<<endl;
    }
    return 0;
}