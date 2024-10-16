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

bool pos(vector<int> &l1, vector<int> &l2) {
    if(l2[1] <= l1[0] || l1[1] <= l2[0]) {
        return false;
    } else {
        return true;
    }
}

int main() {
    vector<int> t1x(2);
    vector<int> t1y(2);
    vector<int> t1z(2);
    vector<int> t2x(2);
    vector<int> t2y(2);
    vector<int> t2z(2);
    cin >> t1x[0] >> t1y[0] >> t1z[0] >> t1x[1] >> t1y[1] >> t1z[1];
    cin >> t2x[0] >> t2y[0] >> t2z[0] >> t2x[1] >> t2y[1] >> t2z[1];

    Yes(pos(t1x, t2x) && pos(t1y, t2y) && pos(t1z, t2z));
}
