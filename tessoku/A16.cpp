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
    int n;
    cin >> n;
    vector<ll> a(n, MAXLL);
    vector<ll> b(n, MAXLL);
    rep(i, n-1) cin >> a[i+1];
    rep(i, n-2) cin >> b[i+2];

    vector<ll> ans(n, MAXLL);
    ans[0] = 0;
    ans[1] = a[1];
    for(int i{2}; i < n; i++) {
        ans[i] = min(ans[i-2]+b[i], ans[i-1]+a[i]);
    }
    cout << ans[n-1] << endl;
}
