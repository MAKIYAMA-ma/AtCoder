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

ll check(vl2 &drp, vl2 &a, int th, int tw, vb2 &visited) {
    if(th < 0 || th >= drp.size() || tw < 0 || tw >= drp[0].size()) return 0;
    if(visited[th][tw]) return drp[th][tw];

    /* cout << "DB1:" << th << " " << tw << endl; */
    visited[th][tw] = true;
    drp[th][tw] = max(a[th][tw], min({
            check(drp, a, th-1, tw, visited),
            check(drp, a, th+1, tw, visited),
            check(drp, a, th, tw-1, visited),
            check(drp, a, th, tw+1, visited),
            }));
    /* cout << "DB2:" << th << " " << tw << endl; */
    return drp[th][tw];
}

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
    vb2 visited(h, vb(w, false));
    rep(i, w) {
        drp[0][i] = a[0][i];
        drp[h-1][i] = a[h-1][i];
    }
    rep(i, h) {
        drp[i][0] = a[i][0];
        drp[i][w-1] = a[i][w-1];
    }
    vl ans(y+1, 0);
    rep(i, h) {
        rep(j, w) {
            ll tm = check(drp, a, i, j, visited);
            if(tm <= y) ans[tm]++;
            /* cout << "--------" << endl; */
            /* cout << "DB:" << i << " " << j << endl; */
            /* rep(k, drp.size()) { */
            /*     rep(l, drp[0].size()) { */
            /*         cout << drp[k][l] << " "; */
            /*     } */
            /*     cout << endl; */
            /* } */
            /* cout << "--------" << endl; */
        }
    }
    srep(i, 1, y+1) {
        ans[i] += ans[i-1];
        cout << h*w - ans[i] << endl;
    }
}
