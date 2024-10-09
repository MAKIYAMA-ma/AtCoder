#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

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
    int n, m, s, t;
    ll money = pow(10, 15);

    cin >> n >> m >> s >> t;
    s--;
    t--;

    vector<vector<pair<int, int>>> ymap(n, vector<pair<int, int>>());
    vector<vector<pair<int, int>>> smap(n, vector<pair<int, int>>());
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
    vector<ll> yc(n, pow(10, 14));
    dijkstra(ymap, s, yc);

    /* ダイクストラ法でtからの各都市のスヌークコストを求める */
    vector<ll> sc(n, pow(10, 14));
    dijkstra(smap, t, sc);

    // 後から順に累積min
    vector<ll> accumin(n, 0);
    accumin.at(n-1) = yc.at(n-1) + sc.at(n-1);
    for(int i = n-2; i >= 0; i--) {
        accumin.at(i) = min(accumin.at(i+1), yc.at(i) + sc.at(i));
    }
    // 回答
    rep(i, n) {
        cout << money - accumin.at(i) << endl;
    }
}
