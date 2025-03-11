#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 0
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

    Def(n);
    Def(m);
    // 一人目から順に決めると、m*(m-1)*...*(m-1)の選択肢があるはず
    // 最後の一人は、n-1人目が1人目と同じかどうかで扱いが変わる。
    // n, m <= 10^6
    // なんか計算できる？　DP？
    // DPだとO(nm)では当然TLEする
#if 1
    vm dp(2, 0);
    vm pdp(2, 0);
    // 最初1として、1になる個数と1でない個数をDPで数える
    // 最初が1~mのパターンがあるのでm倍したら解
    dp[1] = 1;
    rep(i, n-1) {
        swap(dp, pdp);
        dp[0] = pdp[0]*(m-2) + pdp[1]*(m-1);
        dp[1] = pdp[0];
    }
    cout << (dp[0]*m).val() << endl;
#else
    vm2 dp(n, vm(2, 0));
    dp[0][1] = 1;
    srep(i, 1, n) {
        dp[i][0] = dp[i-1][0]*(m-2) + dp[i-1][1]*(m-1);
        dp[i][1] = dp[i-1][0];
    }
    mint ans = dp[n-1][0]*m;
    cout << ans.val() << endl;
#endif
}
