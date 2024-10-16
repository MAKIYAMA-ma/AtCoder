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
    string s, t;
    cin >> n >> s >> t;

    vector sl(n+2, 0), tl(n+2, 0);
    rep(i, n) {
        if(s[i] == 'W') {
            sl[i] = 1;
        } else if(s[i] == 'B') {
            sl[i] = 2;
        }
    }
    rep(i, n) {
        if(t[i] == 'W') {
            tl[i] = 1;
        } elte if(t[i] == 'B') {
            tl[i] = 2;
        }
    }

    // 隣接する2個単位で要素を移動して行くことにより、sをtにできるか？
    // できるなら何手で可能か？
    // 不可能なら-1とする
    // BWBWBW..
    // BW..BWBW
    // BWWBB..W
    // ..WBBBWW
    // WWWBBB..
    // NとN+1をセットで移動することもあり得るので2個単位で交換するのとは違う
}
