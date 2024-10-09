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


/**
 * @brief aとbの最大公約数を求める。
 * でもライブラリでgcdって関数あるけどね。
 *
 * @param a
 * @param b
 *
 * @return 
 */
ll GCD(ll a, ll b) {
    ll v1, v2;
    if(a > b) {
        v1 = a;
        v2 = b;
    } else {
        v1 = b;
        v2 = a;
    }

    return (v2 == 0) ? v1 : GCD(v2, v1 % v2);
}


/**
 * @brief aとbの最小公倍数を求める
 * でもライブラリでlcmって関数あるけどね。
 *
 * @param a
 * @param b
 *
 * @return 
 */
ll LCM(ll a, ll b) {
    return ((a / GCD(a, b)) * b);
}


int main() {
    int n;
    cin >> n;

    vector<ll> t(n);
    rep(i, n) {
        cin >> t[i];
    }

    ll ans = t[0];
    rep(i, n-1) {
        ans = LCM(ans, t[i+1]);
    }
    cout << ans << endl;
}
