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
vector<int>v;
int k;
bool good(int m)
{
    int cnt=0;
    int overhead=0;
    for(auto c:v)
    {
        if(c>=m)
            cnt++;
        else
        {
            overhead+=c;
            while(overhead>=m)
            {
                cnt++;
                overhead-=m;
            }
        }
    }
    return cnt>=k;
}
int32_t main() {
    nitin;
    int n;
    cin>>k>>n;
    counter(n){
        int a;
        cin>>a;
        v.pb(a);
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