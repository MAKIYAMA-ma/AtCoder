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

    Def(n);
    Def(d);
    vl x(n), y(n);
    vl xo(n), yo(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
        xo[i] = x[i];
        yo[i] = y[i];
    }
    sort(all(xo));
    sort(all(yo));

    // なんか、尺取り法らしい

    // 解になりうるx, yの範囲を設定
    ll xmin, xmax, ymin, ymax;
    xmin = xo[n-1] - d;
    xmax = xo[0] + d;
    ymin = yo[n-1] - d;
    ymax = yo[0] + d;

    if(xmax < xmin || ymax < ymin) {
        cout << 0 << endl;
        return 0;
    }

    // 範囲内の全てのx, yについて、全点からのx方向、y方向の距離の総和を尺取り法で計算
    vl xd(xmax - xmin + 1, 0), yd(ymax - ymin + 1, 0);
    int xi{0}, yi{0};
    rep(i, n) {
        xd[0] += abs(x[i] - xmin);
        yd[0] += abs(y[i] - ymin);
    }
    srep(i, xmin + 1, xmax + 1) {
        auto idx = i-xmin;
        while(xi < xo.size() && xo[xi] < i) xi++;
        xd[idx] = xd[idx-1] + (xi - (n-xi));
    }
    srep(i, ymin + 1, ymax + 1) {
        auto idx = i-ymin;
        while(yi < yo.size() && yo[yi] < i) yi++;
        yd[idx] = yd[idx-1] + (yi - (n-yi));
    }
    /* for(auto tx : xd) cout << tx << " "; */
    /* cout << endl; */
    /* for(auto ty : yd) cout << ty << " "; */
    /* cout << endl; */

    // xd + yd <= Dとなる組合せ数を尺取り法でカウント
    ll ans{0};
    sort(rall(xd));
    sort(all(yd));
    ll ind{0};
    for(auto xdv : xd) {
        while(ind < yd.size() && xdv + yd[ind] <= d) ind++;
        ans += ind;
    }
    cout << ans << endl;
}
