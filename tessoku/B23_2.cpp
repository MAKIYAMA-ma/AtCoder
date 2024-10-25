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

double check(vd2 &dist, int pos, int path, vd2 &dp) {
    if(dp[pos][path] >= 0) return dp[pos][path];
    if(__builtin_popcount(path) == 1) {
        if(pos == 0) {
            dp[pos][path] = 0.0;
        } else {
            dp[pos][path] = MAXLD;
        }
        return dp[pos][path];
    }
    dp[pos][path] = MAXLD;
    rep(i, dist.size()) {
        int prepath = (path & ~(1<<pos));
        if(prepath & (1 << i)) {
            double tmp = check(dist, i, prepath, dp) + dist[pos][i];
            dp[pos][path] = min(dp[pos][path], tmp);
            /* cout << "DB:" << pos << ":" << path << ":" << tmp << endl; */
        }
    }
    return dp[pos][path];
}

int main() {
    int n;
    cin >> n;

    vi x(n, 0), y(n, 0);
    rep(i, n) cin >> x[i] >> y[i];

    vd2 dist(n, vd(1 << n, 0));
    rep(i, n) {
        rep(j, n) {
            if(i < j) {
                dist[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
                dist[j][i] = dist[i][j];
            }
        }
    }

    vd2 dp(n, vd(1 << n, -1));
    dp[0][0x01] = 0.0;

    double ans = MAXLD;
    srep(i, 1, n) {
        ans = min(check(dist, i, (1<<n)-1, dp) + dist[0][i], ans);
    }
    /* rep(i, n) { */
    /*     rep(j, 1 << n) { */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    PrintD(ans);
}
