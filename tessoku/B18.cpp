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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;

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

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, s;
    cin >> n >> s;
    vl a(n+1, 0);
    rep(i, n) cin >> a[i+1];

    vb2 dp(n+1, vb(s+1, false));
    dp[0][0] = true;
    srep(i, 1, n+1) {
        rep(j, s+1) {
            dp[i][j] = dp[i-1][j] || ((j >= a[i]) ? dp[i-1][j-a[i]] : false);
        }
    }

    if(dp[n][s]) {
        vl ans;
        ll sum = s;
        rrep(i, n) {
            if(sum >= a[i+1] && dp[i][sum - a[i+1]]) {
                ans.push_back(i+1);
                sum -= a[i+1];
                if(sum == 0) break;
            }
        }

        cout << ans.size() << endl;
        rrep(i, ans.size()) {
            cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
