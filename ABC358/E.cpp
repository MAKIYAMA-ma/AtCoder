#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 0
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


mint Factorical(ll n, ll m) {
    mint ans = 1;
    for(ll i = n; i > m; i--) {
        ans *= i;
    }
    return ans;
}

int main() {
    int k;
    cin >> k;

    vector c(26, 0);
    rep(i, 26) cin >> c[i];

    // Ci以下の26個の整数の和がKになる組み合わせの数を求める。
    // 各組み合わせの文字列が何種類あるかは、K!を各文字の個数の階乗の積で割れば求まる
    // -> 違う。K以下になる組み合わせ。K文字以下ならOKとなる。
    //
    // K=1から順にDPとかありえそうな気がするが
    // 残りの文字数が管理されていないと次の文字に何を使えるか分からない
    // 全パターン管理だと26^Kとかになるわけで、無理。
    //
    // 各数値の利用個数の制限がないならDPで可能なのだが。。
    //
    // 使える文字を増やしていくDP
    vector<vector<mint>> dp(26, vector<mint>(k+1, 0));
    rep(i, k+1) {
        if(i > c[0]) break;
        dp[0][i] = 1;
    }

    for(int i{1}; i < 26; i++) {
        rep(j, k+1) {
            /* cout << i << ":" << j << endl; */
#if 1
            // 階乗部分で同じ計算何度もするの防止
            mint combi = 1;
            for(int l{0}; l <= c[i] && l <= j; l++) {
                if(l > 0) {
                    combi *= (j-l+1);
                    combi /= l;
                }
                dp[i][j] += (dp[i-1][j-l] * combi);
            }
#else
            dp[i][j] += (dp[i-1][j]);
            mint combi = 1;
            for(int l{1}; l <= c[i] && l <= j; l++) {
                dp[i][j] += (dp[i-1][j-l]*Factorical(j, (j-l))/Factorical(l, 1));
            }
#endif
        }
    }

    /* cout << "----------" << endl; */
    /* /1* rep(i, k+1) { *1/ */
    /* rep(i, 5) { */
    /*     /1* rep(j, 26) { *1/ */
    /*     rep(j, 10) { */
    /*         cout << i << ":" << j << ": " << dp[j][i].val() << endl; */
    /*     } */
    /* } */
    /* cout << "----------" << endl; */
    // 最終の回答としては、長さ0はナシ
    cout << reduce(dp[25].begin()+1, dp[25].end()).val() << endl;
}
