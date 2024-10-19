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
    int n;
    cin >> n;

    vi a(n, 0);
    vi b(n-1, 0);
    rep(i, n) cin >> a[i];
    rep(i, n-1) cin >> b[i];
    sort(rall(a));
    sort(rall(b));

    int bx = -1;
    int ai{0}, bi{0};
    rep(i, n) {
        if(bi == n-1) {
            bx = a[ai];
            break;
        }
        if(b[bi] >= a[ai]) {
            ai++;
            bi++;
        } else {
            if(bx < 0) {
                bx = a[ai];
                ai++;
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << bx << endl;
}
