#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()

const ll MAXLL = numeric_limits<ll>::max();
const ll MINLL = numeric_limits<ll>::min();
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


typedef struct {
    int from;
    int to;
    long double cost;
} ST_EDGE;


bool BellmanFord(vector<ST_EDGE> &edges, vector<long double> &cost, int start, int goal, long double INF) {
    bool result = true;
    long double goal_cost = INF;
    cost.at(start) = 0;
    rep(i, cost.size()) {
        bool changed = false;
        for(const auto &edge : edges) {
            if(cost.at(edge.from) == INF) {
                continue;
            }
            long double nc = cost.at(edge.from) + edge.cost;
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


bool checkT(vector<ST_EDGE> &edges, vector<long double> &a, long double T) {
    // a(u) + c(u>w) <= a(w) + T
    vector<ST_EDGE> ne;
    for(auto edge : edges) {
        if(a.at(edge.from) == MAXLD) {
            if(a.at(edge.to) == MAXLD) {
                // a(u) <= a(w) + T - c(u>w)
                ne.push_back({edge.to, edge.from, T - edge.cost});
            } else {
                // a(u) <= Z + a(w) + T - c(u>w)
                ne.push_back({0, edge.from, a.at(edge.to) + T - edge.cost});
            }
        } else {
            if(a.at(edge.to) == MAXLD) {
                // Z <= a(w) + T - c(u>w) - a(u)
                ne.push_back({edge.to, 0, T - edge.cost - a.at(edge.from)});
            } else {
                if((a.at(edge.from) + edge.cost) > (a.at(edge.to) + T)) {
                    return false;
                }
            }
        }
    }
    vector<long double> cost(a.size(), MAXLD);
    return BellmanFord(ne, cost, 0, -1, MAXLD);
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long double> a(n, MAXLD);
    rep(i, k) {
        int v;
        long double vc;
        cin >> v >> vc;
        v--;
        a.at(v) = vc;
    }

    vector<ST_EDGE> edges;
    rep(i, m) {
        int u, w;
        long double c;
        cin >> u >> w >> c;
        u--;
        w--;
        edges.push_back({u, w, c});
    }

#if 0
    long double mx = MAXLD;
    long double mn = MINLD;
    while((mx - mn) >= 1e-8) {
        long double mdl = (mx + mn)/2;
        if(checkT(edges, a, mdl)) {
            mx = mdl;
        } else {
            mn = mdl;
        }
    }
    if(mx < -1e10) {
        cout << '#' << endl;
    } else {
        cout << fixed << setprecision(15) << mx << endl;
    }
#else
    if(checkT(edges, a, MINLD)) {
        cout << '#' << endl;
    } else {
        long double mx = MAXLD;
        long double mn = MINLD;
        while((mx - mn) >= 1e-8) {
            long double mdl = (mx + mn)/2;
            if(checkT(edges, a, mdl)) {
                mx = mdl;
            } else {
                mn = mdl;
            }
        }
        cout << fixed << setprecision(15) << mx << endl;
    }
#endif
}
