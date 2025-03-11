#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 0
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
    Def(k);
    Def(q);
    // k <= n <= 5*10^5
    // q <= 5*10^5
    // 上位k個の総和を管理し続けたい
    // sortはO(nlogn)だから毎回ソートしたらO(qnlogn)になってTLE

    multiset<ll> bg, sm;
    ll ans{0};
    vl a(n, 0);
    rep(i, k) bg.insert(0);
    rep(i, n-k) sm.insert(0);

    rep(i, q) {
        Def(x);
        Def(y);
        x--;

        if(bg.size() > 0 && *bg.begin() <= a[x]) {
            auto lp = bg.find(a[x]);
            bg.erase(lp);
            ans -= a[x];
        } else if(sm.size() > 0){
            auto lp = sm.find(a[x]);
            sm.erase(lp);
        }
        a[x] = y;
        if((bg.size() > 0 && *bg.begin() <= a[x]) || (sm.size() > 0 && *sm.rbegin() < a[x])) {
            bg.insert(a[x]);
            ans += a[x];
        } else {
            sm.insert(a[x]);
        }

        if(bg.size() > k) {
            ll bg_smst = *bg.begin();
            ans -= bg_smst;
            bg.erase(bg.begin());
            sm.insert(bg_smst);
        } else if (bg.size() < k) {
            ll sm_bgst = *sm.rbegin();
            sm.erase(prev(sm.rbegin().base()));
            bg.insert(sm_bgst);
            ans += sm_bgst;
        }
        /* cout << "DB:("; */
        /* for(auto v : bg) cout << v << ","; */
        /* cout << ")("; */
        /* for(auto v : sm) cout << v << ","; */
        /* cout << ")" << endl; */
        cout << ans << endl;
    }
}
