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


int main() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    ll sum = 0;
    rep(i, n) {
        sum += a[i];
    }
    if(sum <= m) {
        cout << "infinite" << endl;
        return 0;
    }

    vector<ll> cum(n);
    cum[0] = a[0];
    rep(i, n-1) {
        cum[i+1] = cum[i] + a[i+1];
    }
    // i番目以降に支給する場合の最低予算
    vector<ll> bag(n);
    rep(i, n) {
        bag[i] = cum[i] + (a[i]+1)*(n-i-1);
    }
    // MAXで、ind番目以降の人に支給するのが予算的に限界
    int ind = upper_bound(all(bag), m) - bag.begin() - 1;

    if(ind < 0) {
        // 全員支給対象の場合
        cout << m/n << endl;
    } else {
        // ind番目以降の人に最大いくらずつ払えるか
        ll ans = (m - cum[ind])/(n - ind - 1);
        cout << ans << endl;
    }
}
