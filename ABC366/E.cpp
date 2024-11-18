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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(d);
    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    // 全てのx,yから、水平垂直の距離の和がD以下である点の個数
    // 各x,y を中心に、対角線が2Dの正方形がダイヤ型に形成されるはず。
    // そのすべてのダイヤの共通部分に含まれる格子点の数が知りたいということ。
    // ----> 違う！！！全てのx,yからの距離の和なので、対角2Dのダイヤではない！！！
    //
    // 範囲に影響するのは最大四つ
    // どれが影響する点か、計算で求まりそうな気もする
    //
    // x+yが最大の点の左下辺
    // x+yが最小の点の右上辺
    // y-xが最大の点の右下辺
    // y-xが最小の点の左上辺
    // のみ考慮すればよいはず
    vpl xpy(n), ymx(n);
    rep(i, n) {
        xpy[i].first = x[i] + y[i];
        xpy[i].second = i;

        ymx[i].first = y[i] - x[i];
        ymx[i].second = i;
    }
    auto ldl = max_element(all(xpy)) - xpy.begin();
    auto rul = min_element(all(xpy)) - xpy.begin();
    auto rdl = max_element(all(ymx)) - ymx.begin();
    auto lul = min_element(all(ymx)) - ymx.begin();

    cout << "ldl : " << ldl << endl;
    cout << "lul : " << lul << endl;
    cout << "rdl : " << rdl << endl;
    cout << "rul : " << rul << endl;

    auto lx = y[ldl] + x[ldl] - y[lul] + x[lul] - 4*d;
    if(lx > 0) lx++;
    lx /= 2;

    auto rx = y[rul] + x[rul] - y[rdl] + x[rdl] * 4*d;
    if(rx < 0) rx--;
    rx /= 2;

    ll ans{0};
    for(int i = lx; i <= rx; i++) {
        auto ymax = min(i + y[lul] - x[lul] + 2*d, -i + y[rul] + x[rul] + 2*d);
        auto ymin = max(-i + y[ldl] + x[ldl] - 2*d, i + y[rdl] + x[rdl] - 2*d);
        cout << "DB:" << i << " " << (ymax - ymin + 1) << endl;
        ans += (ymax - ymin + 1);
    }
    cout << ans << endl;
}
