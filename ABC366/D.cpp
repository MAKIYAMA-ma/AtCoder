#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
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
    int n;
    cin >> n;

    vector<vector<vector<ll>>> a(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
    rep(x, n) {
        rep(y, n) {
            rep(z, n) {
                cin >> a.at(x+1).at(y+1).at(z+1);
            }
        }
    }

    // (0,0,0)から(x,y,z)までの累積
    vector<vector<vector<ll>>> cum(n+1, vector<vector<ll>>(n+1, vector<ll>(n+1, 0)));
#if 0
    rep(x, n) {
        rep(y, n) {
            rep(z, n) {
                cum[x + 1][y + 1][z + 1] =
                    cum[x][y + 1][z + 1] + cum[x + 1][y][z + 1] + cum[x + 1][y + 1][z]
                    - cum[x][y][z + 1] - cum[x][y + 1][z] - cum[x + 1][y][z]
                    + cum[x][y][z]
                    + a[x + 1][y + 1][z + 1];
            }
        }
    }
#else
    // こっちのが個人的には直感的に分かりやすい
    // まずx方向に全部足し、それをy方向に累積し、更にz方向に累積する
    rep(y, n) {
        rep(z, n) {
            rep(x, n) {
                cum[x+1][y+1][z+1] = cum[x][y+1][z+1]+a[x+1][y+1][z+1];
            }
        }
    }
    rep(x, n) {
        rep(y, n) {
            rep(z, n) {
                cum[x+1][y+1][z+1] += cum[x+1][y][z+1];
            }
        }
    }
    rep(x, n) {
        rep(y, n) {
            rep(z, n) {
                cum[x+1][y+1][z+1] += cum[x+1][y+1][z];
            }
        }
    }
#endif
    /* cout << "-------" << endl; */
    /* rep(x, n) { */
    /*     rep(y, n) { */
    /*         rep(z, n) { */
    /*             cout << x+1 << ":" << y+1 << ":" << z+1 << ":" << cum[x+1][y+1][z+1] << " "; */
    /*         } */
    /*         cout <<endl; */
    /*     } */
    /* } */
    /* cout << "-------" << endl; */

    int q;
    cin >> q;
    rep(i, q) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        ll ans = cum[rx][ry][rz]
            - cum[lx-1][ry][rz] - cum[rx][ly-1][rz] - cum[rx][ry][lz-1]
            + cum[lx-1][ly-1][rz] + cum[rx][ly-1][lz-1] + cum[lx-1][ry][lz-1]
            - cum[lx-1][ly-1][lz-1];
        cout << ans << endl;
    }
}
