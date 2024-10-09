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

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<ll>> rail(n, vector<ll>(n, MAXLL));
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        rail[a][b] = t;
        rail[b][a] = t;
    }
    rep(i, n) {
        rail[i][i] = 0;
    }

    WarshallFloyd(rail);
    /* cout << "---------" << endl; */
    /* rep(i, n) { */
    /*     rep(j, n) { */
    /*         cout << rail[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "---------" << endl; */

    ll mv = MAXLL;
    rep(i, n) {
        ll tmp = 0;
        rep(j, n) {
            tmp = max(tmp, rail[i][j]);
        }
        mv = min(mv, tmp);
    }
    cout << mv << endl;
}
