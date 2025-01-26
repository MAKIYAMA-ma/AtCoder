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

    // n, x <= 5000
    // ai <= 2*10^5
    // ビタミンの総和 <= 10^9 ということ
    // 各ビタミンの組み合わせで最小カロリーのDPとかは無理
    //
    // 全ビタミンをa以上にするための最小カロリーは計算できる？
    Def(n);
    Def(x);
    vl2 a(3, vl()), c(3, vl());
    rep(i, n) {
        Def(v);
        Def(ta);
        Def(tc);
        a[v-1].push_back(ta);
        c[v-1].push_back(tc);
    }

    vl2 dp(3, vl(x+1, 0)), pdp(3, vl(x+1, 0));
    rep(i, 3) {
        rep(j, a[i].size()) {
            /* swap(dp[i], pdp[i]); */
            rep(k, dp[i].size()) pdp[i][k] = dp[i][k];
            rep(k, dp[i].size()) {
                if(k+c[i][j] <= x) {
                    dp[i][k+c[i][j]] = max({pdp[i][k]+a[i][j], dp[i][k+c[i][j]]});
                }
            }
        }
    }
    /* rep(i, dp[0].size()) cout << dp[0][i] << " "; */
    /* cout << endl; */
    /* rep(i, dp[1].size()) cout << dp[1][i] << " "; */
    /* cout << endl; */
    /* rep(i, dp[2].size()) cout << dp[2][i] << " "; */
    /* cout << endl; */

    ll l{0}, r{MAXLL};
    while((r-l) > 1) {
        ll m = (l+r)/2;
        ll cal{0};
        rep(i, 3) {
            cal += (lower_bound(all(dp[i]), m) - dp[i].begin());
        }
        /* cout << "DB:" << m << " " << lp1+lp2+lp3 << endl; */

        if(cal <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << endl;
}
