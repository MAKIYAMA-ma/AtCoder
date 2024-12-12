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
    string s;
    cin >> s;
    DefA(c, n);

    // 1010...の列に変換する。ただし、一か所だけ連続する。
    // 貪欲的に決めるのはたぶん無理。
    // だけど探索も無謀な気がする
    // 前からi文字目までを10にする場合と01にする場合のコストをそれぞれ計算
    // 後からも同じことをやる
    // で、1-nまで和が一番小さいのを求める
    // ならO(n)
    vl2 f(n, vl(2, 0)), a(n, vl(2, 0));
    if(s[0] == '0') {
        f[0][1] = c[0];
    } else {
        f[0][0] = c[0];
    }
    srep(i, 1, n) {
        if(s[i] == '0') {
            f[i][1] = f[i-1][0] + c[i];
            f[i][0] = f[i-1][1];
        } else {
            f[i][1] = f[i-1][0];
            f[i][0] = f[i-1][1] + c[i];
        }
    }
    if(s[n-1] == '0') {
        a[n-1][1] = c[n-1];
    } else {
        a[n-1][0] = c[n-1];
    }
    rrep(i, n-1) {
        if(s[i] == '0') {
            a[i][1] = a[i+1][0] + c[i];
            a[i][0] = a[i+1][1];
        } else {
            a[i][1] = a[i+1][0];
            a[i][0] = a[i+1][1] + c[i];
        }
    }

    ll ans{MAXLL};
    rep(i, n-1) {
        ans = min(ans, f[i][0]+a[i+1][0]);
        ans = min(ans, f[i][1]+a[i+1][1]);
    }
    cout << ans << endl;
}
