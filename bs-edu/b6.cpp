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
vector<double>c;
bool good(long double mid, int n,long double d)
{
    long double last=c[0];
    for(int i=1;i<(int)n;i++)
    {
        long double to_put=last+mid;
        if(to_put<c[i])
        {
            last=c[i];
        }
        else if(to_put>=c[i] && to_put<=c[i]+d){
            last=to_put;
        }
        else{
            return false;
        }
    }
    return true;
}
vector<int>v;
int n;
string t;

string s;
bool isSubString(string &par,string &child)
{
    if(par.length()<child.length())
        return false;
    int i=par.length()-1;
    int j=child.length()-1;
    while(i>=0 && j>=0)
    {
        if(par[i]==child[j])
        {
            i--;
            j--;
        }
        else{
            i--;
        }
    }
    return j == -1;
}
bool good(int m)
{
    unordered_map<int,int>mm;
    for(int i=0;i<m;i++)
        mm[v[i]]=true;
    string sam;
    for(int i=0;i<n;i++)
    {
        if(!mm.count(i))
            sam+=s[i];
    }
    return isSubString(sam,t);
}
int32_t main() {
    nitin;
    cin>>s>>t;
    n=s.length();
    counter(n)
    {
        int a;
        cin>>a;
        --a;
        v.pb(a);
    }
    int l=0;
    int r=n;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        if(good(mid))
            l=mid;
        else
            r=mid;
    }
    cout<<l<<endl;
    return 0;
}