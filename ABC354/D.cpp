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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;
#define Def(n) ll n; cin >> n;

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

    Def(a);
    Def(b);
    Def(c);
    Def(d);

    // 繰り返される領域の、各マスの黒面積*2
    vi2 size = {
        {2, 1, 0, 1},
        {1, 2, 1, 0}
    };

    ll h = (d-b);
    ll w = (c-a);
    ll rw = w % 4;

    // 横4マス他になら、倍面積は一段につき4
    ll ans = ((w/4) * 4 * h);

    // 始点が、8マス単位の繰り返し領域のどのポジションか
    ll sx = ((a % 4) + 4) % 4;
    ll sy = ((b % 2) + 2) % 2;
    ll ols = 0; // 横が4マスに満たない端数領域について、始点から奇数段目の倍面積
    ll els = 0; // 横が4マスに満たない端数領域について、始点から偶数段目の倍面積
    rep(i, rw) {
        ols += size[sy][(sx + i)%4];
        els += size[(sy+1)%2][(sx + i)%4];
    }
    ans += (ols + els) * (h/2);
    // 指定の領域が奇数段なら、奇数段目の面積を一段ぶん追加
    if(h % 2) {
        ans += ols;
    }

    cout << ans << endl;
}
