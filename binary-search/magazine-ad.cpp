//https://codeforces.com/contest/803/problem/D
#include <bits/stdc++.h>

typedef long double ld;
#define int long long

#define gcd            __gcd
#define endl           "\n"
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define f              first
#define s              second
#define lb             lower_bound
#define ub             upper_bound
#define ins            insert
#define sz(x)          (int)(x).size()
#define mk             make_pair
#define deci(x, y)     fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define PI             3.141592653589793238
#define mem0(x)        memset(x,0,sizeof x)
#define mem1(x)        memset(x,-1,sizeof x)
using namespace std;
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.f << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NITIN
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

//000000000001111111111111
vector<int>v;
int k;
bool func(int w) {
    int req_no_of_lines = 1;
    int temp = 0;
    for (auto &c:v) {
        if (temp + c > w) {
            req_no_of_lines++;
            temp = c;
        } else {
            temp += c;
        }
    }
    return req_no_of_lines <= k;
}
void solve() {
    cin>>k;
    cin.ignore();
    string s;
    getline(cin,s);
    int temp=0;
    for(auto &c:s){
        if(c=='-' || c==' '){
            v.push_back(temp+1);
            temp=0;
        }else{
            temp++;
        }
    }
    v.push_back(temp);
    int l= maxe(all(v))-1; // l will lie in the portion of 0
    int r=s.length(); // r will lie in the portion of 1
    while(l+1<r){
        int mid=(l+r)/2;
        if(func(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<r<<endl;
}

int32_t main() {
    nitin;

    solve();
}