#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;

using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<pi>;
using vb = vector<bool>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vp2 = vector<vp>;

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

ll combine(int n, int k, int start, vi& current, ll ans, vl& a, vl& b) {
    if (current.size() == k) {
        ll am = 1;
        ll sb = 0;
        for(auto t: current) {
            am = max(a[t], am);
            sb += b[t];
        }
        ans = min(ans, am*sb);
        return ans;
    }

    for (int i = start; i < n; ++i) {
        current.push_back(i);
        ans = combine(n, k, i + 1, current, ans, a, b);
        current.pop_back();
    }
    return ans;
}

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

        vl a(n), b(n);
        rep(j, n) cin >> a[j];
        rep(j, n) cin >> b[j];
#if 1
        vp s(n);
        rep(j, n) {
            s[j].first = a[j]*b[j];
            s[j].second = j;
        }
        sort(all(s));
        ll am = 1;
        ll sb = 0;
        rep(j, k) {
            am = max(a[s[j].second], am);
            sb += b[s[j].second];
        }
        ans = am*sb;
#else
        vi current;
        ans = combine(n, k, 0, current, ans, a, b);
#endif
        cout << ans << endl;
    }
}
