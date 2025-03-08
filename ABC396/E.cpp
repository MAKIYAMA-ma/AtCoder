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
    Def(m);
    vl x(m), y(m), z(m);
    rep(i, m) cin >> x[i] >> y[i] >> z[i];

    vpl zo(m);
    rep(i, m) {
        zo[i].first = z[i];
        zo[i].second = i;
    }
    sort(all(zo));

    vl a(n, -1);
    rep(i, m) {
        cout << "DB:" << zo[i].second << endl;
        ll xi = x[zo[i].second]-1;
        ll yi = y[zo[i].second]-1;
        ll zi = z[zo[i].second];

#if 1
        if(a[xi] != -1 && a[yi] != -1) {
            if((a[xi]^a[yi]) != zi) {
                cout << -1 << endl;
                return 0;
            }
        } else if(a[xi] != -1) {
            a[yi] = zi^a[xi];
        } else if(a[yi] != -1) {
            a[xi] = zi^a[yi];
        } else {
            a[xi] = 0;
            a[yi] = zi;
        }
#else
        if(a[xi] == -1) {
            a[xi] = 0;
        }
        ll v = zi^a[xi];
        if(a[yi] != -1 && a[yi] != v) {
            cout << -1 << endl;
            return 0;
        }
        a[yi] = v;
#endif
        rep(i, n) {
            cout << a[i] << " ";
        }
    }
    rep(i, n) {
        cout << a[i] << " ";
    }
    cout << endl;
}
