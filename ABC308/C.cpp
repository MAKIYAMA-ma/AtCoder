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

/**
 * @brief aとbの最大公約数を求める。
 * でもライブラリでgcdって関数あるけどね。
 *
 * @param a
 * @param b
 *
 * @return 
 */
ll GCD(ll a, ll b) {
    ll v1, v2;
    if(a > b) {
        v1 = a;
        v2 = b;
    } else {
        v1 = b;
        v2 = a;
    }

    return (v2 == 0) ? v1 : GCD(v2, v1 % v2);
}


/**
 * @brief aとbの最小公倍数を求める
 * でもライブラリでlcmって関数あるけどね。
 *
 * @param a
 * @param b
 *
 * @return 
 */
ll LCM(ll a, ll b) {
    return ((a / GCD(a, b)) * b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vector<pair<long double, ll>> pr(n);
    rep(i, n) {
        Def(a);
        Def(b);
        pr[i] = {(long double)a/(a+b), i};
    }
    sort(all(pr), [](const pair<long double, ll> &a, const pair<long double, ll> &b) {
                if(a.first == b.first) {
                    return a.second < b.second;
                } else {
                    return a.first > b.first;
                }
            });
    rep(i, n) cout << pr[i].second+1 << " ";
    cout << endl;
}
