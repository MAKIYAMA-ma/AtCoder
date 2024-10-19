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

int check(int l, int r, int t, int n, char h) {
    if(h == 'L') {
        if(l < r) {
            if(l < t && t < r) {
                return t-l;
            } else {
                int tmp = l-t;
                if(tmp < 0) tmp += n;
                return tmp;
            }
        } else {
            if(r < t && t < l) {
                return l-t;
            } else {
                int tmp = t-l;
                if(tmp < 0) tmp += n;
                return tmp;
            }
        }
    } else {
        if(l < r) {
            if(l < t && t < r) {
                return r-t;
            } else {
                int tmp = t-r;
                if(tmp < 0) tmp += n;
                return tmp;
            }
        } else {
            if(r < t && t < l) {
                return t-r;
            } else {
                int tmp = r-t;
                if(tmp < 0) tmp += n;
                return tmp;
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    int l{1}, r{2};

    ll ans = 0;
    rep(i, q) {
        char h;
        int t;
        cin >> h >> t;

        int a1 = check(l, r, t, n, h);
        if(h == 'L') {
            int nl = t-1;
            if(nl < 0) nl += n;

            int a2 = check(l, r, (t+1)%(n+1), n, 'R') +
                check(l, (t+1)%(n+1), t, n, 'L');
            int a3 = check(l, r, nl, n, 'R') +
                check(l, nl, t, n, 'L');
            /* cout << "DB1:" << a1 << ":" << a2 << endl; */
            int sl = min(a1, min(a2, a3));
            ans += sl;
            if(sl == a2) {
                r = (t+1)%(n+1);
            } else if(sl == a3) {
                r = nl;
            }
            l = t;
        } else {
            int nl = t-1;
            if(nl < 0) nl += n;

            int a2 = check(l, r, (t+1)%(n+1), n, 'L') +
                check((t+1)%(n+1), r, t, n, 'R');
            int a3 = check(l, r, nl, n, 'L') +
                check(nl, r, t, n, 'R');
            /* cout << "DB2:" << a1 << ":" << a2 << endl; */

            int sl = min(a1, min(a2, a3));
            ans += sl;
            if(sl == a2) {
                l = (t+1)%(n+1);
            } else if(sl == a3) {
                l = nl;
            }
            r = t;
        }
    }
    cout << ans << endl;
}
