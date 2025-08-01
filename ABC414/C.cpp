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

using sl = set<ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;
using vs = vector<string>;
using vsl = vector<sl>;

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
#define Def2(m, n) ll m, n; cin >> m >> n;
#define Def3(l, m, n) ll l, m, n; cin >> l >> m >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define Def3A(a, b, c, n) vl a(n); vl b(n); vl c(n); rep(i, n) cin >> a[i] >> b[i] >> c[i];
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

string to_base(ll n, ll b) {
    if (n == 0) return "0";
    string digits = "0123456789";
    string result;

    while (n > 0) {
        result += digits[n % b];
        n /= b;
    }
    reverse(all(result));
    return result;
}

ll check(ll n, ll k, ll a, ll mx) {
    /* cout << "DB:" << n << endl; */
    if(mx < n) return 0;
    if(k >= 10000000000000) return 0;

    ll ans{0};
    /* cout << n << ":" << r << endl; */
    if(n%10) {
        string r = to_base(n, a);
        bool ok{true};
        rep(i, r.length()/2) {
            if(r[i] != r[r.length()-1-i]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ans += n;
            /* cout << "DB:" << n << endl; */
        }
    }

    rep(i, 10) {
        ans += check((n+i*k)*10+i, k*100, a, mx);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(a, n);
    // a <= 9
    // n <= 10^12
    ll ans{0};
    rep(i, 10) {
        ans += check(i, 10, a, n);
        ans += check(i*10+i, 100, a, n);
    }
    cout << ans << endl;
}
