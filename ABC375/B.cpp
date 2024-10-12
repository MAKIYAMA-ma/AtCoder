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

    ll cx = 0, cy = 0;
    long double ans = 0;
    ll x, y;
    rep(i, n) {
        cin >> x >> y;
        ans += sqrt((x-cx)*(x-cx) + (y-cy)*(y-cy));
        cx = x;
        cy = y;
    }
    ans += sqrt((y)*(y)+ (x)*(x));
    cout << fixed << setprecision(15) << ans << endl;
}
