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

ll PrimeFactNum(ll n) {
    sl prms;
    ll tmp = n;
    for(ll i = 2; i*i <= tmp; i++) {
        // iが素数かどうかの判定は不要
        // iが素数でないなら、iの約数による割り算がもっと前に完了している
        while(tmp % i == 0) {
            prms.insert(i);
            tmp /= i;
        }
    }
    if(tmp >= 2) prms.insert(tmp);
    return prms.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // aが素数の累乗の二乗の和である
    // -> aは二乗数
    // aの平方根が素数二つで構成される
    // a <= 10^12
    //
    Def(q);
    DefA(a, q);
    // aの最大値までの400numberを洗い出せないだろうか
    ll mx = *max_element(all(a));

    sl nm400;
    srep(i, 6, sqrt(mx)+1) {
        if(PrimeFactNum(i) == 2) nm400.insert(i*i);
    }

    rep(i, q) {
        // setに二分探索をする場合、メンバ関数を使うとO(logN)
        // しかし、upper_bound(all(nm400, a[i]))とするとO(N)になるらしい
        // 構造が双方向の連結だからみたい
        auto lp = nm400.upper_bound(a[i]);
        lp--;
        cout << *lp << endl;
    }
}
