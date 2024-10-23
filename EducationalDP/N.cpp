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


ll merge(vl &ac, int l, int r, vl2 &dp) {
    if(dp[l][r] != MAXLL) return dp[l][r];
    if(l == r) {
        dp[l][r] = 0;
        return dp[l][r];
    }
    srep(i, l, r) {
        dp[l][r] = min(dp[l][r], merge(ac, l, i, dp) + merge(ac, i+1, r, dp) + ac[r] - ((l > 0) ? ac[l-1] : 0));
    }
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vl a(n);
    rep(i, n) cin >> a[i];

    vl ac(n);   // スライムサイズの累積配列
    ac[0] = a[0];
    srep(i, 1, n) {
        ac[i] = ac[i-1] + a[i];
    }

    // 基本的には、大きいものほど合体に使う回数を減らしたい
    // 端から処理の縛りはないので区間DPとかとも違う感じ
    // 途中経過の状態をどう管理するのか？
    // 2 ≤ N ≤ 400
    // 1 ≤ ai ≤ 10^9
    // 各隙間が合体済みか否かだと、2^399状態になってしまう。
    // 合体はn-1回で絶対終わる
    //
    // n-1回目にkとk+1の間を合体するなら、コストは
    // 1 ~ kの最小コスト + k+1 ~ nの最小コスト+ 1 ~ n のスライムの合計
    // しかしこの路線でたどるなら上記の2^399状態の路線になる。。。
    //
    // l ~ rまでの合体の最小コストということだと行けるのでは？
    // 組合せ数は高々400*399/2しかない

    vl2 dp(n, vl(n, MAXLL));
    cout << merge(ac, 0, n-1, dp) << endl;
}
