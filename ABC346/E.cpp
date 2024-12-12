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

    Def(h);
    Def(w);
    Def(m);

    vl t(m), a(m), x(m);
    rep(i, m) cin >> t[i] >> a[i] >> x[i];
    // 同じ行/列に対して複数指示があれば、最後のみ考慮すればOK
    //
    // 指示を後から処理？
    // 残っている行、列をsetで管理
    set<ll> t1, t2;
    rep(i, h) t1.insert(i+1);
    rep(i, w) t2.insert(i+1);

    map<ll, ll> cls;
    cls[0] = h*w;
    rrep(i, m) {
        if(t[i] == 1) {
            if(t1.find(a[i]) != t1.end()) {
                cls[x[i]] += t2.size();
                cls[0] -= t2.size();
                t1.erase(a[i]);
            }
        } else {
            if(t2.find(a[i]) != t2.end()) {
                cls[x[i]] += t1.size();
                cls[0] -= t1.size();
                t2.erase(a[i]);
            }
        }
    }
    auto it = cls.begin();
    while(it != cls.end()) {
        if((*it).second == 0) {
            it = cls.erase(it);
        } else {
            it++;
        }
    }
    cout << cls.size() << endl;
    for(auto c : cls) {
        cout << c.first << " " << c.second << endl;
    }
}
