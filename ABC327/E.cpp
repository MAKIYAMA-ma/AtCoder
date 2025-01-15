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

    Def(n);
    DefA(p, n);

    vector<float> dv(n+1, 1.0);
    vector<float> dva(n+1, 1.0);
    srep(i, 1, dv.size()) {
        dv[i] = dv[i-1]*0.9;
        dva[i] = dva[i-1]+dv[i];
    }

    vector<vector<float>> dp(n, vector<float>(n+1, 0.0));
    float ans{-1.0e30};

#if 1
    dp[0][1] = p[0];
    srep(i, 1, n) {
        srep(j, 1, i+1+1) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]*0.9F + p[i]);
        }
    }
    rep(k, n+1) {
        float vl = dp[n-1][k]/dva[k-1] - (1200/sqrt(k));
        ans = max(ans, vl);
    }
#elif 1
    // TLE -> WA
    // になっただけだった
    // 誤差が大きい？
    dp[0][1] = dv[n-1]*p[0];
    srep(i, 1, n) {
        srep(j, 1, i+1+1) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + dv[n-j]*p[i]);
        }
    }
    rep(k, n+1) {
        float vl = (dp[n-1][k]/dv[n-k])/dva[k-1] - (1200/sqrt(k));
        ans = max(ans, vl);
    }
#else
    // 各kについて、1~nまでの値を何番目に採用するか。。。
    // -> O(n^3)では？
    // n <= 5000
    // だからTLEでは。
    // 実際にはその数分の1だが。。。
    srep(k, 1, n+1) {
        rep(i, dp.size()) fill(all(dp[i]), 0);
        dp[0][1] = dv[k-1]*p[0];
        srep(i, 1, n) {
            srep(j, 1, min(i+1, k)+1) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + dv[k-j]*p[i]);
            }
        }
        float vl = max(dp[n-1][k], ans)/dva[k-1] - (1200/sqrt(k));
        ans = max(ans, vl);
    }
#endif
    PrintD(ans);
}
