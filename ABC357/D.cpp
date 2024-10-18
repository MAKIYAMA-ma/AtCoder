#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 0
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


mint Pow(mint x, ll n) {
    mint ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;

    int keta = 0;
    ll tmp = n;
    while(tmp > 0) {
        tmp /= 10;
        keta++;
    }

#if 1
    // (10^0 + 10^k + 10^2k + … + 10^(n-1)k) * n
    // の形に変形できるので、等比数列の和の公式で計算
    mint ans = (1 - Pow(Pow(10, keta), n)) / (1 - Pow(10, keta));
    ans *= n;
    cout << ans.val() << endl;
#else
    // 文言通りの実装だとTLE(O(N)だが、10^18とかまでいくので）
    ll pt = Pow(10, keta);
    mint ans = 0;
    for(ll i = n; i > 0; i--) {
        ans *= pt;
        ans += n;
    }
    cout << ans.val() << endl;
#endif
}
