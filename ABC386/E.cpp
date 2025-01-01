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

ll lst(ll idx, set<ll> &l, ll tl, vl &a) {
    /* cout << "DB:" << idx << " " << l.size() << " " << tl << endl; */
    if(l.size() == tl) {
        ll ans{0};
        for(auto t : l) {
            /* cout << "  DB2:" << t << endl; */
            ans ^= a[t];
            /* cout << "  DB3:" << ans << endl; */
        }
        /* cout << "  DB4:" << ans << endl; */
        return ans;
    }
    if(idx < a.size() && l.size() < tl) {
        auto l1 =  lst(idx+1, l, tl, a);
        l.insert(idx);
        auto l2 =  lst(idx+1, l, tl, a);
        l.erase(--l.end());
        return max(l1, l2);
    } else {
        return MINLL;
    }
}

ll lst_m(ll idx, set<ll> &l, ll tl, vl &a, ll ttl) {
    /* cout << "DB:" << idx << " " << l.size() << " " << tl << endl; */
    if(l.size() == tl) {
        ll ans{0};
        for(auto t : l) {
            /* cout << "  DB2:" << t << endl; */
            ans ^= a[t];
            /* cout << "  DB3:" << ans << endl; */
        }
        /* cout << "  DB4:" << (ans ^ ttl) << endl; */
        return ans ^ ttl;
    }
    if(idx < a.size() && l.size() < tl) {
        auto l1 =  lst_m(idx+1, l, tl, a, ttl);
        l.insert(idx);
        auto l2 =  lst_m(idx+1, l, tl, a, ttl);
        l.erase(--l.end());
        return max(l1, l2);
    } else {
        return MINLL;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(k);
    DefA(a, n);
    sort(all(a));

    // なるべく上のビットが1になるk個が最善
    // -> なるべく上位ビットで1を奇数個にしたい
    //
    // 困ったらDP？
    // Aiを使って上からjビット考慮した場合の最大。。。
    // 無理があるような
    set<ll> l;
    if(k < n/2) {
        cout << lst(0, l, k, a) << endl;
    } else {
        ll ttl{0};
        for(auto ai : a) {
            ttl ^= ai;
        }
        cout << lst_m(0, l, n-k, a, ttl) << endl;
    }
}
