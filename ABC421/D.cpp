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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(rt, ct);
    Def2(ra, ca);
    Def3(n, m, l);

    vpl sa(m), tb(l);
    rep(i, m) {
        char s;
        cin >> s >> sa[i].second;
        switch(s) {
            case 'U': sa[i].first = 0; break;
            case 'D': sa[i].first = 1; break;
            case 'L': sa[i].first = 2; break;
            case 'R': sa[i].first = 3; break;
        }
    }
    rep(i, l) {
        char s;
        cin >> s >> tb[i].second;
        switch(s) {
            case 'U': tb[i].first = 0; break;
            case 'D': tb[i].first = 1; break;
            case 'L': tb[i].first = 2; break;
            case 'R': tb[i].first = 3; break;
        }
    }

    ll ans{0};
    ll pr = ra-rt;
    ll pc = ca-ct;
    vl dsr = {1, -1, 0, 0};
    vl dsc = {0, 0, 1, -1};
    vl dtr = {-1, 1, 0, 0};
    vl dtc = {0, 0, -1, 1};

    ll si{0}, ti{0};
    while(si < sa.size() && ti < tb.size()) {
        ll nm = min(sa[si].second, tb[ti].second);
        ll dr = dsr[sa[si].first] + dtr[tb[ti].first];
        ll dc = dsc[sa[si].first] + dtc[tb[ti].first];

        /* cout << "DB0:" << pr << "," << pc << endl; */
        /* cout << "DB1:" << dr << "," << dc << ":" << nm << endl; */

        if((pr && !dr) || (pc && !dc) || (!pr && dr) || (!pc && dc)
                || ((dr%2 == 0) && (pr%2 != 0))
                || ((dc%2 == 0) && (pc%2 != 0))) {
        } else if(pr == 0 && pc == 0 && dr == 0 && dc == 0) {
            ans += nm;
        } else {
            ll dfr{0}, dfc{0};
            if(dr) dfr = -pr/dr;
            if(dc) dfc = -pc/dc;
            /* cout << "DB2:" << dfr << "," << dfc << endl; */
            if((dfr < 0) || (dfc < 0)) {
            } else if((dfr == dfc) && (dfr <= nm)) {
                ans++;
            } else if ((((pr == 0) && (dfc <= nm))) || ((pc == 0) && (dfr <= nm))) {
                ans++;
            }
        }
        pr += nm*dr;
        pc += nm*dc;
        sa[si].second -= nm;
        if(sa[si].second == 0) si++;
        tb[ti].second -= nm;
        if(tb[ti].second == 0) ti++;
    }
    cout<< ans << endl;
}
