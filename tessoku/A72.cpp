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

    Def(h);
    Def(w);
    Def(k);
    vs c(h);
    rep(i, h) cin >> c[i];

#if 1
    ll ans{0};
    rep(i, (1 << h)) {
        auto phc = __builtin_popcount(i);
        if(phc > k) continue;

        vs cc(h);
        rep(j, h) {
            cc[j] = c[j];
            if(i & (1<<j)) {
                rep(l, w) cc[j][l] = '#';
            }
        }

        ll tmp = h*w;
        vl ww(w, 0);
        rep(j, h) {
            rep(l, w) {
                if(cc[j][l] == '.') {
                    ww[l]++;
                    tmp--;
                }
            }
        }
        sort(rall(ww));
        rep(j, k-phc) {
            tmp += ww[j];
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
#else
    rep(i, k) {
        vl hw(h, 0);
        vl ww(w, 0);
        rep(j, h) {
            rep(l, w) {
                if(c[j][l] == '.') {
                    hw[j]++;
                    ww[l]++;
                }
            }
        }
        auto mxh = max_element(all(hw));
        auto mxw = max_element(all(ww));
        if(*mxh > *mxw) {
            auto th = mxh - hw.begin();
            rep(j, w) {
                c[th][j] = '#';
            }
        } else {
            auto tw = mxw - ww.begin();
            rep(j, h) {
                c[j][tw] = '#';
            }
        }
    }
    ll ans{0};
    rep(i, h) {
        rep(j, w) {
            if(c[i][j] == '#') ans++;
        }
    }
    cout << ans << endl;
#endif
}
