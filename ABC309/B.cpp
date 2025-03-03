#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif

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
using vm = vector<mint>;
using vs = vector<string>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(ll i = (ll)(s); i < (ll)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;
#define Def(n) ll n; cin >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define DefPA(a, n) vl a(n); rep(i, n) cin >> a[i].first >> a[i].second;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
const int MAXI = 1e9;
const int MINI = -1e9;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vs a(n);
    rep(i, n) cin >> a[i];
    vl2 by(2, vl(n));
    vl2 bt(n, vl(2));
    by[0][0] = a[1][0]-'0';
    by[1][n-1] = a[n-2][n-1]-'0';
    srep(i, 1, n) {
        by[0][i] = a[0][i-1]-'0';
        by[1][n-1-i] = a[n-1][n-i]-'0';
    }
    bt[0][1] = a[0][n-2]-'0';
    bt[n-2][0] = a[n-1][1]-'0';
    srep(i, 1, n) {
        bt[i][1] = a[i-1][n-1]-'0';
        bt[n-1-i][0] = a[n-i][0]-'0';
    }
    rep(i, n) {
        cout << by[0][i];
    }
    cout << endl;
    srep(i, 1, n-1) {
        cout << bt[i][0];
        srep(j, 1, n-1) {
            cout << a[i][j];
        }
        cout << bt[i][1] << endl;
    }
    rep(i, n) {
        cout << by[1][i];
    }
    cout << endl;
}
