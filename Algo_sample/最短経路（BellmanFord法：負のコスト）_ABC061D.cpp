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

    vector<ST_EDGE> edges;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;

        edges.push_back({a, b, -c});
    }

    ll INF = (ll)1000*1000000000+1;
    vector<ll> cost(n, INF);

    if(!BellmanFord(edges, cost, 0, n-1, INF)) {
        cout << "inf" << endl;
    } else {
        cout << -cost.at(n-1) << endl;
    }
}
