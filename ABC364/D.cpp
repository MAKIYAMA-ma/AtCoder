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
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));

    rep(i, q) {
        ll b, k;
        cin >> b >> k;

        // TODO 毎回検索するとTLEとなるが、何かの累積とか計算しとくとクエリに一瞬で答えられる、
        // 系の問題と思われる
        // ---> 違った。答えの二分探索らしい。
#if 1
        ll l = -1;
        ll r = MAXLL;
        while((r - l) > 1) {
            ll mid = (l+r)/2;
            int li = lower_bound(all(a), b-mid) - a.begin();
            int ri = upper_bound(all(a), b+mid) - a.begin();

            /* cout << "DB:" << l << ":" << r << ":" << mid << "::" << li << ":" << ri << endl; */
            if((ri - li) >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        /* cout << "DB2:" << l << ":" << r << endl; */
        cout << r << endl;
#elif 0
        // こんなややこしい判定いらない
        ll l = 0;
        ll r = MAXLL;
        while(true) {
            ll mid = (l+r)/2;
            int li = lower_bound(all(a), b-mid) - a.begin();
            int ri = upper_bound(all(a), b+mid) - a.begin();

            /* cout << "DB:" << l << ":" << r << ":" << mid << "::" << li << ":" << ri << endl; */
            if((ri - li) == k) {
                if(ri > 0) ri--;
                cout << max(abs(a[ri]-b), abs(b-a[li])) << endl;
                break;
            } else if(ri == li || l == r) {
                // 同じ距離に複数ある
                cout << abs(a[li]-b) << endl;
                break;
            } else if((ri - li) > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
#else
        // 何も考えないなら、bごとに差分を計算して配列作ってソートしてk番目を探す、とかになるが
        // それだとO(Q(N+logN))とかになるのでは
        vector<ll> dir(n);
        rep(j, n) {
            dir[j] = abs(a[j] - b);
        }
        sort(all(dir));
        /* cout << "--------" << endl; */
        /* rep(j, n) { */
        /*     cout << dir[j] << " "; */
        /* } */
        /* cout << endl; */
        /* cout << "--------" << endl; */
        cout << dir[k-1] << endl;
#endif
    }
}
