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


void dijkstra(vector<vector<pair<pl, int>>> &graph, int start, vl &cost) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;   // {cost, index}
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
            int to = graph.at(from).at(i).first.first;
            ll nc = graph.at(from).at(i).first.second + cst;

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
    Def(m);
    vector<vector<pair<pl, int>>> map(n, vector<pair<pl, int>>());
    rep(i, m) {
        Def(a);
        Def(b);
        Def(c);
        Def(d);
        a--; b--;
        map[a].push_back(make_pair(make_pair(b, c), d));
        map[b].push_back(make_pair(make_pair(a, c), d));
    }

    // 全て連結
    // 0 -> n-1 への最短経路を知りたい
    // その長さの経路で、Dの総和が最大の経路をとりたい
    //
    // Dのあるほうが経路が短くなる、とかやるとそもそも最短ではない経路を選ぶ恐れがある。
    // (1) 最短経路をダイクストラで算出する
    // (2) 逆にたどり、ありうる経路ごとに探索とかでいける？

    vl cost(n, MAXLL);
    dijkstra(map, 0, cost);

    ll ans{0};
    stack<pl> st;
    st.push(make_pair(n-1, 0));
    while(!st.empty()) {
        auto tp = st.top();
        st.pop();
        auto cur = tp.first;
        if(cur == 0) {
            ans = max(ans, tp.second);
            continue;
        }
        for(auto rd : map[cur]) {
            auto nxt = rd.first.first;
            auto dst = rd.first.second;
            auto tree = rd.second;
            if(cost[nxt] == (cost[cur] - dst)) {
                st.push(make_pair(nxt, tp.second + tree));
            }
        }
    }
    cout << cost[n-1] << " " << ans << endl;
}
