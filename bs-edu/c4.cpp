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
int n,m,d;
vector<pair<int,int>>v[100001];
int vis[100001];
int par[100001];
int dist[100001];
bool good(int val)
{
    queue<int>q;
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dist[i]=0;
    }
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto c:v[node]){
            if(c.second<=val && !vis[c.first])
            {
                vis[c.first]=1;
                dist[c.first]=dist[node]+1;
                if(dist[c.first]<d)
                {
                    q.push(c.first);
                }
            }
        }
    }
    return vis[n]==1;
}
int32_t main() {
    nitin;
    cin>>n>>m>>d;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    int s=-1;
    int e=1000000001;
    while(s+1<e)
    {
        int m=(s+e)/2;
        if(good(m)) e=m;
        else s=m;
    }
    if(e==1000000001)
    {
        cout<<-1<<endl;
        return 0;
    }
    vector<int>ans;
    queue<int>q;
    q.push(1);
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
        par[i]=0;
    }
    vis[1]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto c:v[node])
        {
            if(!vis[c.first] && c.second<=e)
            {
                q.push(c.first);
                vis[c.first]=1;
                par[c.first]=node;
            }
        }
    }
    int node=n;
    while(node!=0)
    {
        ans.push_back(node);
        node=par[node];
    }
    cout<<ans.size()-1<<endl;
    reverse(ans.begin(),ans.end());
    for(auto c:ans)
        cout<<c<<" ";
    cout<<endl;
    return 0;
}