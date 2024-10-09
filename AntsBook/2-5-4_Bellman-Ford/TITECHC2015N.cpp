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


/**
 * @brief 負閉路の有無を検出する
 *
 * @param edges 辺の情報
 * @param pn    頂点の数(edgesに設定した頂点情報が0 ~ pn-1であること）
 *
 * @return true:負閉路がない false:負閉路がある
 */
bool checkNegativeCycle(vector<ST_EDGE> &edges, int pn) {
    bool result = true;
    // 始点からの正確な最短コストは不要なので、全て0スタートとする
    // なので連結でなくても負閉路の検出はできる
    vector<long double> cost(pn, 0);
    rep(i, cost.size()) {
        bool changed = false;
        for(const auto &edge : edges) {
            long double nc = cost.at(edge.from) + edge.cost;
            if(nc < cost.at(edge.to)) {
                cost.at(edge.to) = nc;
                changed = true;
            }
        }
        if(!changed) {
            break;
        }
        if(i == cost.size()-1) {
            result = false;
        }
    }

    return result;
}


bool checkT(vector<ST_EDGE> &edges, vector<long double> &a, long double T) {
    // a(u) + c(u>w) <= a(w) + T
    vector<ST_EDGE> ne;
#if 0
    for(auto edge : edges) {
        ne.push_back({edge.to, edge.from, T - edge.cost});
    }
    rep(i, a.size()) {
        if(a.at(i) != MAXLD) {
            ne.push_back({0, i, a.at(i)});
            ne.push_back({i, 0, -a.at(i)});
        }
    }
    vector<long double> cost(a.size(), 0);
#else
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
    // 全て連結の保証がないので、連結要素の始点をそれぞれ0にしたい
    // しかし、今回はそもそも負閉路の有無のチェックのみで、その際のコストは不要なので、
    // 全部0スタートで問題ない。
    /* vector<long double> cost(a.size(), 0); */
#endif
    /* return BellmanFord(ne, cost, MAXLD); */
    return checkNegativeCycle(ne, a.size());
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long double> a(n+1, MAXLD);
    rep(i, k) {
        int v;
        long double vc;
        cin >> v >> vc;
        /* v--; */
        a.at(v) = vc;
    }

    vector<ST_EDGE> edges;
    rep(i, m) {
        int u, w;
        long double c;
        cin >> u >> w >> c;
        /* u--; */
        /* w--; */
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
