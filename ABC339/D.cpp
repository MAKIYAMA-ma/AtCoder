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

void dijkstra(vpl2 &graph, ll start, vl &cost) {
    priority_queue<pl, vpl, greater<pl>> q;   // {cost, index}
    cost.at(start) = 0;
    q.push(make_pair(0, start));

    while(!q.empty()) {
        auto from = q.top().second;
        auto cst = q.top().first;
        q.pop();

        if(cost.at(from) < cst) {
            // 取得した情報が古い（最短でない）
            continue;
        }
        rep(i, graph.at(from).size()) {
            int to = graph.at(from).at(i).first;
            ll nc = graph.at(from).at(i).second + cst;

            if(nc < cost.at(to)) {
                cost.at(to) = nc;
                q.push(make_pair(nc, to));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vs s(n);
    rep(i, n) cin >> s[i];

    // とりあえず、上下左右方向の差分の分が必要
    //
    // そのうえで、ひっかける為の最短距離
    // ひっかけることができる間は距離が1縮まる
    // ひっかけられないと1も縮まない
    // 引っ掛からない移動が何回必要かが重要
    //
    // N <= 60
    vpl2 mp (n*n*n*n, vpl());
    vl dx = {1, -1, 0, 0};
    vl dy = {0, 0, 1, -1};
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                rep(l, n) {
                    if((i*n+j) >= (k*n+l)) continue;
                    rep(m, 4) {
                        auto ni = i + dx[m];
                        auto nj = j + dy[m];
                        auto nk = k + dx[m];
                        auto nl = l + dy[m];
                        if(ni < 0 || ni >= n || nj < 0 || nj >= n || s[ni][nj] == '#') {
                            ni = i;
                            nj = j;
                        }
                        if(nk < 0 || nk >= n || nl < 0 || nl >= n || s[nk][nl] == '#') {
                            nk = k;
                            nl = l;
                        }
                        if(i != ni || j != nj || k != nk || l != nl) {
                            mp[i + j*n + k*n*n + l*n*n*n].push_back(make_pair(ni + nj*n + nk*n*n + nl*n*n*n, 1));
                        }
                    }
                }
            }
        }
    }

    vl ps;
    rep(i, n) {
        rep(j, n) {
            if(s[i][j] == 'P') {
                ps.push_back(i);
                ps.push_back(j);
            }
        }
    }
    ll st{0}, base{1};
    rep(i, ps.size()) {
        st += base*ps[i];
        base *= n;
    }

    vl cost(n*n*n*n, MAXLL);
    dijkstra(mp, st, cost);
    ll ans{MAXLL};
    rep(i, n) {
        rep(j, n) {
            ans = min(ans, cost[i + j*n + i*n*n + j*n*n*n]);
        }
    }
    if(ans >= MAXLL) {
        ans = -1;
    }
    cout << ans << endl;
}
