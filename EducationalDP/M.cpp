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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, n) cin >> a[i];

    // kを、a[i]以下のn個の正整数の和に分割するパターン数を求める
    // k-a[n-1] ~ kを、n-1までのa[i]に分割する方法の和に等しい
    // 1 ≤ N ≤ 100
    // 0 ≤ K ≤ 10^5
    // NxKの配列で問題ない
    vector<vector<mint>> dp(n, vector<mint>(k+1, 0));
#if 1
    // 毎回足すのばからしいのでdpの中身を累積に変更。
    // これなら10^2 * 10^5 = 10^7のループなので余裕。
    dp[0][0] = 1;
    srep(i, 1, k+1) {
        if(i <= a[0]) {
            dp[0][i] += dp[0][i-1] + 1;
        } else {
            dp[0][i] += dp[0][i-1];
        }
    }
    srep(i, 1, n) {
        rep(j, k+1) {
            dp[i][j] = ((j > 0) ? dp[i][j-1] : 0) + dp[i-1][j] - ((j - a[i] - 1 >= 0) ? dp[i-1][j-a[i]-1] : 0);
        }
    }
    /* cout << "-------------" << endl; */
    /* rep(i, n) { */
    /*     rep(j, k+1) { */
    /*         cout << dp[i][j].val() << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "-------------" << endl; */
    cout << (dp[n-1][k] - dp[n-1][k-1]).val() << endl;
#else
    rep(i, a[0]+1) {
        dp[0][i] = 1;
    }
    // TODO TLEとなった
    // 最大で10^2 * 10^5 * 10*5 = 10^12
    // AtCoderでは10^8回/secくらいが目安だそうなので、これだとTLE
    srep(i, 1, n) {
        rep(j, k+1) {
            int mx = min(j+1, a[i]+1);
            rep(l, mx) {
                dp[i][j] += dp[i-1][j-l];
            }
        }
    }
    cout << dp[n-1][k].val() << endl;
#endif
}
