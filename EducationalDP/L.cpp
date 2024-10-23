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
using vd = vector<double>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;

#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

ll check(vi &a, int l, int r, bool plus, vl2 &pt, vb2 &visited) {
    if(visited[l][r]) return pt[l][r];
    if(l == r) {
        pt[l][r] = a[l] * (plus ? 1 : -1);
    } else {
        if(plus) {
            pt[l][r] = max(check(a, l+1, r, !plus, pt, visited) + a[l], check(a, l, r-1, !plus, pt, visited) + a[r]);
        } else {
            pt[l][r] = min(check(a, l+1, r, !plus, pt, visited) - a[l], check(a, l, r-1, !plus, pt, visited) - a[r]);
        }
    }
    visited[l][r] = true;
    return pt[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vi a(n, 0);
    rep(i, n) cin >> a[i];

    vl2 pt(n, vl(n, 0));
    vb2 visited(n, vb(n, false));
    cout << check(a, 0, n-1, true, pt, visited) << endl;
}
