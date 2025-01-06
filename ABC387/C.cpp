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

ll Pow(ll x, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

ll check(ll n) {
    ll ans{0};
    ll tmp = n;
    ll kt{0};
    ll hd{0};

    while(tmp) {
        kt++;
        if(tmp!=0) hd = tmp;
        tmp /= 10;
    }

    // n自体が蛇数か否か判定
    bool snk{true};
    tmp = n;
    while(tmp >= 10) {
        if(tmp % 10 >= hd) {
            snk = false;
            break;
        }
        tmp /= 10;
    }

    // kt桁の数字で、頭からx桁がnと一致する場合の蛇数のカウント
    // 下からたどって、頭数以上の数字が登場したら一旦リセット（その数字がnと一致する前提なら、全て蛇数ではない）
    ll cr{0};
    tmp = n;
    /* cout << "DB:" << kt << endl; */
    while(tmp >= 10) {
        ll b = tmp%10;
        if(b >= hd) {
            ans = hd*Pow(hd, cr);
        } else {
            ans += b*Pow(hd, cr);
        }
        /* cout << "DB2:" << b << " " << hd << " " << ans << endl; */
        cr++;
        tmp /= 10;
    }

    // nが蛇数なら、n自身をカウント
    if(snk) ans++;
    /* cout << "DB3:" << ans << endl; */

    // kt桁で、頭数がnのモノより小さい場合の蛇数をカウント
    srep(i, 1, hd) {
        ans += Pow(i, kt-1);
    }
    /* cout << "DB4:" << ans << endl; */

    // kt桁未満の蛇数をカウント
    srep(i, 1, kt) {
        srep(j, 1, 10) {
            ans += Pow(j, i-1);
            /* cout << "DB4-1:" << i << " " << j << " " << ans << endl; */
        }
    }
    /* cout << "DB5:" << ans << endl; */
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(l);
    Def(r);

#if 1
    cout << check(r) - check(l-1) << endl;
#else
    ll cl = check(l);
    ll cr = check(r);

    cout << cl << " " << cr << endl;
#endif
}
