#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;

#if 0
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
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


ll check(string s, int l, int r, vl2 &dp) {
    if(dp[l][r] >= 0) return dp[l][r];
    if(l == r) {
        dp[l][r] = 1;
    } else if(r - l == 1) {
        dp[l][r] = ((s[l] == s[r]) ? 2 : 1);
    } else {
        dp[l][r] = max({(s[l] == s[r]) ? (check(s, l+1, r-1, dp) + 2) : 0,
                check(s, l+1, r, dp), check(s, l, r-1, dp)});
    }
    return dp[l][r];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vi a(n, 0), b(n, 0);
    rep(i, n-1) cin >> a[i+1];
    rep(i, n-1) cin >> b[i+1];

    // 0初期化だと、そもそもスタートから遷移できないマスからの移動が採用される恐れがある
    vl dp(n+1, MINLL);
    dp[1] = 0;
    srep(i, 1, n) {
        dp[a[i]] = max(dp[a[i]], dp[i] + 100);
        dp[b[i]] = max(dp[b[i]], dp[i] + 150);
    }
    cout << dp[n] << endl;
}
