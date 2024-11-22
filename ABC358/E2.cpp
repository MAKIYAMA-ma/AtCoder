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

    ll n = 26;
    Def(k);
    DefA(c, n);

    // DPっぽい匂いがする？
    // でも26文字全ての残り文字数を管理するのは無理がある
    // i文字目まで使用の場合、とかで何かできる？
    // Aのみ使用なら、min(k, c[0])種類作れる（幾つ並べるかしか選択余地なし）
    //
    // i文字目まででj文字を作るのDPなら？
    // i+1文字でj文字作るのは、i文字目でj-1文字作るやつから、i+1文字目の配置がj種類
    // 同様に、i文字でj-1文字作るやつから、i+1文字目の配置がj個から2個選ぶ組合せj(j-1)/2種類。。。って感じで計算できる
    vm2 dp(n, vm(k+1, 0));
    rep(i, min(c[0], k)+1) {
        dp[0][i] = 1;
    }
    rep(i, n) {
        dp[i][0] = 1;
    }
    vm fact(k+1);
    fact[0] = 1;
    srep(i, 1, k+1) {
        fact[i] = fact[i-1]*i;
    }
    // O(26 * k * c)
    srep(i, 1, n) {
        srep(j, 1, k+1) {
            dp[i][j] = dp[i-1][j];
            srep(l, 1, min(j, c[i])+1) {
#if 1
                dp[i][j] += (dp[i-1][j-l] * fact[j] / (fact[j-l] * fact[l]));
#else
                // これだと処理時間が倍増してTLE
                // mintは、割り算にことのほか弱いのかもしれない。
                dp[i][j] += (dp[i-1][j-l] * fact[j] / fact[j-l] / fact[l]);
#endif
            }
        }
    }
    mint ans = 0;
    srep(i, 1, k+1) {
        ans += dp[n-1][i];
    }
    cout << ans.val() << endl;
}
