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

    // 1≤H,W≤1000
    // 1≤Y≤10^5
    // 1≤Ai,j≤10^5
    // O(HW)を一回やって、あとは毎回少ない計算量で対応可能、みたいなイメージの問題なはず

    Def(h);
    Def(w);
    Def(y);
    vl2 a(h, vl(w, 0));
    rep(i, h) rep(j, w) cin >> a[i][j];

    // i = 1 ~ Yのそれぞれについて、a > iとなる座標で囲まれた最大面積を求める。
    // 当然、海に沈む領域は単調増加する
    // 幅優先探索とかで何とか？
    vl2 drp(h, vl(w, MAXLL));
    vl ans(y+1, 0);
    priority_queue<pair<ll, pl>, vector<pair<ll, pl>>, greater<pair<ll, pl>>> pq;
    rep(i, w) {
        drp[0][i] = a[0][i];
        drp[h-1][i] = a[h-1][i];
    }
    srep(i, 1, h-1) {
        drp[i][0] = a[i][0];
        drp[i][w-1] = a[i][w-1];
    }
    rep(i, h) {
        if(i == 0 || i == h-1) {
            rep(j, w) {
                pq.push(make_pair(drp[i][j], make_pair(i, j)));
            }
        } else {
            pq.push(make_pair(drp[i][0], make_pair(i, 0)));
            if(w != 1) pq.push(make_pair(drp[i][w-1], make_pair(i, w-1)));
        }
    }
    vi dh = {1, -1, 0, 0};
    vi dw = {0, 0, 1, -1};
    while(!pq.empty()) {
        auto nxt = pq.top();
        pq.pop();
        auto d = nxt.first;
        auto ih = nxt.second.first;
        auto iw = nxt.second.second;

        rep(i, 4) {
            auto nh = ih+dh[i];
            auto nw = iw+dw[i];
            if(nh >= 0 && nh < h && nw >= 0 && nw < w && drp[nh][nw] == MAXLL) {
                drp[nh][nw] = max(drp[ih][iw], a[nh][nw]);
                pq.push(make_pair(drp[nh][nw], make_pair(nh, nw)));
            }
        }
    }
    rep(i, h) {
        rep(j, w) {
            if(drp[i][j] <= y) ans[drp[i][j]]++;
        }
    }
    srep(i, 1, y+1) {
        ans[i] += ans[i-1];
        cout << h*w - ans[i] << endl;
    }
}
