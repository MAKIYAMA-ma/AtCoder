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

    string s;
    cin >> s;
    Def(n);

    // nのほうがビット数多ければ全て1が正解
    // nの方がビット数が少なければ、あふれた部分がすべて？ならこの部分をカット
    // そうでなければ常にNG
    //
    // 後は上位から比べた際にs=1, n=0があったらNG
    // s=0, n=1があったら以降は全て?->1
    // s=?, n=0があったら?->0で続行
    // s=?, n=1があったら微妙。以降で小さくできるならここは1にしたい

    vector<char> nb;
    while(n > 0) {
        if(n % 2) {
            nb.push_back('1');
        } else {
            nb.push_back('0');
        }
        n /= 2;
    }
    vector<char> ns;
    rep(i, s.length()) {
        ns.push_back(s[i]);
    }
    reverse(all(ns));

    ll df = nb.size()-ns.size();
    if(df > 0) {
        rep(i, df) ns.push_back('0');
    } else if(df < 0){
        rep(i, -df) nb.push_back('0');
    }

    ll mn{MAXLL};
    rep(i, nb.size()) {
        if(ns[i] != '1' && nb[i] == '1') {
            mn = i;
            break;
        }
    }

    /* cout << "---------" << endl; */
    /* rep(i, nb.size()) cout << nb[i]; */
    /* cout << endl; */
    /* cout << "---------" << endl; */
    /* rep(i, ns.size()) cout << ns[i]; */
    /* cout << endl; */
    /* cout << "---------" << endl; */

    bool clr{false};
    rrep(i, nb.size()) {
        if(ns[i] == '0' && nb[i] == '1') {
            clr = true;
        } else if(ns[i] == '1' && nb[i] == '0') {
            cout << -1 << endl;
            return 0;
        } else if(ns[i] == '?') {
            if(clr) {
                ns[i] = '1';
            } else {
                if(nb[i] == '0' || i <= mn) {
                    ns[i] = '0';
                } else {
                    ns[i] = '1';
                }
            }
        }
    }

    /* cout << "---------" << endl; */
    /* rep(i, ns.size()) cout << ns[i]; */
    /* cout << endl; */
    /* cout << "---------" << endl; */
    ll ans{0}, base{1};
    rep(i, ns.size()) {
        if(ns[i] == '1') ans += base;
        base *= 2;
    }
    cout << ans << endl;
}
