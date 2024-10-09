#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

void WarshallFloyd(vector<vector<ll>> &cost) {
    rep(k, cost.size()) {
        rep(i, cost.size()) {
            rep(j, cost.size()) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

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
    int h, w;
    cin >> h >> w;

#if 0
    // 正のコスト最短経路なのでダイクストラでもいける
    // でも始点ごとに10回（9回でもOK）実行することを考えると、
    // WarshallFloydを一回やるほうが速いっぽい
    vector<vector<pair<int, int>>> c(10);
    rep(i, 10) {
        rep(j, 10) {
            int cst;
            cin >> cst;
            c[i].push_back(make_pair(j, cst));
        }
    }

    vector<vector<int>> a(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    vector<ll> cost(10);
    rep(i, 10) {
        vector<ll> tmp(10, MAXLL);
        dijkstra(c, i, tmp);
        cost[i] = tmp[1];
    }

    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(a[i][j] >= 0) {
                ans += cost[a[i][j]];
            }
        }
    }
    cout << ans << endl;

#else
    vector<vector<ll>> c(10, vector<ll>(10, 0));
    rep(i, 10) {
        rep(j, 10) {
            cin >> c[i][j];
        }
    }

    vector<vector<int>> a(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            cin >> a[i][j];
        }
    }

    /* 各数字から1への最短コストを求める */
    /* そのうえで、aの値に応じて足していく */
    WarshallFloyd(c);
    ll ans = 0;
    rep(i, h) {
        rep(j, w) {
            if(a[i][j] >= 0) {
                ans += c[a[i][j]][1];
            }
        }
    }
    cout << ans << endl;
#endif
}
