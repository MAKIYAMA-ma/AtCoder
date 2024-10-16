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

ll Pow(ll x, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;

    /* n番目の回文数を求める */
    // 1≤N≤10^18
    // なのでO(N)で全探索するのは無理
    // 回文数の次の回文数は、中央の数字(1つor2つ）をインクリメントすると出てくる。
    // 9まで達したら、次の回文数は、中央を0にし、両外側を一つインクリメント。また中央のインクリメントに戻る。
    // 全部9になったら、1桁増やし、両脇を1、残りを0とする
    // という対応になる。
    // 1桁の回文数-> 0~9で10個
    // 2桁の回文数-> 11~99で9個
    // 3桁の回文数-> 101~999=10*9=90個
    // 4桁の回文数-> 1001~9999=10*9=90個
    // 5桁の回文数-> 10001~99999=10*10*9=900個
    // 6桁の回文数-> 100001~999999=10*10*9=900個
    //
    // n桁の回文数-> 10^((n-1)/2) * 9個
    // ただし、0だけ別枠
    int keta = 1;
    ll kosu = 10;
    ll pk;
    if(kosu >= n) {
        // 1桁ならここで終わる
        // 0が特殊なので別処理
        cout << n-1 << endl;
        return 0;
    }

    // 答えの桁数を求める
    while(kosu < n) {
        keta++;
        pk = kosu;
        kosu += (ll)Pow(10, (keta-1)/2)*9;
    }
    ll num = n - pk - 1;
    /* cout << "num:" << num << endl; */

    // ullでもあふれるので配列として一桁ずつ管理
    vector<int> ans(keta, 0);
    // 両端は1以上
    ans[0] = 1;
    ans[keta-1] = 1;
    int ui, di;
    // 桁桁の回文数のnum番目の数字を求める。
    // (処理しやすいのでnumを1減らし、0番目からとしている。)
    // 中央部分の数値を入れる。偶奇で対象の個数が変わる
    if(keta % 2) {
        ans[keta/2] = (num%10);
        ui = keta/2 + 1;
        di = keta/2 - 1;
    } else {
        ans[keta/2] = (num%10);
        ans[keta/2-1] = (num%10);
        ui = keta/2 + 1;
        di = keta/2 - 2;
    }
    // 外側に向けて桁を埋めていく
    num /= 10;
    while(num) {
        ans[ui] += (num%10);
        ans[di] += (num%10);
        ui++;
        di--;
        num /= 10;
    }

    rep(i, keta) {
        cout << ans[keta-i-1];
    }
    cout << endl;
}
