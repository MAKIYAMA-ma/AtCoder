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
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    // i=0 ~ n-k-1の範囲で、回文か否かチェック
    // その際、両方?なら*2となる。
    // O(NK)で探索できるのでは？？
    // N, K <= 1000だから間に合いそうだが。
    //
    // --> この場合、回文エリア以外の?は何でもいいことになる。
    // そのうえで、回文の個数をトータルの個数から引く？（その後998244353を足す）
    // ただ、別の場所で回文を作った際との重複が発生する。
    // 回文エリアがかぶっていないなら、エリアAで計算した個数のうち、エリアB内を回文にする？の設定パターン数は除くとか
    // でも重複があるとさらにわけわからなくなる
    //
    // ?の個数次第だが、最悪2^1000と考えれば全探索なんて論外
    // DPや最短経路な感じでもない
    // UnionFindとかで何かできる気もしない
    // 木構造とかを活かして何かできるのか？
    //
    // ----> DPらしいがよくわからない。。。
    mint ans = 0;
    rep(i, n-k) {
        mint tmp = 1;
        bool kai = true;
        rep(j, (k+1)/2) {
            int l = i+j;
            int r = i+k-1-j;

            if(s[l] == '?' && s[r] == '?') {
                tmp *= 2;
            } else if(s[l] != '?' && s[r] != '?' && s[l] != s[r]) {
                kai = false;
                break;
            }
        }
        if(kai) {
        }
    }
}
