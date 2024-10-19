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


int main() {
    int n, q;
    cin >> n >> q;
    int l{1}, r{2};

    ll ans = 0;
    rep(i, q) {
        char h;
        int t;
        cin >> h >> t;

        if(h == 'L') {
            if(l < r) {
                if(l < t && t < r) {
                    ans += t-l;
                } else {
                    int tmp = l-t;
                    if(tmp < 0) tmp += n;
                    ans += tmp;
                }
            } else {
                if(r < t && t < l) {
                    ans += l-t;
                } else {
                    int tmp = t-l;
                    if(tmp < 0) tmp += n;
                    ans += tmp;
                }
            }
            l = t;
        } else {
            if(l < r) {
                if(l < t && t < r) {
                    ans += r-t;
                } else {
                    int tmp = t-r;
                    if(tmp < 0) tmp += n;
                    ans += tmp;
                }
            } else {
                if(r < t && t < l) {
                    ans += t-r;
                } else {
                    int tmp = r-t;
                    if(tmp < 0) tmp += n;
                    ans += tmp;
                }
            }
            r = t;
        }
    }
    cout << ans << endl;
}
