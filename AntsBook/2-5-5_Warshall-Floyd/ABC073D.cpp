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
    int n, m, r;
    cin >> n >> m >> r;

    vector<int> rl(r);
    rep(i, r) {
        cin >> rl[i];
        rl[i]--;
    }

    vector<vector<ll>> road(n, vector<ll>(n, MAXLL));
    rep(i, m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--;
        b--;
        road[a][b] = t;
        road[b][a] = t;
    }
    rep(i, n) {
        road[i][i] = 0;
    }

    // 各町間の最短距離算出
    WarshallFloyd(road);
    /* cout << "---------" << endl; */
    /* rep(i, n) { */
    /*     rep(j, n) { */
    /*         cout << rail[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "---------" << endl; */

    // 順列全列挙で探索
    sort(all(rl));
    ll ans = MAXLL;
    do {
        ll tmp = 0;
        rep(i, r-1) {
            tmp += road[rl[i]][rl[i+1]];
        }
        ans = min(ans, tmp);
    } while (next_permutation(all(rl)));
    cout << ans << endl;
}
