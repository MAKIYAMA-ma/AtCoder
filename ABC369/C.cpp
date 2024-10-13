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


int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    // 差の配列を作る
    vector<ll> df(n, 0);
    rep(i, n-1) {
        df.at(i+1) = a.at(i+1) - a.at(i);
    }
    ll ans = n;
    ll l = 1;
    ll r = 1;
    // 等差の範囲ごとにlとrを探す
    // その中から2つのIndexを選ぶ組み合わせ数を加算
    while(l < n) {
        while(r < n && df.at(l) == df.at(r)) {
            r++;
        }
        /* cout << "DB:" << l << " " << r << endl; */
        ans += (r-l+1)*(r-l)/2;
        l = r;
    }
    cout << ans << endl;
}
