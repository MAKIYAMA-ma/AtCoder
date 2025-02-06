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

    Def(h);
    Def(w);
    // h, w <= 2000
    vs a(h);
    rep(i, h) cin >> a[i];

    // 通行可能なマスの地図を作って探索でいいはず
    // 問題は、4*10^6マスについて探索したあと、人を見つけた際に視線のマスを通行不可にしてく作業をすると、
    // 8*10^9のオーダーになること。
    // -> 上下左右方向にたどってO(4HW)
    // そこから幅優先探索で最短距離
    ll sh, sw, gh, gw;
    vb2 mp(h, vb(w, true));
    rep(i, h) {
        bool p{false};
        rep(j, w) {
            if(a[i][j] == 'S') {
                sh = i;
                sw = j;
            } else if(a[i][j] == 'G') {
                gh = i;
                gw = j;
            }
            switch(a[i][j]) {
                case '>':
                    mp[i][j] = false;
                    p = true;
                    break;
                case '<':
                case '^':
                case 'v':
                case '#':
                    mp[i][j] = false;
                    p = false;
                    break;
                default:
                    if(p) mp[i][j] = false;
                    break;
            }
        }
        rrep(j, w) {
            switch(a[i][j]) {
                case '<':
                    mp[i][j] = false;
                    p = true;
                    break;
                case '>':
                case '^':
                case 'v':
                case '#':
                    mp[i][j] = false;
                    p = false;
                    break;
                default:
                    if(p) mp[i][j] = false;
                    break;
            }
        }
    }
    rep(j, w) {
        bool p{false};
        rep(i, h) {
            switch(a[i][j]) {
                case 'v':
                    mp[i][j] = false;
                    p = true;
                    break;
                case '>':
                case '<':
                case '^':
                case '#':
                    mp[i][j] = false;
                    p = false;
                    break;
                default:
                    if(p) mp[i][j] = false;
                    break;
            }
        }
        rrep(i, h) {
            switch(a[i][j]) {
                case '^':
                    mp[i][j] = false;
                    p = true;
                    break;
                case '<':
                case '>':
                case 'v':
                case '#':
                    mp[i][j] = false;
                    p = false;
                    break;
                default:
                    if(p) mp[i][j] = false;
                    break;
            }
        }
    }

    vl dh = {1, -1, 0, 0};
    vl dw = {0, 0, 1, -1};
    queue<pl> q;
    q.push(make_pair(sh, sw));
    vl2 cost(h, vl(w, MAXLL));
    cost[sh][sw] = 0;
    while(!q.empty()) {
        auto [ch, cw] = q.front();
        q.pop();
        rep(i, 4) {
            ll nh = ch + dh[i];
            ll nw = cw + dw[i];
            if(nh >= 0 && nh < h && nw >= 0 && nw < w && mp[nh][nw] && cost[nh][nw] >= MAXLL) {
                cost[nh][nw] = min(cost[nh][nw], cost[ch][cw]+1);
                if(nh == gh && nw == gw) {
                    cout << cost[nh][nw] << endl;
                    return 0;
                } else {
                    q.push(make_pair(nh, nw));
                }
            }
        }
    }
    cout << -1 << endl;
}
