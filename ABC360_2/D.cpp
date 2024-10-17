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
    ll n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<pair<ll, ll>> x(n, {0, 0});
    rep(i, n) cin >> x[i].first;
    rep(i, n) {
        x[i].second = (s[i] - '0');
    }
    sort(all(x));

    // 各正向きのアリxiについて、xi+2*tまでの範囲に、左向きのアリが何匹いるかの総和を求めれば良い。
    // -> 左向きのアリの引数の累積を求める。
    // 二分探索でindexを出し、それを基に総和を計算
    // O(N + NlogN)でいけるでしょ
    vector lx(n, 0);
    lx[0] = (x[0].second == 0 ? 1 : 0);
    rep(i, n-1) {
        lx[i+1] = lx[i];
        if(x[i+1].second == 0) {
            lx[i+1]++;
        }
    }

    ll ans = 0;
    rep(i, n) {
        if(x[i].second) {
            auto ind = upper_bound(all(x), x[i].first + 2*t, [](const ll k, const pair<ll, ll>& a) {
                    return (k < a.first);
                    }) - 1 - x.begin();
            if(ind > 0) {
                /* cout << "DB:" << i << " " << ind << endl; */
                ans += (lx[ind] - lx[i]);
            }
        }
    }
    cout << ans << endl;
}
