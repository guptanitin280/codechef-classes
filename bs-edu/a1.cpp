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
bool bs(int a)
{
    int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(v[mid]==a)
            return true;
        else if(v[mid]<a)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return false;
}
int32_t main() {
    nitin;
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    while(q--)
    {
        int a;
        cin>>a;
        if(bs(a))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}