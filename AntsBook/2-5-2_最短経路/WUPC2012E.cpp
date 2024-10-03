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

typedef struct {
    int no;
    int m4;
    int m7;
} STATE;

void dijkstra(vector<vector<pair<int, int>>> &graph, int start, vector<vector<vector<ll>>> &cost) {
    // priority_queueのカスタムコンパレータ
    auto cmp = [](const pair<ll, STATE> &a, const pair<ll, STATE> &b) {
        return a.first > b.first;  // firstが小さい順に取り出す
    };

    priority_queue<pair<ll, STATE>, vector<pair<ll, STATE>>, decltype(cmp)> q(cmp);
    cost.at(start).at(0).at(0) = 0;
    STATE st = {start, 0, 0};
    q.push(make_pair(0, st));

    while(!q.empty()) {
        auto from = q.top().second;
        auto cst = q.top().first;
        q.pop();

        if(cost.at(from.no).at(from.m4).at(from.m7) < cst) {
            continue;
        }
        rep(i, graph.at(from.no).size()) {
            int to = graph.at(from.no).at(i).first;
            ll nc = graph.at(from.no).at(i).second + cst;
            int m4 = nc % 4;
            int m7 = nc % 7;

            if(nc < cost.at(to).at(m4).at(m7)) {
                cost.at(to).at(m4).at(m7) = nc;
                STATE tmp = {to, m4, m7};
                q.push(make_pair(nc, tmp));
            }
        }
    }
}

int main() {
    int n, m;
    ll inf = 9223372036854775807;
    cin >> n >> m;

    vector<vector<pair<int, int>>> map(n, vector<pair<int, int>>());
    rep(i, m) {
        int f, t, c;
        cin >> f >> t >> c;
        map.at(f).push_back(make_pair(t, c));
        map.at(t).push_back(make_pair(f, c));
    }

    /* 条件付きで最短距離を求める */
    /* 当然、全ての街を4-7縛りで計算する必要があるわけではない */
    /* 何で帳尻を合わせるのか？ */

    /* (1) 都市 */
    /* (2) mod4 = 0, 1, 2, 3 */
    /* (3) mod7 = 0, 1, 2, 3, 4, 5, 6 */
    /* 1000 * 4 * 7 = 28000状態 */
    vector<vector<vector<ll>>> cost(n, vector<vector<ll>>(4, vector<ll>(7, inf)));
    dijkstra(map, 0, cost);

    ll ans = inf;
    rep(i, 4) {
        ans = min(ans, cost.at(n-1).at(i).at(0));
    }
    rep(i, 7) {
        ans = min(ans, cost.at(n-1).at(0).at(i));
    }
    cout << ans << endl;
}
