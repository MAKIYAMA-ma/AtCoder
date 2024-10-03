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
    int n, k;
    cin >> n >> k;

    vector<vector<pair<int, int>>> map(n, vector<pair<int, int>>());

    rep(i, k) {
        int o;
        cin >> o;
        ll inf = 100000001; // 無限遠

        if(o) {
            // 船の運航開始
            int c, d, e;
            cin >> c >> d >> e;
            c--;
            d--;

            map.at(c).push_back(make_pair(d, e));
            map.at(d).push_back(make_pair(c, e));
        } else {
            // 問合わせ
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            // 毎回ダイクストラやるのか
            vector<ll> cost(n, inf);
            dijkstra(map, a, cost);
            if(cost.at(b) < inf) {
                cout << cost.at(b) << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}
