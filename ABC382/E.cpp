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
#define Def2A(a, b, n) vl a(n); rep(i, n) cin >> a[i] >> b[i];
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

double NormalApproximation(const vd& pro, int n) {
    // 期待値 (μ) と分散 (σ^2) を計算
    double mean = 0.0, var = 0.0;
    for (double p : pro) {
        mean += p;
        var += p * (1 - p);
    }
    double sigma = sqrt(var); // 標準偏差

    // 正規分布の近似
    double normalization = 1.0 / (sqrt(2 * M_PI) * sigma); // 正規化係数
    double exponent = -pow(n - mean, 2) / (2 * var);  // 指数部分
    return normalization * exp(exponent);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(x);
    DefA(p, n);

    // 1パックに入っているレアの枚数の期待値はPiの総和ではないの？
    // 50%と100%なら、1パック当たり1.5枚
    // 1枚当たり1/1.5パック必要
    // よって2枚ほしいなら2/1.5=1.33333パック必要ということ
    // 超える分の補正は。。。？
    vd per(n);
    rep(i, n) {
        per[i] = (double)100 / p[i];
    }
    vd pos(n);
    rep(i, n) {
        pos[i] = NormalApproximation(per, i);
    }
}
