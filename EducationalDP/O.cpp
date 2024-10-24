#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;

#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
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

int popcount(int x) {
    return __builtin_popcount(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vi2 a(n, vi(n, 0));
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }

    // 残っている女性の組合せごとのDP
    // 1:ペアリング済み 0:未ペアリング
    vector<mint> dp(1 << n, 0);
    dp[0] = 1;

    rep(i, (1 << n) - 1) {
        // ペアリングする順番は結果に関係ない
        // よって、0番からn番に向けて、各男性のペアを決定していく、という順序で固定する。
        // -> ペアリング済みの女性がmn人なら、ペアを探す男性はmn番。
        int mn = popcount(i);
        rep(j, n) {
            if(a[mn][j] && !(i & (1 << j))) {
                // 常にビットが増えた要素を更新するので、0から順に更新するなら問題ない
                dp[i | (1 << j)] += dp[i];
            }
        }
    }
    cout << dp[(1 << n)-1].val() << endl;
}
