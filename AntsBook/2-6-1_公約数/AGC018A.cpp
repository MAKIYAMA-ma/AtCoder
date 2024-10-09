#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
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


int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    /* 二つの数値の差の絶対値を追加できる */
    /* -> 繰り返すことで、任意のa,bについてa%bのボールが追加できる */
    /* --> 任意のa > bについて、gcd(a, b)のa以下の倍数は作成可能 */

    /* 任意の組合せのGCDの中に、kの約数があり、その約数の倍数でk以上の値がaに含まれればOK */
    // (1) 任意の2数のGCDを求める
    //     ただし、どちらか一方はk以上であること。
    // (2) 各GCDの中からkの約数を探す
    //     見つかれば、作成可能
    sort(all(a));
    a.erase(unique(all(a)), a.end());

    // これだとTLE
    // 大半のカードがK以上のカードだとO(N^2)の計算をフルにやる事になる。
    // もっと圧縮できないのか
    // 既に見つかったGCDを活用できない？？
#if 1
    for(int i = a.size()-1; i >= 0 && a.at(i) >= k; i--) {
        if(a.at(i) == k) {
            // そもそもkのカード1枚しかもともとない場合等は、この条件でないと引っ掛からない
            // 重複除去するなら、kが何枚もあるケースも同様
            // 他のカードが1枚でもあれば、kの約数が何かしら抽出されるはず
            cout << "POSSIBLE" << endl;
            return 0;
        }
        for(int j = i-1; j >= 0; j--) {
            if(k % gcd(a.at(i), a.at(j)) == 0) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
#else
    rep(i, a.size()) {
        if(a.at(i) == k) {
            // そもそもkのカード1枚しかもともとない場合等は、この条件でないと引っ掛からない
            // 重複除去するなら、kが何枚もあるケースも同様
            // 他のカードが1枚でもあれば、kの約数が何かしら抽出されるはず
            cout << "POSSIBLE" << endl;
            return 0;
        }
        for(int j = i+1; j < a.size(); j++) {
            if(a.at(i) >= k || a.at(j) >= k) {
                if(k % gcd(a.at(i), a.at(j)) == 0) {
                    cout << "POSSIBLE" << endl;
                    return 0;
                }
            }
        }
    }
#endif
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
