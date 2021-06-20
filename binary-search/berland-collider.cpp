//https://codeforces.com/contest/24/problem/E
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

vector<pair<double,double>>pos,neg;
vector<int>idx;
int n;
// return true if any collision happened in time  tme
bool f(double tme) {
    vector<double> f_neg, f_pos;
    for (int i = 0; i < pos.size(); i++) {
        f_pos.push_back(pos[i].first + pos[i].second * tme);
    }
    for (int i = 0; i < neg.size(); i++) {
        f_neg.push_back(neg[i].first + neg[i].second * tme);
    }
    for (int i = sz(neg) - 2; i >= 0; i--) {
        f_neg[i] = min(f_neg[i], f_neg[i + 1]);
    }
    for (int i = 0; i < f_pos.size(); i++) {
        if (idx[i] < neg.size() && f_neg[idx[i]] <= f_pos[i]) {
            return true;
        }
    }
    return false;
}
void solve() {
    cin>>n;
    for(int i =0;i<n;i++) {
        int x, v;
        cin >> x >> v;
        if (v > 0) {
            pos.push_back({x, v});
        } else {
            neg.push_back({x, v});
        }
    }
    sort(all(pos));
    sort(all(neg));
    for(int i=0;i<pos.size();i++) {
        int l = -1, r = neg.size();
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (neg[mid].first <= pos[i].first) {
                l = mid;
            } else {
                r = mid;
            }
        }
        idx.push_back(r);
    }
    double l=0; // return false;
    double r=1e10; // return true;
    if(!f(r)){
        cout<<-1<<endl;
        return;
    }
    for(int i =0;i<100;i++){
        double mid=(l+r)/2;
        if(f(mid)){
            r=mid;
        }else{
            l=mid;
        }
    }
    cout<<deci(r,10)<<endl;
}

int32_t main() {
    nitin;

    solve();
}