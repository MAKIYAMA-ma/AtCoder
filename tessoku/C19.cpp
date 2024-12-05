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

    Def(n);
    Def(l);
    Def(k);
    vl a(n+2, 0), c(n+2, 0);
    rep(i, n) {
        cin >> a[i+1] >> c[i+1];
    }
    a[n+1] = l;

    // 到達可能範囲で最安のスタンドでガソリンを入れる。
    // Kキロ以内にもっと安いスタンドがあればそこまで到達可能なガソリンを入れる
    // ないなら満タンまで入れる
    // を繰り返せば良いはず。
    // ただし、最後はゴールまでの分だけ入れれば良い。
    ll pos{0};
    ll ans{0};
    ll rest = k;
    auto up = upper_bound(all(a), a[pos] + k) - a.begin();
    auto ming = min_element(c.begin() + pos + 1, c.begin() + up) - c.begin();
    while(pos < n+1) {
        if(up - pos == 1) {
            cout << -1 << endl;
            return 0;
        }
        /* cout << "rest:" << rest << " " << a[ming] << " " << a[pos] << "--->"; */
        rest -= (a[ming] - a[pos]);
        /* cout << rest << endl; */
        /* cout << "DD:" << up << " " << ming << endl; */

        auto up2 = upper_bound(all(a), a[ming] + k) - a.begin();
        auto ming2 = min_element(c.begin() + ming + 1, c.begin() + up2) - c.begin();
        /* cout << "DD2:" << up2 << " " << *min_element(c.begin() + ming + 1, c.begin() + up2) << endl; */
        /* cout << "DD:" << ming << ":" << c[ming] << " " << ming2 << ":" << c[ming2] << endl; */
        if(c[ming] <= c[ming2]) {
            // 満タンにする
            ans += (c[ming]*(k-rest));
            rest = k;
            /* cout << "DB2:" << ming << " " << ans << endl; */
        } else {
            // ming2までの分を入れる
            ans += (c[ming]*(a[ming2]-a[ming]-rest));
            rest = a[ming2]-a[ming];
            /* cout << "DB3:" << ming << " " << ans << endl; */
        }
        pos = ming;
        up = up2;
        ming = ming2;
    }
    cout << ans << endl;
}
