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

using sl = set<ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;
using vs = vector<string>;
using vsl = vector<sl>;

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
#define Def2(m, n) ll m, n; cin >> m >> n;
#define Def3(l, m, n) ll l, m, n; cin >> l >> m >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define Def3A(a, b, c, n) vl a(n); vl b(n); vl c(n); rep(i, n) cin >> a[i] >> b[i] >> c[i];
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

    Def2(n, m);
    Def2A(a, b, m);

    // n <= 8
    // 非常に制約が小さい。全探索？？
    // 元のグラフも単純無向グラフ
    // (1) 点の並び順を全探索1始まり固定とすれば、7!=5040
    // (2) 現状の辺との違いを確認
    vl od(n-1);
    rep(i, n-1) od[i] = i+2;
    ll ans{MAXLL};
    do {
        /* cout << "--------" << endl; */
        /* cout << 1 << ","; */
        /* rep(i, n-1) { */
        /*     cout << od[i] << ","; */
        /* } */
        /* cout << endl; */
        ll c{0};

        bool ok2{false};
        rep(j, m) {
            if((1 == a[j] && od[0] == b[j]) || (1 == b[j] && od[0] == a[j])) {
                // 一致
                ok2 = true;
                break;
            }
        }
        if(!ok2) c++;
        rep(i, n-1) {
            bool ok{false};
            if(i != n-2) {
                rep(j, m) {
                    if((od[i] == a[j] && od[i+1] == b[j]) || (od[i] == b[j] && od[i+1] == a[j])) {
                        // 一致
                        ok = true;
                        break;
                    }
                }
            } else {
                rep(j, m) {
                    if((od[i] == a[j] && 1 == b[j]) || (od[i] == b[j] && 1 == a[j])) {
                        // 一致
                        ok = true;
                        break;
                    }
                }
            }
            if(!ok) {
                /* cout << "add:" << od[i] << " - " << ((i != n-2) ? od[i+1] : 1) << endl;; */
                c++;
            }
        }
        rep(j, m) {
            bool ok{false};
            if((1 == a[j] && od[0] == b[j]) || (1 == b[j] && od[0] == a[j])) {
                // 一致
                ok = true;
            } else {
                rep(i, n-1) {
                    if(i != n-2) {
                        if((od[i] == a[j] && od[i+1] == b[j]) || (od[i] == b[j] && od[i+1] == a[j])) {
                            // 一致
                            ok = true;
                            break;
                        }
                    } else {
                        if((od[i] == a[j] && 1 == b[j]) || (od[i] == b[j] && 1 == a[j])) {
                            // 一致
                            ok = true;
                            break;
                        }
                    }
                }
            }
            if(!ok) {
                /* cout << "del:" << a[j] << " - " << b[j] << endl;; */
                c++;
            }
        }
        ans = min(ans, c);
    } while (next_permutation(all(od)));
    cout << ans << endl;
}
