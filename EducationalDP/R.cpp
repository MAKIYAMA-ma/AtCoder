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

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

/**
 * @brief 行列の積
 *
 * @param x
 * @param y
 *
 * @return 
 */
vector<vector<mint>> MultiArray(vector<vector<mint>> &x, vector<vector<mint>> &y) {
    vector<vector<mint>> ans(x.size(), vector<mint>(y[0].size(), 0));
    rep(i, x.size()) {
        rep(j, y[0].size()) {
            rep(k, x[0].size()) {
                ans[i][j] += (x[i][k] * y[k][j]);
            }
        }
    }
    return ans;
}

/**
 * @brief 行列の累乗
 *
 * @param x
 * @param n
 *
 * @return 
 */
vector<vector<mint>> PowArray(vector<vector<mint>> &x, ll n) {
    vector<vector<mint>> ans(x.size(), vector<mint>(x.size(), 0));
    rep(i, x.size()) {
        ans[i][i] = 1;
    }

    while(n > 0) {
        if(n % 2) {
            ans = MultiArray(ans, x);
        }
        x = MultiArray(x, x);
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, k;
    cin >> n >> k;
    // 1 ≤ N ≤ 50
    // 1 ≤ K ≤ 10^18

    vector<vector<mint>> a(n, vector<mint>(n, 0));
    rep(i, n) {
        rep(j, n) {
            int tmp;
            cin >> tmp;
            a[i][j] = tmp;
        }
    }

    // 点iから始まる長さjの有効パスの数、とかいう管理は不可。Kが大きすぎる。
    // てか普通にO(N)でKまでインクリしていくことすら不可
    // サイクルの個数や分岐とかから計算する必要がある？？？
    // でもそれじゃDPじゃないな

    // --> 行列演算で求められる。
    // aは、iからjに長さ1で到達できるパス数の行列
    // a^2とすると、
    // iからjに長さ2で到達できるパス数の行列になる。
    vector<vector<mint>> kpath = PowArray(a, k);
    mint ans = 0;
    rep(i, kpath.size()) {
        rep(j, kpath[0].size()) {
            ans += kpath[i][j];
        }
    }
    cout << ans.val() << endl;
}
