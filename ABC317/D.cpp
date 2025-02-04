#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;
using vs = vector<string>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(ll i = (ll)(s); i < (ll)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;
#define Def(n) ll n; cin >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define DefPA(a, n) vl a(n); rep(i, n) cin >> a[i].first >> a[i].second;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
const int MAXI = 1e9;
const int MINI = -1e9;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vl x(n), y(n), z(n);
    rep(i, n) cin >> x[i] >> y[i] >> z[i];

    // 各選挙区でk人寝返りが必要でl議席とれる、は簡単に分かる。
    // それをもとに、i議席とる最小人数を調べればよい
    //
    // n <= 100
    // x,y <= 10^9
    // z <= 10^5 -> トータル10^7議席
    ll nd{0};
    rep(i, n) {
        if(x[i] < y[i]) {
            nd += z[i];
        } else {
            nd -= z[i];
        }
    }
    nd = max((nd+1)/2, 0LL);

    vl dp(reduce(all(z))+1, MAXLL);
    dp[0] = 0;
    rep(i, n) {
        if(x[i] < y[i]) {
            rrep(j, dp.size()-z[i]) {
                if(dp[j] < MAXLL) {
                    dp[j+z[i]] = min(dp[j+z[i]], dp[j] + (y[i]-x[i]+1)/2);
                }
            }
        }
    }
    /* rep(i, dp.size()) { */
    /*     if(dp[i] < MAXLL) cout << dp[i] << " "; */
    /*     else cout << "MX "; */
    /* } */
    /* cout << endl; */
    cout << *min_element(dp.begin()+nd, dp.end()) << endl;
}
