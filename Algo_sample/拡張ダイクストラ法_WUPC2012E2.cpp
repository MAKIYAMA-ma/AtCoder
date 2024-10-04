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

void dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<vector<ll>> &cost) {
    // priority_queueのカスタムコンパレータ
    auto cmp = [](const pair<ll, pair<int, int>> &a, const pair<ll, pair<int, int>> &b) {
        return a.first > b.first;  // firstが小さい順に取り出す
    };
    int base = cost.at(0).size();

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, decltype(cmp)> q(cmp);
    cost.at(start).at(0) = 0;
    pair<int, int> st = {start, 0};
    q.push(make_pair(0, st));

    while(!q.empty()) {
        auto from = q.top().second;
        auto cst = q.top().first;
        q.pop();

        if(from.first == cost.size()-1) {
            // 会場についてからの移動は不可
            continue;
        }
        if(cost.at(from.first).at(from.second) < cst) {
            continue;
        }
        rep(i, graph.at(from.first).size()) {
            int to = graph.at(from.first).at(i).first;
            ll nc = graph.at(from.first).at(i).second + cst;
            int m = nc % base;

            if(nc < cost.at(to).at(m)) {
                cost.at(to).at(m) = nc;
                q.push(make_pair(nc, make_pair(to, m)));
            }
        }
    }
}

int main() {
    int n, m;
    ll inf = 1e18;
    cin >> n >> m;

    vector<vector<pair<int, int>>> map(n, vector<pair<int, int>>());
    rep(i, m) {
        int f, t, c;
        cin >> f >> t >> c;
        map.at(f).push_back(make_pair(t, c));
        map.at(t).push_back(make_pair(f, c));
    }

    /* mod4を状態に加えたダイクストラ */
    vector<vector<ll>> cost4(n, vector<ll>(4, inf));
    dijkstra(map, 0, cost4);
    /* mod7を状態に加えたダイクストラ */
    vector<vector<ll>> cost7(n, vector<ll>(7, inf));
    dijkstra(map, 0, cost7);

    cout << min(cost4.at(n-1).at(0), cost7.at(n-1).at(0)) << endl;
}
