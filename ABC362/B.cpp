#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    vector x(3, 0);
    vector y(3, 0);

    rep(i, 3) {
        cin >> x[i] >> y[i];
    }

    vector edge(3, 0);
    rep(i, 3) {
        edge[i] = (x[i] - x[(i+1)%3])*(x[i] - x[(i+1)%3]) + (y[i] - y[(i+1)%3])*(y[i] - y[(i+1)%3]);
    }

    sort(all(edge));
    Yes(edge[2] == (edge[0] + edge[1]));
}
