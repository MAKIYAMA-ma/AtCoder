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
    int n, m;
    cin >> n >> m;

    vector<int> ic(n, 0);
    int full = (1 << m) - 1;
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, m) {
            if(s[j] == 'o') {
                ic[i] |= (1 << j);
            }
        }
    }

    int ans = n;
    rep(i, (1 << n)) {
        int tmp = 0;
        rep(j, n) {
            if(i & (1 << j)) {
                tmp |= ic[j];
            }
        }
        if(tmp == full) {
            ans = min(ans, __builtin_popcount(i));
        }
    }
    cout << ans << endl;
}
