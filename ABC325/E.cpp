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
    Def(a);
    Def(b);
    Def(c);

    vl2 d(n, vl(n, 0));
    rep(i, n) rep(j, n) cin >> d[i][j];

    // n <= 1000
    // O(n2)で電車のみでnからダイクストラ
    // O(n2)で車のみで1からダイクストラ
    // 接続点1000個でmin計算O(n)
    vpl2 car(n, vpl());
    vpl2 train(n, vpl());
    rep(i, n) {
        rep(j, n) {
            car[i].push_back(make_pair(j, d[i][j]*a));
            // 電車はゴールからたどるので逆方向に張る
            // とはいえ今回はDij = Djiなので変わらないけど。
            train[j].push_back(make_pair(i, d[j][i]*b+c));
        }
    }
    vl tc(n, MAXLL), tt(n, MAXLL);
    dijkstra(car, 0, tc);
    dijkstra(train, n-1, tt);

    ll ans{MAXLL};
    rep(i, n) {
        ans = min(ans, tc[i]+tt[i]);
    }
    cout << ans << endl;
}
