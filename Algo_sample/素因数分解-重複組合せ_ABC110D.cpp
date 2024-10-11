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

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


/**
 * @brief 素数判定
 *
 * @param n
 *
 * @return 
 */
bool isPrime(ll n) {
    ll fin = sqrt(n);
    vector<ll> wheel_fact = {4, 2, 4, 2, 4, 6, 2, 6};
    int wfi = 0;

    if(n == 1) {
        return false;
    }
    if((n == 2) || (n == 3) || (n == 5)) {
        return true;
    }
    if((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) {
        return false;
    }
    for(ll i = 7; i <= fin; i += wheel_fact.at(wfi++ % wheel_fact.size())) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * @brief nを素因数分解し、prmに結果を入れる関数
 *
 * @param n     素因数分解の対象
 * @param prm   分解結果。各素因数をkeyとし、その個数をvalueとして格納する。
 */
void PrimeFact(ll n, map<int, int> &prm) {
    int tmp = n;
    for(int i = 2; i <= tmp; i++) {
        // iが素数かどうかの判定は不要
        // iが素数でないなら、iの約数による割り算がもっと前に完了している
        while(tmp % i == 0) {
            prm[i]++;
            tmp /= i;
        }
    }
    /* cout << "------------" << endl; */
    /* for(auto p : prm) { */
    /*     cout << p.first << ":" << p.second << endl; */
    /* } */
    /* cout << "------------" << endl; */
}

/**
 * @brief ev個の要素からgv個のグループを作る組合せ数の計算
 * 順序なし、空グループなしで計算する。
 *
 * 第二スターリング数。
 * m個の要素をn個の非空のグループに分ける場合（順序なし、空のグループなし）
 * スターリング数 𝑆(𝑚,𝑛) S(m,n) は、m個の要素をn個のグループに分ける方法の数です。
 * S(m,n)=S(m−1,n−1)+n⋅S(m−1,n)
 * 初期条件はS(0,0)=1 とし、他はS(0,n)=0 （n > 0）です。
 *
 * @param ev 元の要素数
 * @param gv グループ数
 *
 * @return 解答
 */
ll Stirling2(ll ev, ll gv) {
    vector<vector<ll>> dp(ev+1, vector<ll>(gv+1, 0));
    dp.at(0).at(0) = 1;

    for(ll i = 1; i <= ev; i++) {
        for(ll j = 1; j <= gv; j++) {
            dp.at(i).at(j) = dp.at(i-1).at(j-1) + j * dp.at(i-1).at(j);
        }
    }

    return dp.at(ev).at(gv);
}

/**
 * @brief 階乗( n! / m!)の計算
 * 単にn!を求めたいならmを0 or 1にする
 *
 * @param n
 * @param m
 *
 * @return 
 */
mint Factorical(ll n, ll m) {
    mint ans = 1;
    for(ll i = n; i > m; i--) {
        ans *= i;
    }
    return ans;
}


int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> prm;

    // 当然、a1~aNは、mの素因数を分配して構成される。
    // mを素因数分解する
    PrimeFact(m, prm);

#if 1
    // 各素因数について、空を許し、n個のグループに分けるパターン数を計算する
    // -> 重複組合せ

    // 必要な範囲の階乗を先に計算して覚えておく
    // 何度も似た範囲の階乗計算をするのを回避
    ll prmCnt = 0;
    for(auto pe : prm) {
        prmCnt += pe.second;
    }
    vector<mint> fl(prmCnt + n, 1);
    for(int i = 2; i < prmCnt + n; i++) {
        fl.at(i) = fl.at(i-1) * i;
    }

    mint ans = 1;
    for(auto pe : prm) {
        // a個をnグループに分ける方法は、
        // a個の要素とn-1個の仕切りを並べる組合せ数と等しい。
        // よって、(a + n - 1)! / (a! * (n-1)!)で求まる
        ans *= (fl.at(pe.second + n - 1) / (fl.at(pe.second) * fl.at(n - 1)));
        /* ans *= (Factorical(pe.second + n - 1) / (Factorical(pe.second) * Factorical(n - 1))); */
        /* ans *= (Factorical(pe.second + n - 1, n - 1) / Factorical(pe.second, 1)); */
    }
    cout << ans.val() << endl;
#else
    // 素因数分解結果をどう並べてどうN個にまとめるか
    // 素因数の順序パターン数はともかく、それを更にN個にまとめるのをどうすれば
    ll prmCnt = 0;
    for(auto pe : prm) {
        prmCnt += pe.second;
    }

    // TODO (1) この結果それぞれについてN通りの順列
    // TODO (2) そのうえで、同一要素のグループの順列は除去
    // する必要がある
    // -> 各組合せを列挙しないと無理じゃないの
    cout << Stirling2(prmCnt, n) << endl;
#endif
}
