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
    int h, w;
    cin >> h >> w;

    int sx, sy;
    cin >> sy >> sx;
    sy--;
    sx--;

    vector<vector<bool>> c(h, vector<bool>(w, false));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if(s[j] == '.') {
                c[i][j] = true;
            }
        }
    }

    string x;
    cin >> x;
    vector dx = {-1, 1, 0, 0};
    vector dy = {0, 0, -1, 1};
    rep(i, x.length()) {
        /* cout << "DB:" << sy << " " << sx << endl; */
        int dir = 0;
        switch(x[i]) {
            case 'L': dir = 0; break;
            case 'R': dir = 1; break;
            case 'U': dir = 2; break;
            case 'D': dir = 3; break;
        }
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
        if((nx < 0) || (ny < 0) || (nx >= w) || (ny >= h)) {
            continue;
        }
        if(!c[ny][nx]) {
            continue;
        }
        sx = nx;
        sy = ny;
    }
    cout << sy+1 << " " << sx+1 << endl;
}
