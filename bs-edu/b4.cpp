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
int m,n;
int *t,*z,*y;
bool good(int time)
{
    int sum=0;
    for(int i=0;i<n;i++){
        int timess=((time+y[i])/(z[i]*t[i]+y[i]));
        int time_left=time-(z[i]*t[i]+y[i])*timess;
        sum+=timess*z[i]+max((int)0,min((time_left/t[i]),z[i]));
    }
    return sum>=m;
}
int32_t main() {
    nitin;
    cin>>m>>n;
    t=new int[n];
    z=new int[n];
    y=new int[n];
    if(m==0)
    {
        cout<<0<<endl;
        for(int i=0;i<n;i++)
            cout<<0<<" ";
        return 0;
    }
    for(int i=0;i<n;i++)
        cin>>t[i]>>z[i]>>y[i];
    int l=0;
    int r=200*15000;
    while(r>l+1)
    {
        int mid=(l+r)/2;
        if(good(mid))
        {
            r=mid;
        }
        else{
            l=mid;
        }
    }
    vector<int>ans;
    cout<<r<<endl;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int time=r;
        int timess=((time+y[i])/(z[i]*t[i]+y[i]));
        int time_left=time-(z[i]*t[i]+y[i])*timess;
        ans.push_back(timess*z[i]+max((int)0,min((time_left/t[i]),z[i])));
        sum+=timess*z[i]+max((int)0,min((time_left/t[i]),z[i]));
    }
    int reqq=sum-m;
    for(auto c:ans)
    {
        //        cout<<endl;
        //        cout<<c<<endl;
        //        cout<<reqq<<endl;
        //        cout<<endl;
        if(reqq)
        {
            if(c>=reqq)
            {
                cout<<c-reqq<<" ";
                reqq=0;
            }
            else{
                cout<<0<<" ";
                reqq=reqq-c;
            }
        }
        else{
            cout<<c<<" ";
        }
    }
    return 0;
}