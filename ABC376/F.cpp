#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;

using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<pi>;
using vb = vector<bool>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vp2 = vector<vp>;

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


ll check(ll &bf, ll &gd, ll tgt, ll n) {
    vl ans(2, 0);
    vl ngd(2, gd);

    if(bf > gd) gd += n;
    if(bf > tgt) tgt += n;

    if(tgt < gd) {
        ans[0] = tgt - bf;

        ans[1] = gd - (tgt - 1);
        ans[1] += bf - (tgt - n);
        ngd[1] = (tgt - 1) % n;
    } else {
        ans[0] = bf - (tgt - n);

        ans[1] = (tgt + 1) - gd;
        ans[1] += tgt - bf;
        ngd[1] = (tgt + 1) % n;
    }

    int ai{0};
    if(ans[0] > ans[1]) {
        ai = 1;
    }

    bf = tgt % n;
    gd = ngd[ai];

    return ans[ai];
}


int main() {
    ll n, q;
    cin >> n >> q;
    ll l{0}, r{1};

    ll ans = 0;
    rep(i, q) {
        char h;
        ll t;
        cin >> h >> t;
        t--;

        // TODO 貪欲ではWA
        // 邪魔な手をずらすパターンと逆側から行くパターンで、
        // その時点では手数が多くても、後の要求時の手数が大幅に削減できるパターンがありうる
        // -> DPを使うらしい
        if(h == 'L') {
            ans += check(l, r, t, n);
        } else {
            ans += check(r, l, t, n);
        }
        /* cout << l << " " << r << " " << ans << endl; */
    }
    cout << ans << endl;
}
