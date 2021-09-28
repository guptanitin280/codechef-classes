#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
//#define endl           "\n"
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
int k;
vector<int>v;
bool good(int m)
{
    int cnt=1;
    int last=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]-last>=m)
        {
            cnt++;
            last=v[i];
        }
    }
    return cnt>=k;
}
int32_t main() {
    nitin;
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int s=0;
    int e=1e18;
    while(s+1<e)
    {
        int mid=(s+e)/2;
        if(good(mid))
            s=mid;
        else
            e=mid;
    }
    cout<<s<<endl;
    return 0;
}