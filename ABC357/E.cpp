#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;

using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<pi>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vp2 = vector<vp>;

#if 0
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

void dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<int> &cost) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;   // {cost, index}
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
            int nc = graph.at(from).at(i).second + cst;

            if(nc < cost.at(to)) {
                cost.at(to) = nc;
                q.push(make_pair(nc, to));
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    // そもそもn x nのマトリクスが持てない。
    // (2*10^5)^2 * 4Byte = 149GByte
    // -> どこからどこまで到達可能かを管理しておくのは無理
    //
    // Functional Graphというらしい。
    // 各連結成分ごとに、一つの閉路とその要素を根とする有向木で構成される性質があるそうな。
    //
    // ある点からDSPする
    // いずれ閉路が見つかる
    // -> 根と閉路の個数を記録する
#if 1
    // これはTLE
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    rep(i, n) {
        int a;
        cin >> a;
        a--;
        g[i].push_back({a, 1});
    }

    vector<int> cost(n, n+1);
    ll ans = 0;
    rep(i, n) {
        vector<int> cost(n, n+1);
        dijkstra(g, i, cost);
        ans += count_if(all(cost), [&n](ll x) {
            return x <= n;
        });
    }
    cout << ans << endl;
#else
    vector<ll> a(n, 0);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
#endif
}
