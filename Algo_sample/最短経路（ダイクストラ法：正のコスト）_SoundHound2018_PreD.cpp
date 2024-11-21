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
    int n, m, s, t;
    ll money = pow(10, 15);

    cin >> n >> m >> s >> t;
    s--;
    t--;

    vpl2 ymap(n, vpl());
    vpl2 smap(n, vpl());
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        ymap.at(u).push_back(make_pair(v, a));
        ymap.at(v).push_back(make_pair(u, a));
        smap.at(u).push_back(make_pair(v, b));
        smap.at(v).push_back(make_pair(u, b));
    }

    /* ダイクストラ法でsからの各都市のyenコストを求める */
    vl yc(n, MAXLL);
    dijkstra(ymap, s, yc);

    /* ダイクストラ法でtからの各都市のスヌークコストを求める */
    vl sc(n, MAXLL);
    dijkstra(smap, t, sc);

    // 後から順に累積min
    vl accumin(n, 0);
    accumin.at(n-1) = yc.at(n-1) + sc.at(n-1);
    for(int i = n-2; i >= 0; i--) {
        accumin.at(i) = min(accumin.at(i+1), yc.at(i) + sc.at(i));
    }
    // 回答
    rep(i, n) {
        cout << money - accumin.at(i) << endl;
    }
}
