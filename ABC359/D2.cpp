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


int main() {
    unsigned N, K;
    cin >> N >> K;

    // A=0, B=1としてAB文字列を10文字列の数値で表す。
    // その前提で、回文でないK文字をあらかじめ列挙する
    //
    // 長さ K の 0/1 文字列のうち、回文でないもの
    // を二進法で表された整数として解釈したもの
    vector<unsigned> not_palindrome;
    for (unsigned i = 0; i < 1U << K; ++i) {
        bool is_palindrome = true;
        for (unsigned j = 0, k = K - 1; j < k; ++j, --k){
            // 上から見たときと下から見たときで違うビットがあれば
            if ((1 & i >> j) != (1 & i >> k)){
                // 回文ではない
                is_palindrome = false;
                break;
            }
        }
        // 回文でなければ追加
        if (!is_palindrome)
            not_palindrome.emplace_back(i);
    }

    string S;
    cin >> S;

    vector<mint> dp(1U << K - 1), prev(1U << K - 1);
    { // 先頭 K - 1 文字としてありえるものをすべて列挙する
        // a_mask = 'A' の場所だけ 1 になっているビットマスク
        // q_mask = '?' の場所だけ 0 になっているビットマスク
        unsigned a_mask{}, q_mask{};
        for (const auto c : S | views::take(K - 1)) {
            // <-- コンテナSの先頭K-1要素を順に取得する。
            // range-based for ループというらしい
            // rep(i, k) でs[i]にアクセスするのと同じか。
            (a_mask *= 2) += c == 'A';
            (q_mask *= 2) += c != '?';
        }

        // q_mask のビットは常に確定させて、'?' の部分を全探索
        for (unsigned i{q_mask}; i < 1U << K - 1; ++i |= q_mask)
            // i{q_mask}というのは、iをq_maskで初期化するという事らしい。
            // q_maskが=0の部分を全探索
            // そのうえで、a_maskの位置は0に落とす事で、?にA/Bのどちらを詰めるかを網羅している。
            // a_maskの位置はもともと常に1なので、& ~a_maskと同じことをしているかと。
            // そして、その接尾辞（K-1字）の「いい文字列」が1あることを記録する。
            dp[i ^ a_mask] = 1;
    }

    const unsigned mask{(1U << K - 1) - 1};
    for (const auto c : S | views::drop(K - 1)) {
        // <-- takeと逆に、先頭K-1要素は捨てるということか
        swap(dp, prev);
        // <- 二つのvectorを入れ替えられるらしい。
        // ひとつ前のDPをprevに持っておく
        ranges::fill(dp, mint{});
        // 最新のDPは0初期化

        // 'A' を追加する場合
        if (c != 'B')
            // 回文でなく、末尾が 'A'(0) であるような場合について遷移する
            for(const auto i : not_palindrome | views::filter([](auto i){return ~i & 1;}))
                dp[i & mask] += prev[i / 2];

        // 'B' を追加する場合
        if (c != 'A')
            // 回文でなく、末尾が 'B'(1) であるような場合について遷移する
            for(const auto i : not_palindrome | views::filter([](auto i){return i & 1;}))
                dp[i & mask] += prev[i / 2];
    }

    // すべての接尾辞に対する合計が答え
    cout << reduce(begin(dp), end(dp)).val() << endl;
    // <-- reduce は std::accumulate と似た機能で、全要素を畳み込み演算してくれるそうな。
    return 0;
}
