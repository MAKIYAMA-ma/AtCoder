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

    Def(r);
    Def(c);
    Def(sy);
    Def(sx);
    Def(gy);
    Def(gx);
    sy--; sx--;
    gy--; gx--;
    vector<string> map(r);
    rep(i, r) {
        cin >> map[i];
    }
    vl2 cost(r, vl(c, MAXI));
    cost[sy][sx] = 0;
    queue<pi> q;
    q.push(make_pair(sy, sx));
    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    while(!q.empty()) {
        auto nxt = q.front();
        q.pop();
        if(nxt.first == gy && nxt.second == gx) break;
        auto nv = cost[nxt.first][nxt.second] + 1;
        rep(i, 4) {
            auto ny = nxt.first + dy[i];
            auto nx = nxt.second + dx[i];
            if(ny >= 0 && ny < r && nx >= 0 && nx < c && map[ny][nx] == '.' && nv < cost[ny][nx]) {
                cost[ny][nx] = nv;
                q.push(make_pair(ny, nx));
            }
        }
    }
    cout << cost[gy][gx] << endl;
}
