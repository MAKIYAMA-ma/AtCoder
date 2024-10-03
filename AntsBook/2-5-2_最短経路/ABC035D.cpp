#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

/**
 * @brief 
 *
 * @param graph i番目の要素は、{jまでコストcの経路がある}という経路の配列
 * @param start 最短経路検索の始点
 * @param cost  最短経路の結果を格納する配列
 */
void dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<ll> &cost) {
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
    int n, m;
    ll t;
    cin >> n >> m >> t;

    vector<vector<pair<int, int>>> map(n, vector<pair<int, int>>());
    vector<vector<pair<int, int>>> rmap(n, vector<pair<int, int>>());
    vector<ll> a(n, 0);
    rep(i, n) {
        cin >> a.at(i);
    }
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        map.at(a).push_back(make_pair(b, c));
        rmap.at(b).push_back(make_pair(a, c));
    }

    // 往路の計算
    vector<ll> cg(n, pow(10, 10) + 1);
    dijkstra(map, 0, cg);

    // 復路の計算
    vector<ll> cr(n, pow(10, 10) + 1);
    dijkstra(rmap, 0, cr);

    ll trs = 0;
    rep(i, n) {
        auto stay = t - cg.at(i) - cr.at(i);
        trs = max(trs, (stay * a.at(i)));
    }
    cout << trs << endl;
}
