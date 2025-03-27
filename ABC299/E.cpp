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

    Def2(n, m);
    vpl2 edge(n, vpl());
    rep(i, m) {
        Def2(u, v);
        u--; v--;
        edge[u].push_back({v, 1});
        edge[v].push_back({u, 1});
    }
    Def(k);
    vl p(k), d(k);
    rep(i, k) {
        Def2(tp, td);
        tp--;
        p[i] = tp;
        d[i] = td;
    }

    // n <= 2000
    // 各p, dについて、pからdの距離にある点が一つ以上黒であり、d未満の点は全て0である必要がある
    // 各点間の距離が欲しいが、WarshallFloydはO(N^3)だからTLE
    // 各pごとにダイクストラならO(N^2 logN)か？ 2000ならいける
    set<ll> wht;    // 白必須の頂点
    vsl blk;        // どれか黒になる頂点グループ
    vl cost(n, MAXLL);
    rep(i, k) {
        fill(all(cost), MAXLL);
        dijkstra(edge, p[i], cost);
        set<ll> blkt;

        rep(j, cost.size()) {
            if(cost[j] < d[i]) {
                wht.insert(j);
            } else if(cost[j] == d[i]) {
                blkt.insert(j);
            }
        }
        blk.push_back(blkt);
    }

    // 一つ以上黒必須なので、黒でいい頂点は全部黒としておく
    vl ans(n, 1);
    for(auto c : wht) ans[c] = 0;
    if(reduce(all(ans)) == 0) {
        // 全白ならアウト
        Yes(0);
        return 0;
    }

    for(auto s : blk) {
        bool fnd{false};
        for(auto c : s) {
            if(ans[c]) {
                fnd = true;
                break;
            }
        }
        if(!fnd) {
            Yes(0);
            return 0;
        }
    }
    Yes(1);
    rep(i, n) cout << (ans[i]?'1':'0');
    cout << endl;
}
