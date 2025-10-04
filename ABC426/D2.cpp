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

    Def(t);
    rep(i, t) {
        Def(n);
        string s;
        cin >> s;

        // それまでに登場した最後の1までの0の数
        // それまでに登場した最後に0までの1の数

        vl2 cnt(n, vl(2, 0));
        map<ll, ll> mp;
        mp[s[0]-'0']++;
        cnt[0][1-(s[0]-'0')] = 1;
        srep(j, 1, n) {
            ll tgt = s[j]-'0';
            mp[tgt]++;
            cnt[j][tgt] = cnt[j-1][tgt];
            cnt[j][1-tgt] = mp[1-tgt]*2+mp[tgt];
            /* cout << "P:" << cnt[j][0] << "," << cnt[j][1] << endl; */
        }

        vl2 rcnt(n, vl(2, 0));
        map<ll, ll> rmp;
        rmp[s[n-1]-'0']++;
        rcnt[n-1][1-(s[n-1]-'0')] = 1;
        for(ll j = n-2; j >= 0; j--) {
            ll tgt = s[j]-'0';
            rmp[tgt]++;
            rcnt[j][tgt] = rcnt[j+1][tgt];
            rcnt[j][1-tgt] = rmp[1-tgt]*2+rmp[tgt];
            /* cout << "R:" << rcnt[j][0] << "," << rcnt[j][1] << endl; */
        }

        ll ans{MAXLL};
        rep(j, n) {
            /* cout << cnt[j][0] << "+" << rcnt[j][0] << "  :  " << cnt[j][1] << "+" << rcnt[j][1] << endl; */
            ans = min({ans, cnt[j][0]+rcnt[j][0], cnt[j][1]+rcnt[j][1]});
        }
        cout << ans << endl;
    }
}
