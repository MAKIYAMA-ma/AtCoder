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


ll Pow(ll x, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}


void make(vector<vector<char>> &cpt, int sx, int sy, int lvl) {
    if(lvl == 0) {
        cpt[sx][sy] = '#';
    } else {
        int blksz = Pow(3, lvl-1);
        make(cpt, sx, sy, lvl-1);
        make(cpt, sx + blksz, sy, lvl-1);
        make(cpt, sx + blksz*2, sy, lvl-1);
        make(cpt, sx, sy + blksz, lvl-1);
        make(cpt, sx + blksz*2, sy + blksz, lvl-1);
        make(cpt, sx, sy + blksz*2, lvl-1);
        make(cpt, sx + blksz, sy + blksz*2, lvl-1);
        make(cpt, sx + blksz*2, sy + blksz*2, lvl-1);
        rep(i, blksz) {
            rep(j, blksz) {
                cpt[sx+blksz+i][sy+blksz+j] = '.';
            }
        }
    }
}


int main() {
    int n;
    cin >> n;

    ll sz = Pow(3, n);

    vector<vector<char>> cpt(sz, vector<char>(sz, ' '));
    make(cpt, 0, 0, n);
    rep(i, sz) {
        rep(j, sz) {
            cout << cpt[i][j];
        }
        cout << endl;
    }
}
