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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    // 欲しいのは格子点数であり、a, b, c, dは整数なので、
    // 始点を原点に合わせたうえで、第一象限にしてしまって構わない
    ll e = abs(c - a);
    ll f = abs(d - b);

    // 直線の式は y = (f/e)x
    // よって、xが(e/gcdv)の倍数であれば格子点となる
    // そのようなxは、0 <= x <= eの間に、(e/gcdv)*0 ~ (e/gcdv)*gcdvの、合計gcdv+1個ある。
    // 両端は除くので、gcdv-1個が答え。
    ll gcdv = gcd(e, f);

    cout << gcdv - 1 << endl;
}
