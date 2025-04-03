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

pl check(string &a, ll k, ll ps) {
    if(k == 0) {
        return {a[ps-1]-'0', 1};
    } else {
        auto p1 = check(a, k-1, ps*3-2);
        auto p2 = check(a, k-1, ps*3-1);
        auto p3 = check(a, k-1, ps*3);
        /* cout << k-1 << " " << ps*3-2 << " (" << p1.first << "," << p1.second << ")" << endl; */
        /* cout << k-1 << " " << ps*3-1 << " (" << p2.first << "," << p2.second << ")" << endl; */
        /* cout << k-1 << " " << ps*3 << " (" << p3.first << "," << p3.second << ")" << endl; */
        if((p1.first == p2.first) && (p2.first == p3.first)) {
            ll tp = (p1.second+p2.second+p3.second) - max({p1.second, p2.second, p3.second});
            return {p1.first, tp};
        } else if(p1.first == p2.first) {
            return {p1.first, min(p1.second,p2.second)};
        } else if(p2.first == p3.first) {
            return {p2.first, min(p2.second,p3.second)};
        } else if(p3.first == p1.first) {
            return {p1.first, min(p1.second,p3.second)};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    string a;
    cin >> a;
    // n <= 13
    // -> 3^n <= 1.6*10^6
    // 010011101
    // 011
    // 1
    // -> 011 or 101を0にする
    // 000000000
    // 000
    // 0
    // -> 4つ変更必要
    cout << check(a, n, 1).second << endl;
}
