//link:- https://www.hackerrank.com/challenges/contacts/problem
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


struct node {
    map<char, int> m;
    bool terminate = false;
    int cnt = 0;
};
node a[1000001];

struct Trie{
    int ptr=2;

    void insert(string s) {
        int curr = 1;
        for (auto &c:s) {
            if (a[curr].m.count(c)) {
                curr = a[curr].m[c];
            } else {
                a[curr].m[c] = ptr;
                ptr++;
                curr = a[curr].m[c];
            }
            a[curr].cnt++;
        }
        a[curr].terminate=true;
    }
    int find(string s) {
        int curr = 1;
        for (auto &c:s) {
            if (!a[curr].m.count(c)) {
                return 0;
            }
            curr = a[curr].m[c];
        }
        return a[curr].cnt;
    }
};




void solve() {
    int n;
    cin>>n;
    Trie T;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        if(a=="add"){
            T.insert(b);
        }else{
            cout<<T.find(b)<<endl;
        }
    }
}

int32_t main() {
    nitin;

    solve();
}
