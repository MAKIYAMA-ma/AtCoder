#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    // sで示した<>の関係が全て成立する、1 ~ nの順列のパターン数
    // N <= 3000
    // 3000個の数字のどれを使ったか管理していくのはきつい
    // 単純に考えると残る数字の組合せは2^3000ある。
    //
    // k-1番の数字と、残りの数値があればk番目のOK/NGは判定できる
    //
    // dp[i][j] i番目の要素の確定時点で、i番目の要素より大きい数値がj個残っているパターン数
    //          逆に、小さい数値の個数はn - (i+1) - j 個ということ
    vm2 dp(n+1, vm(n, 0));
    rep(i, n) {
#if 1
        dp[1][i] = 1 + ((i > 0) ? dp[1][i-1] : 0);
#else
        dp[1][i] = 1;
#endif
    }
    srep(i, 2, n+1) {
        if(s[i-2] == '<') {
            // 大きい数字を使う
            // i番目まで数字が決まる段階で、残す数値の数はn-i個なので、jはn-i以下
            // 同様に、i-1番目の数値を参照する際、有効なのは j <= n-(i-1)まで
            rep(j, n-i+1) {
#if 1
                // O(N3)でTLEになるのを回避する為、累積にしてO(N2）とする。
                // N <= 3000なのでO(N2)なら間に合う。
                dp[i][j] = dp[i-1][n-i+1] - dp[i-1][j] + ((j > 0) ? dp[i][j-1] : 0);
#else
                srep(k, j+1, n-i+2) {
                    dp[i][j] += dp[i-1][k];
                }
#endif
            }
        } else {
            // 小さい数字を使う
            rep(j, n-i+1) {
#if 1
                dp[i][j] = dp[i-1][j] + ((j > 0) ? dp[i][j-1] : 0);
#else
                rep(k, j + 1) {
                    dp[i][j] += dp[i-1][k];
                }
#endif
            }
        }
    }
    cout << "----------" << endl;
    rep(i, n+1) {
        rep(j, n) {
            cout << dp[i][j].val() << " ";
        }
        cout << endl;
    }
    cout << "----------" << endl;
    // n個並べ終えた段階で、残り0個になっているのが有効なパターン
    cout << dp[n][0].val() << endl;
}
