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
    int seg=1;
    int past=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]+past>m)
        {
            seg++;
            past=v[i];
        }
        else{
            past+=v[i];
        }
    }
    return seg<=k;
}
int32_t main() {
    nitin;
    cin>>n;
    cin>>k;
    counter(n){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int s=maxe(v.begin(),v.end())-1;
    int e=1e18;
    while(s+1<e)
    {
        int m=(s+e)/2;
        if(good(m))
            e=m;
        else
            s=m;
    }
    cout<<e<<endl;
    return 0;
}