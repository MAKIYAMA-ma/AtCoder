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

    int n, W;
    cin >> n >> W;

    vl w(n+1, 0);
    vl v(n+1, 0);
    rep(i, n) cin >> w[i+1] >> v[i+1];

    ll MAXV = 100 * 1000;
    vl2 dp(n+1, vl(MAXV+1, MAXLL));
    dp[0][0] = 0;
    srep(i, 1, n+1) {
        rep(j, MAXV+1) {
            dp[i][j] = min(dp[i-1][j], ((j >= v[i]) ? dp[i-1][j-v[i]] : 0) + w[i]);
        }
    }
    /* cout << "------------" << endl; */
    /* rep(i, n+1) { */
    /*     /1* rep(j, MAXV+1) { *1/ */
    /*     rep(j, 100) { */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "------------" << endl; */
    auto up = upper_bound(all(dp[n]), W);
    if(up != dp[n].begin()) up--;
    cout << up - dp[n].begin() << endl;
}
