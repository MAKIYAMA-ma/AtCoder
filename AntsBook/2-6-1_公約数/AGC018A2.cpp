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
    ll n, k;
    cin >> n >> k;

    ll maxval = MINLL;
    ll gcdv;

    /* 二つの数値の差の絶対値を追加できる */
    /* -> 繰り返すことで、任意のa,bについてa%bのボールが追加できる */
    /* --> 任意のa > bについて、gcd(a, b)のa以下の倍数は作成可能 */
    /* 結局、全ての値の最大公約数としてkの約数が作れればOK */

    rep(i, n) {
        ll a;
        cin >> a;

        if(i == 0) {
            gcdv = a;
        } else {
            gcdv = gcd(a, gcdv);
        }
        maxval = max(maxval, a);
    }

    if((maxval >= k) && (k % gcdv == 0)) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}
