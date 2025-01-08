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

ll check(vl2 &flu, ll a, ll b) {
    ll ans{0};
    ll n = flu.size();

    if(a < 0 || b < 0) return 0;

    ans += (a/n)*(b/n)*flu[n-1][n-1];
    ans += (b/n)*flu[a%n][n-1];
    ans += (a/n)*flu[n-1][b%n];
    ans += flu[a%n][b%n];

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(q);
    vs p(n);
    rep(i, n) cin >> p[i];

    // 左上からの累積を計算
    vl2 flu(n, vl(n, 0));
    rep(i, n) {
        flu[i][0] = ((p[i][0] == 'B') ? 1 : 0);
        srep(j, 1, n) {
            flu[i][j] = flu[i][j-1]+((p[i][j] == 'B') ? 1 : 0);
        }
    }
    srep(i, 1, n) {
        rep(j, n) {
            flu[i][j] += flu[i-1][j];
        }
    }

    /* rep(i, n) { */
    /*     rep(j, n) { */
    /*         cout << flu[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    rep(i, q) {
        Def(a);
        Def(b);
        Def(c);
        Def(d);

        ll ans = check(flu, c, d) - check(flu, c, b-1) - check(flu, a-1, d) + check(flu, a-1, b-1);
        cout << ans << endl;
    }
}
