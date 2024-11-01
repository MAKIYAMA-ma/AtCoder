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

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
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

    // 1 ≤ N ≤ 100
    // 1 ≤ M ≤ 100
    Def(n);
    Def(m);

    vs map(n);
    rep(i, n) cin >> map[i];

    // n*m: start
    // n*m+1: goal
    mf_graph<ll> grp(n * m + 2);
    int sp = n*m;
    int gp = n*m+1;
    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    rep(i, n) {
        rep(j, m) {
            if(map[i][j] == '#') continue;
            // start -> 奇数マス -> 隣接偶数マス -> ゴールとなるように枝を張る
            if((i+j)%2) {
                grp.add_edge(sp, i*m + j, 1);
                rep(k, 4) {
                    auto nx = i+dx[k];
                    auto ny = j+dy[k];
                    if((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m) && map[nx][ny] != '#') {
                        grp.add_edge(i*m + j, nx*m + ny, 1);
                    }
                }
            } else {
                grp.add_edge(i*m + j, gp, 1);
            }
        }
    }
    // 最大流の計算
    ll ans = grp.flow(sp, gp);
    auto pairs = grp.edges();
    for(auto p : pairs) {
        // 流量がある枝について、マップの表記を変更
        if(p.from == sp || p.to == sp || p.from == gp || p.to == gp) continue;
        if(p.flow == 0) continue;
        int p1x = p.from / m;
        int p1y = p.from % m;
        int p2x = p.to / m;
        int p2y = p.to % m;

        if(p1x == p2x) {
            map[p1x][min(p1y, p2y)] = '>';
            map[p1x][max(p1y, p2y)] = '<';
        } else {
            map[min(p1x, p2x)][p1y] = 'v';
            map[max(p1x, p2x)][p1y] = '^';
        }
    }

    cout << ans << endl;
    rep(i, n) {
        rep(j, m) {
            cout << map[i][j];
        }
        cout<< endl;
    }
}
