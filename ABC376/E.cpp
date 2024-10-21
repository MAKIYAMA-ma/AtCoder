#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;

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
    ll t;
    cin >> t;

    // 小さい問題に削減はできないか？　DPは無理？
    // でも全探索はTLEする
    // 最短経路とかに帰着できる気もしないか？

    rep(i, t) {
        ll n, k;
        cin >> n >> k;
        ll ans = MAXLL;

        vpl ab(n);
        rep(j, n) cin >> ab[j].first;
        rep(j, n) cin >> ab[j].second;

        sort(all(ab));
        /* priority_queue<ll, vl, greater<ll>> bl; */
        priority_queue<ll> bl;
        ll bsum = 0;
        rep(j, k-1) {
            bl.push(ab[j].second);
            bsum += ab[j].second;
        }
        for(int j = k-1; j < n; j++) {
            auto nxt = ab[j];
            bsum += nxt.second;
            /* cout << "next (a,b): " << nxt.first << "," << nxt.second << endl; */
            ans = min(ans, nxt.first * bsum);

            bl.push(nxt.second);
            bsum -= bl.top();
            /* cout << "pop: " << bl.top() << endl; */
            bl.pop();
        }
        cout << ans << endl;
    }
}
