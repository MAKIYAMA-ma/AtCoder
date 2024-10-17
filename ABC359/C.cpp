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
    vector<ll> x(2, 0);
    vector<ll> y(2, 0);
    cin >> x[0] >> y[0] >> x[1] >> y[1];

    int s, t;
    if(x[0] < x[1]) {
        s = 0;
        t = 1;
    } else {
        s = 1;
        t = 0;
    }

    ll ans = abs(y[0] - y[1]);
    ll dif = x[t] - x[s];
    // 縦移動中に、横方向の距離を詰める分
    if(dif > ans) {
        dif -= ans;
    } else {
        dif = 0;
    }
    if((x[s] + y[s]) % 2 == 0) {
        dif--;
    }
    // 残りの横移動ぶん
    ans += (dif+1)/2;
    cout << ans << endl;

    // y方向は、座標の差分だけタイルをまたぐ必要がある
    // その過程で、x方向への移動はy方向に移動した分だけ追加コストなしで可能
    // 面倒なので、左にあるほうをスタートとして金額を換算すればよいか。
    // そのうえで、スタートが偶数位置なら追加で1だけx方向を吸収できる。
}
