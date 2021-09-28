#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
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
int a,b,c;
int ra=0,rb=0,rc=0;
int pa,pb,pc;
int r;
bool good(int m)
{
    int to_comp_a=m*ra;
    int to_com_b=m*rb;
    int to_com_c=m*rc;
    to_comp_a-=a;
    to_com_b-=b;
    to_com_c-=c;
    int ans=0;
    ans+=max((int)0,to_comp_a*pa);
    ans+=max((int)0,to_com_b*pb);
    ans+=max((int)0,to_com_c*pc);
    return ans<=r;

}
int32_t main() {
    nitin;
    string s;
    cin>>s;
    for(auto c:s)
    {
        if(c=='B')
        {
            ra++;
        }
        else if(c=='S')
            rb++;
        else
            rc++;
    }
    cin>>a>>b>>c>>pa>>pb>>pc>>r;
    int l=0;
    int e=1e15;
    while(e>l+1)
    {
        int mid=(l+e)/2;
        if(good(mid)) l=mid;
        else e=mid;
    }
    cout<<l<<endl;
    return 0;
}