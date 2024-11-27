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

mint Pow(mint x, ll n) {
    mint ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(k);
    DefA(a, n);
    // 2 ≤ N ≤ 100000
    // 1 ≤ K ≤ 10^9
    // 1 ≤ Ai
    // ΣA <= 10^9
    // ボーダーとなる「票数÷議席数」の値は1 を超え10^9未満である
    // ボーダーとなる「票数÷議席数」と、次点の「票数÷議席数」の相対誤差は10^−6を超える
    //
    // 真面目にK個選ぶとTLE
    // 後二つの制約がポイントなのだろうが。。。
    // 要は各党についてボーダーを知りたい
    // -> ボーダーの票数を2分探索する。
    double l{0}, r{1000000001};
    while((r-l) > 0.000001) {
        double m = (l+r)/2;
        ll ans{0};
        rep(i, n) {
            ans += (ll)(a[i]/m);
        }
        if(ans >= k) {
            l = m;
        } else {
            r = m;
        }
    }
    rep(i, n) {
        cout << (ll)(a[i]/l) << " ";
    }
    cout << endl;
}
