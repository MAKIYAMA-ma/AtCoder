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

    string s, t;
    cin >> s >> t;

    vi2 dp(s.length(), vi(t.length(), 0));
    rep(i, s.length()) {
        rep(j, t.length()) {
            int pre = 0;
            if(i > 0 && j > 0) {
                pre = dp[i-1][j-1];
            }
            dp[i][j] = max(pre + (s[i] == t[j] ? 1 : 0), max((i > 0) ? dp[i-1][j] : 0, (j > 0) ? dp[i][j-1] : 0));
        }
    }

    cout << "------------" << endl;
    rep(i, s.length()) {
        rep(j, t.length()) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "------------" << endl;

    vector<char> ans;
    int si = s.length()-1;
    int ti = t.length()-1;
    int len = dp[si][ti];

    while(len > 0) {
        while(ti > 0 && dp[si][ti] == dp[si][ti-1]) {
            ti--;
        }
        while(si > 0 && dp[si][ti] == dp[si-1][ti]) {
            si--;
        }
        ans.push_back(s[si]);
        if(si == 0 || ti == 0) {
            break;
        } else {
            len--;
            si--;
            ti--;
        }
    }

    rrep(i, ans.size()) {
        cout << ans[i];
    }
    cout << endl;
}
