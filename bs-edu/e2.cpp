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
int n,m;
vector<pair<int,double>>v[100001];
bool good(double val)
{
    double dist[n+1];
    for(int i=0;i<n;i++)
    {
        dist[i+1]=INT_MAX;
    }
    dist[1]=0;
    for(int i=1;i<=n;i++)
    {
        for(auto c:v[i])
        {
            if(dist[i]!=INT_MAX &&  dist[c.first]>dist[i]+c.second-val)
            {
                dist[c.first]=dist[i]+c.second-val;
            }
        }
    }
    return dist[n] <= 0;
}
int32_t main() {
    nitin;
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].emplace_back(b,c);
    }
    double s=-1;
    double e=101;
    for(int i=0;i<=100;i++)
    {
        double m=(s+e)/2;
        if(good(m))
            e=m;
        else
            s=m;
    }
    int par[n+1];
    double dist[n+1];
    for(int i=1;i<=n;i++)
        dist[i]=INT_MAX;
    dist[1]=0;
    par[1]=0;
    for(int i=1;i<=n;i++)
    {
        for(auto c:v[i])
        {
            if(dist[c.first]>dist[i]+c.second-e)
            {
                dist[c.first]=dist[i]+c.second-e;
                par[c.first]=i;
            }
        }
    }
    vector<int>ans;
    while(n!=0)
    {
        ans.push_back(n);
        n=par[n];
    }
    cout<<ans.size()-1<<endl;
    reverse(ans.begin(),ans.end());
    for(auto c:ans)
        cout<<c<<" ";
    cout<<endl;
    return 0;
}