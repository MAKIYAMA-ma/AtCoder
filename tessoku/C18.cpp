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

ll check(vl2 &dp, vl &a, ll l, ll r) {
    if(l < 0 || r >= dp.size() || l > r) return MAXLL;
    if(dp[l][r] < MAXLL) return dp[l][r];

    /* dp[l][r] = min({check(dp, a, l+1, r-1) + abs(a[l]-a[r]), */
    /*         check(dp, a, l+2, r) + abs(a[l]-a[l+1]), */
    /*         check(dp, a, l, r-2) + abs(a[r-1]-a[r]) */
    /*         }); */
    dp[l][r] = check(dp, a, l+1, r-1) + abs(a[l]-a[r]);
    rep(i, (r-l)/2) {
        dp[l][r] = min(dp[l][r], check(dp, a, l, l+2*i+1) + check(dp, a, l+2*(i+1), r));
    }
    /* cout << "DB:" << l << " " << r << " " << dp[l][r] << endl; */
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    DefA(a, 2*n);

    // 隣接する二要素を削除していく
    // 削除する二要素の差の絶対値の総和を最小化する
    // 1 <= n <= 200
    //
    // 操作回数はn回
    // 2個増えた場合の最低コストが2個少ないほうのコストから求まるかというとそうではないような
    // DPでは無理？？
    // 1 10は9コストだが、
    // 1 10 10 1 なら真ん中からとれば0になる

    vl2 dp(2*n, vl(2*n, MAXLL));
    rep(i, 2*n) {
        dp[i][i] = 0;
    }
    rep(i, 2*n-1) {
        dp[i][i+1] = abs(a[i] - a[i+1]);
    }
    cout << check(dp, a, 0, 2*n-1) << endl;
}
