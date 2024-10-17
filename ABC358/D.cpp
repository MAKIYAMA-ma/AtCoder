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
    int n, m;
    cin >> n >> m;

    vector<ll> a(n, 0);
    vector<ll> b(m, 0);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];


    ll ans = 0;
#if 1
    // 小さいほうからの貪欲でも別に問題ないか
    // それなら尺取り的にいける
    sort(all(a));
    sort(all(b));
    int ai = 0;
    for(auto top : b) {
        while(ai < n && a[ai] < top) {
            ai++;
        }
        if(ai >= n) {
            cout << -1 << endl;
            return 0;
        }
        ans += a[ai++];
    }
    cout << ans << endl;
#elif 0
    // bの大きいほうから順に一番弱い箱を買っていく貪欲で良いのでは。
    sort(all(a));
    sort(rall(b));

    // vectorのeraseもO(N)なので、これだとO(N2)になり、usedを使う際と変わらない
    // setが使えれば削除が速いが、同一要素がありうるので却下
    for(auto top : b) {
        auto lp = lower_bound(all(a), top);
        if(lp == a.end()) {
            cout << -1 << endl;
            return 0;
        }
        ans += *lp;
        a.erase(lp);
    }
    cout << ans << endl;
#else
    // bの大きいほうから順に一番弱い箱を買っていく貪欲で良いのでは。
    sort(all(a));
    sort(rall(b));

    // これだとTLE
    vector<bool> used(n, false);
    for(auto top : b) {
        auto ind = lower_bound(all(a), top) - a.begin();
        while(ind < n && used[ind]) {
            ind++;
        }
        if(ind >= n) {
            cout << -1 << endl;
            return 0;
        }
        ans += a[ind];
        used[ind] = true;
    }
    cout << ans << endl;
#endif
}
