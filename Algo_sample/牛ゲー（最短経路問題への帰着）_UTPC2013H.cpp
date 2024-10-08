#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


typedef struct {
    int from;
    int to;
    int cost;
} ST_EDGE;


bool BellmanFord(vector<ST_EDGE> &edges, vector<ll> &cost, int start, int goal, ll INF) {
    bool result = true;
    ll goal_cost = INF;
    cost.at(start) = 0;
    rep(i, cost.size()) {
        bool changed = false;
        for(const auto &edge : edges) {
            if(cost.at(edge.from) == INF) {
                continue;
            }
            ll nc = cost.at(edge.from) + edge.cost;
            if(nc < cost.at(edge.to)) {
                cost.at(edge.to) = nc;
                changed = true;
            }
        }
        if(!changed) {
            break;
        }
        if(goal < 0) {
            // ゴールの指定がない（-1）なら、ループがあるとNG
            if(i == cost.size()-1) {
                result = false;
            }
        } else {
            // ゴールが指定されている場合、たとえループがあってもゴールのコストは変わらないならOKとする
            // -> ループ内でコストがプラスマイナス0になる
            if(i == cost.size()-2) {
                goal_cost = cost.at(goal);
            } else if(i == cost.size()-1) {
                if(goal_cost != cost.at(goal)) {
                    result = false;
                }
            }
        }
    }

    return result;
}



int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n), q(n);
    vector<pair<int, int>> xy(m, {0, 0});
    vector<pair<int, int>> ab(m, {0, 0});
    rep(i, n) {
        cin >> p.at(i);
    }
    rep(i, n) {
        cin >> q.at(i);
    }
    rep(i, m) {
        cin >> xy.at(i).first >> xy.at(i).second >> ab.at(i).first >> ab.at(i).second;
    }

    // 0 <= s(i) <= p(i)
    // 0 <= t(j) <= q(j)
    // a(i,j) <= s(i) + t(j) <= b(i,j)
    // を満たすs, tがあればyes
    //
    // --->
    // 各不等式に適宜Z(=0) を加えて形を整えると、
    // z <= s(i) + 0
    // s(i) <= z + p(i)
    // -t(j) <= z + 0
    // z <= -t(j) + q(j)
    // -t(j) <= s(i) - a(i,j)
    // s(i) <= -t(j) + b(i,j)
    // となる。
    // z, s(i), -t(j)を頂点とし、zを始点（コスト0）とし、
    // 上記不等式に従い、
    // y <= x + cであればx->yにコストcの有向辺を持つグラフを定義して最短経路問題として解けばよい。
    // 解が存在すれば、そのようなsとtが定義できるということ。

    ll INF = 1e18;
    vector<ST_EDGE> edges;
    // 0        :start
    // 1-n      :x方向強度
    // n+1-2*n  :y方向強度
    vector<ll> cost(n*2 + 1, INF);

    cost.at(0) = 0;
    rep(i, n) {
        edges.push_back({i+1, 0, 0});
        edges.push_back({0, n+i+1, 0});
        edges.push_back({0, i+1, p.at(i)});
        edges.push_back({n+i+1, 0, q.at(i)});
    }
    rep(i, m) {
        int x, y, a, b;
        x = xy.at(i).first;
        y = xy.at(i).second;
        a = ab.at(i).first;
        b = ab.at(i).second;

        edges.push_back({x, n+y, -a});
        edges.push_back({n+y, x, b});
    }

    if(BellmanFord(edges, cost, 0, -1, INF)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}
