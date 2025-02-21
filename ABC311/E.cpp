#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 0
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
    Def(n);
    Def2A(a, b, n);

    // h, w <= 3000
    // よってマスの数は9*10^6
    // これで正方形のサイズ<=3000で。。。とか全網羅するのは当然TLE
    //
    // i, jを左上をとして1辺lの正方形が作れるかどうかをO(logH)とかで判定できないか？
    // 可能なら9000000回二分探索すればたぶん間に合う
    vl2 ac(h, vl(w, 0));
    rep(i, n) {
        ac[a[i]-1][b[i]-1] = 1;
    }
    rep(i, h) {
        srep(j, 1, w) {
            ac[i][j] += ac[i][j-1];
        }
    }
    rep(i, w) {
        srep(j, 1, h) {
            ac[j][i] += ac[j-1][i];
        }
    }

    /* cout << "-------" << endl; */
    /* rep(i, h) { */
    /*     rep(j, w) { */
    /*         cout << ac[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "-------" << endl; */

    ll ans{0};
    rep(i, h) {
        rep(j, w) {
            ll l{0};
            ll r = min(h-i, w-j)+1;
            while((r-l) > 1) {
                ll m = (l+r)/2;
                ll hl = ac[i+m-1][j+m-1];
                if(i > 0) hl -= ac[i-1][j+m-1];
                if(j > 0) hl -= ac[i+m-1][j-1];
                if(i > 0 && j > 0) hl += ac[i-1][j-1];
                if(hl) {
                    r = m;
                } else {
                    l = m;
                }
            }
            /* cout << "DB:" << i << " " << j << " " << l << endl; */
            ans += l;
        }
    }
    cout << ans << endl;
}
