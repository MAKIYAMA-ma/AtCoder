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

    Def2A(x, y, 3);

    // (1) 荷物の移動距離
    // (2) 移動方向の逆側に回り込むまでの距離（近いほう）
    // (3) XY両方向移動必要なら、回り込む距離(+2)
    //
    // 荷物のXY軸それぞれの移動方向
    ll xd{0}, yd{0};
    if(x[2] > x[1]) xd = 1;
    else if (x[2] < x[1]) xd = -1;
    if(y[2] > y[1]) yd = 1;
    else if (y[2] < y[1]) yd = -1;

    ll ans{0};
    // 荷物を移動させるための位置への移動距離
    vl d = {abs(x[1]-xd - x[0]) + abs(y[1] - y[0]), abs(x[1] - x[0]) + abs(y[1]-yd - y[0])};
    if(xd == 0) {
        ans += d[1];
        if(x[0] == x[1] && ((y[1]-y[0])*(-yd) > 0)) {
            // 初期位置に移動するのに、荷物を回り込む必要がある
            ans += 2;
        }
    } else if(yd == 0) {
        ans += d[0];
        if(y[0] == y[1] && ((x[1]-x[0])*(-xd) > 0)) {
            // 初期位置に移動するのに、荷物を回り込む必要がある
            ans += 2;
        }
    } else {
        // 移動位置の近いほうに最初に行き、移動後に他方の軸の移動を行うために2歩歩いて回り込む
        ans += min(d[0], d[1])+2;
    }
    // 荷物の移動距離
    ans += (abs(x[2] - x[1]) + abs(y[2] - y[1]));

    cout  << ans << endl;
}
