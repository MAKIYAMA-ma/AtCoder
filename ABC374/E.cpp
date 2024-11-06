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

    Def(n);
    Def(x);
    vl a(n), b(n), p(n), q(n);
    rep(i, n) cin >> a[i] >> p[i] >> b[i] >> q[i];

#if 1
    // 答えを二分探索しようという発想は正しかったらしいが
    // 最小コストフローは無関係だったみたい。
    ll l{0};
    ll r = 1000000001;
    while ((r-l) > 1) {
        ll mid = (l+r)/2;
        ll cost{0};
        rep(i, n) {
            ll minc = MAXLL;
            rep(j, b[i]) {
                ll rest = mid - (a[i]*j);
                ll tmp = p[i]*j;
                if(rest > 0) {
                    tmp += (rest/b[i] + ((rest % b[i]) ? 1 : 0)) * q[i];
                }
                minc = min(minc, tmp);
            }
            rep(j, a[i]) {
                ll rest = mid - (b[i]*j);
                ll tmp = q[i]*j;
                if(rest > 0) {
                    tmp += (rest/a[i] + ((rest % a[i]) ? 1 : 0)) * p[i];
                }
                minc = min(minc, tmp);
            }
            cost += minc;
            if(cost > x) break;
        }
        /* cout << "DB:" << mid << " " << cost << endl; */

        if(cost > x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << endl;
#elif 1
    // なるべく均等に各工程の生産能力を向上していく。
    // マシンが一種類なら、ボトルネックを強化していく貪欲で良い気がするが、
    // 2種類あるので価格と効率のどちらを重視するのかが問題となる。
    //
    // 最小コストフローとかで解くのかな。
    int l{1};
    int r = 10000000;
#if 1
    srep(mid, 1, 5) {
        mcf_graph<ll, ll> graph(n+1);
        rep(i, n) {
            rep(j, x/p[i]) {
                graph.add_edge(i, i+1, a[i], p[i]);
            }
            rep(j, x/q[i]) {
                graph.add_edge(i, i+1, b[i], q[i]/b[i]);
            }
        }
        auto res = graph.flow(0, n, mid);
        cout << "DB:" << mid << " " << res.first << " " << res.second << endl;
        auto edges = graph.edges();
        for(auto e : edges) {
            /* if(e.flow) { */
                cout << "  " << e.from << " -> " << e.to << " " << e.flow << ":" << e.cost << endl;
            /* } */
        }
    }
#else
    while ((r-l) > 1) {
        int mid = (l+r)/2;

        cout << l << "," << r << endl;

        mcf_graph<ll, ll> graph(n+1);
        rep(i, n) {
            rep(j, x/p[i]) {
                graph.add_edge(i, i+1, a[i], p[i]);
            }
            rep(j, x/q[i]) {
                graph.add_edge(i, i+1, b[i], q[i]);
            }
        }
        auto res = graph.flow(0, n, mid);
        cout << "DB:" << mid << " " << res.first << " " << res.second << endl;
        if(x > res.second) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
#endif
#endif
}
