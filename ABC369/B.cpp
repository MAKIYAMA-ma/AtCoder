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

    int ans = 0;
    int lp = -1, rp = -1;
    rep(i, n) {
        int a;
        char s;
        cin >> a >> s;

        if(s == 'L') {
            if(lp < 0) {
                lp = a;
            } else {
                ans += abs(a - lp);
                lp = a;
            }
        } else {
            if(rp < 0) {
                rp = a;
            } else {
                ans += abs(a - rp);
                rp = a;
            }
        }
    }
    cout << ans << endl;
}
