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

void dijkstra(vpi2 &graph, int start, vi &cost) {
    priority_queue<pi, vpi, greater<pi>> q;   // {cost, index}
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
    vs c(n);
    rep(i, n) cin >> c[i];

    int st = n*n;
    vpi2 g(n*n+1, vpi());
    vpi2 cr(26, vpi());
    rep(i, n) {
        g[st].push_back({i*n+i, 0});
        rep(j, n) {
            if(c[i][j] != '-') {
                g[st].push_back({i*n+j, 1});
                cr[c[i][j] - 'a'].push_back({i, j});
            }
        }
    }
    /* cout << "--------" << endl; */
    /* rep(i, cr.size()) { */
    /*     rep(j, cr[i].size()) { */
    /*         cout << cr[i][j].first << "," << cr[i][j].second << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "--------" << endl; */
    rep(i, cr.size()) {
        rep(j, cr[i].size()) {
            srep(k, j+1, cr[i].size()) {
                auto [s1, g1] = cr[i][j];
                auto [s2, g2] = cr[i][k];
                g[g1*n+s2].push_back({s1*n+g2, 2});
                g[g2*n+s1].push_back({s2*n+g1, 2});
            }
        }
    }

    /* cout << "---------" << endl; */
    /* rep(i, g.size()) { */
    /*     cout << i/n << "," << i%n << " : "; */
    /*     rep(j, g[i].size()) { */
    /*         cout << "(" << g[i][j].first/n << "," << g[i][j].first%n << "):" << g[i][j].second << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "---------" << endl; */

    vi cost(n*n+1, MAXI);
    dijkstra(g, st, cost);
    rep(i, n) {
        rep(j, n) {
            if(cost[i*n+j] == MAXI) {
                cout << -1;
            } else {
                cout << cost[i*n+j];
            }
            cout << " ";
        }
        cout << endl;
    }
}
