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


int main() {
    ll n, x;
    cin >> n >> x;

    ll v1 = max(x, n-x);
    ll v2 = min(x, n-x);

    ll ans = n;
    while(v2 != 0) {
        ll v3 = v1 % v2;
        ans += (((v1/v2) * 2) * v2);

        if(!v3) {
            ans -= v2;
        }

        v1 = v2;
        v2 = v3;
    }

    cout << ans << endl;
}
