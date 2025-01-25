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
    vl a1, c1, a2, c2, a3, c3;
    rep(i, n) {
        Def(v);
        Def(a);
        Def(c);
        switch(v) {
            case 1:
                a1.push_back(a);
                c1.push_back(c);
                break;
            case 2:
                a2.push_back(a);
                c2.push_back(c);
                break;
            case 3:
                a3.push_back(a);
                c3.push_back(c);
                break;
        }
    }

    vl dp1(x+1), dp2(x+1), dp3(x+1);
    vl pdp1(x+1), pdp2(x+1), pdp3(x+1);
    rep(i, a1.size()) {
        rep(j, dp1.size()) {
            pdp1[j] = dp1[j];
        }
        rep(j, dp1.size()) {
            if(j+c1[i] <= x) {
                dp1[j+c1[i]] = max(pdp1[j]+a1[i], pdp1[j+c1[i]]);
            }
        }
    }
    rep(i, a2.size()) {
        rep(j, dp2.size()) {
            pdp2[j] = dp2[j];
        }
        rep(j, dp2.size()) {
            if(j+c2[i] <= x) {
                dp2[j+c2[i]] = max(pdp2[j]+a2[i], pdp2[j+c2[i]]);
            }
        }
    }
    rep(i, a3.size()) {
        rep(j, dp3.size()) {
            pdp3[j] = dp3[j];
        }
        rep(j, dp3.size()) {
            if(j+c3[i] <= x) {
                dp3[j+c3[i]] = max(pdp3[j]+a3[i], pdp3[j+c3[i]]);
            }
        }
    }
    /* rep(i, dp1.size()) cout << dp1[i] << " "; */
    /* cout << endl; */
    /* rep(i, dp2.size()) cout << dp2[i] << " "; */
    /* cout << endl; */
    /* rep(i, dp3.size()) cout << dp3[i] << " "; */
    /* cout << endl; */

    ll l{0}, r{MAXLL};
    while((r-l) > 1) {
        ll m = (l+r)/2;
        auto lp1 = lower_bound(all(dp1), m) - dp1.begin();
        auto lp2 = lower_bound(all(dp2), m) - dp2.begin();
        auto lp3 = lower_bound(all(dp3), m) - dp3.begin();

        /* cout << "DB:" << m << " " << lp1+lp2+lp3 << endl; */

        if((lp1+lp2+lp3) <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    auto v1 = *lower_bound(all(dp1), l);
    auto v2 = *lower_bound(all(dp2), l);
    auto v3 = *lower_bound(all(dp3), l);
    cout << min({v1, v2, v3}) << endl;
}
