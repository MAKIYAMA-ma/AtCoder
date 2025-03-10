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

    DefA(hwa, 2);
    vs a(hwa[0]);
    rep(i, hwa[0]) cin >> a[i];

    DefA(hwb, 2);
    vs b(hwb[0]);
    rep(i, hwb[0]) cin >> b[i];

    DefA(hwx, 2);
    vs x(hwx[0]);
    rep(i, hwx[0]) cin >> x[i];

    // x内でのa,bの置き場所は最大100^2通り。当然全部試すのが良い。
    ll maxah{0}, minah{MAXLL};
    ll maxaw{0}, minaw{MAXLL};
    ll maxbh{0}, minbh{MAXLL};
    ll maxbw{0}, minbw{MAXLL};
    rep(i, hwa[0]) {
        rep(j, hwa[1]) {
            if(a[i][j] == '#') {
                maxah = max(maxah, i);
                minah = min(minah, i);
                maxaw = max(maxaw, j);
                minaw = min(minaw, j);
            }
        }
    }
    rep(i, hwb[0]) {
        rep(j, hwb[1]) {
            if(b[i][j] == '#') {
                maxbh = max(maxbh, i);
                minbh = min(minbh, i);
                maxbw = max(maxbw, j);
                minbw = min(minbw, j);
            }
        }
    }
    /* cout << "DB1:" << minah << " " << maxah << " " << hwx[0]-(maxah-minah) << endl; */
    /* cout << "DB2:" << minaw << " " << maxaw << " " << hwx[1]-(maxaw-minaw) << endl; */
    /* cout << "DB3:" << minbh << " " << maxbh << " " << hwx[0]-(maxbh-minbh) << endl; */
    /* cout << "DB4:" << minbw << " " << maxbw << " " << hwx[1]-(maxbw-minbw) << endl; */
    rep(i, hwx[0]-(maxah-minah)) {
        rep(j, hwx[1]-(maxaw-minaw)) {
            rep(k, hwx[0]-(maxbh-minbh)) {
                rep(l, hwx[1]-(maxbw-minbw)) {
                    bool err{false};
                    vl2 tx(hwx[0], vl(hwx[1], 0));
                    srep(m, minah, maxah+1) {
                        srep(n, minaw, maxaw+1) {
                            if(a[m][n] == '#') {
                                if(i+m >= tx.size() || j+n >= tx[0].size()) {
                                    err = true;
                                    break;
                                }
                                tx[i+m][j+n] = 1;
                            }
                        }
                        if(err) break;
                    }
                    if(err) continue;
                    srep(m, minbh, maxbh+1) {
                        srep(n, minbw, maxbw+1) {
                            if(b[m][n] == '#') {
                                if(k+m >= tx.size() || l+n >= tx[0].size()) {
                                    err = true;
                                    break;
                                }
                                tx[k+m][l+n] = 1;
                            }
                        }
                        if(err) break;
                    }
                    if(err) continue;

                    /* cout << "-------" << endl; */
                    /* rep(m, tx.size()) { */
                    /*     rep(n, tx[0].size()) { */
                    /*         cout << ((tx[m][n])?'#':'.'); */
                    /*     } */
                    /*     cout << endl; */
                    /* } */

                    bool ans{true};
                    rep(m, tx.size()) {
                        rep(n, tx[0].size()) {
                            if((x[m][n] == '#' && tx[m][n]) || (x[m][n] == '.' && !tx[m][n])) {
                            } else {
                                ans = false;
                                break;
                            }
                        }
                        if(!ans) break;
                    }
                    if(ans) {
                        Yes(1);
                        return 0;
                    }
                }
            }
        }
    }
    Yes(0);
}
