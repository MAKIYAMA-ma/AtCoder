#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;

#if 0
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, W;
    cin >> n >> W;

    vl w(n), v(n);
    rep(i, n) cin >> w[i] >> v[i];

    ll MAXV = 100*1000;

    // indexはv
    // v以上の価値にするための最低重量を表すDP
    vl dpp(MAXV+1, MAXLL), dpc(MAXV+1, MAXLL);
    dpc[0] = 0;
    srep(i, 1, v[0]+1) {
        dpc[i] = w[0];
    }
    srep(i, 1, n) {
        swap(dpc, dpp);

        /* cout << "----------" << endl; */
        rep(j, MAXV+1) {
            ll pw = 0;
            if(v[i] <= j) {
                pw = dpp[j-v[i]];
            }
            dpc[j] = min(dpp[j], pw + w[i]);
            /* cout << dpc[j] << " "; */
        }
        /* cout << endl; */
        /* cout << "----------" << endl; */
    }

    // DPの意味的に昇順なはずなので、そのまま二分探索
    // 重量がW以下である最後の要素を取得。このIndexが答えのv。
    auto ans = upper_bound(all(dpc), W);
    if(ans != dpc.begin()) ans--;
    cout << ans - dpc.begin() << endl;
}
