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

/**
 * @brief 累乗
 *
 * @param x
 * @param n
 *
 * @return 
 */
ll Pow(ll x, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}


/**
 * @brief 階乗
 *
 * @param n
 * @param m
 *
 * @return 
 */
mint Factorical(ll n, ll m) {
    mint ans = 1;
    for(ll i = n; i > m; i--) {
        ans *= i;
    }
    return ans;
}


/**
 * @brief 0 ~ nの整数で、第pビット（0始まり）が立つ数字が何個あるか
 *
 * @param n
 * @param p
 *
 * @return 
 */
ll CountBit(ll n, int p) {
    ll ans = 0;
    ll cycle = ((ll)1 << (p + 1));     // 第p bitはcycle/2回0となり、cycle/2回1となるのを繰り返す
    ll cycle_num = (n+1) / cycle;  // 0~nの整数で、cycleが何個入るか

    ans = cycle_num * (cycle/2);
    ans += max((ll)0, ((n+1) % cycle) - (cycle/2)); // 余剰分に含まれる1の個数。0区間が終わった残りがあれば、その分は1

    /* cout << p << ":" << ans << endl; */
    return ans;
}


/**
 * @brief 行列の積
 *        indexはx[行][列]
 *
 * @param x
 * @param y
 *
 * @return 
 */
vector<vector<mint>> MultiArray(vector<vector<mint>> &x, vector<vector<mint>> &y) {
    vector<vector<mint>> ans(x.size(), vector<mint>(y[0].size(), 0));
    rep(i, x.size()) {
        rep(j, y[0].size()) {
            rep(k, x[0].size()) {
                ans[i][j] += (x[i][k] * y[k][j]);
            }
        }
    }
    return ans;
}


/**
 * @brief 行列の累乗
 *        indexはx[行][列]
 *
 * @param x
 * @param n
 *
 * @return 
 */
vector<vector<mint>> PowArray(vector<vector<mint>> &x, ll n) {
    vector<vector<mint>> ans(x.size(), vector<mint>(x.size(), 0));
    rep(i, x.size()) {
        ans[i][i] = 1;
    }

    while(n > 0) {
        if(n % 2) {
            ans = MultiArray(ans, x);
        }
        x = MultiArray(x, x);
        n >>= 1;
    }
    return ans;
}


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
    ll n;
    cin >> n;
}
