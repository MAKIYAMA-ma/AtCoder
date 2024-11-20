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
    Def(x);
    Def(y);

    // 1≤N≤80
    // 1≤Ai,Bi≤10000
    // 1≤X,Y≤10000
    // 3sec
    vpl ab(n+1);
    rep(i, n) cin >> ab[i+1].first >> ab[i+1].second;
    sort(all(ab), [](const pl &a, const pl &b) {
            if(a.second == b.second) {
                return a.first < b.first;
            } else {
                return a.second < b.second;
            }
            });

    /* cout << "----------" << endl; */
    /* rep(i, n+1) { */
    /*     cout << ab[i].first << " " << ab[i].second << endl; */
    /* } */
    /* cout << "----------" << endl; */

    // aの総和>x、またはbの総和>yとなるまでの最大の個数は？
    //
    // 当然別々なら単に数字が小さいものを優先する貪欲
    // この場合普通ならDPだろう。
#if 1
    vl2 dpc(vl2(n+1, vl(x+2, MAXLL))), dpp(vl2(n+1, vl(x+2, MAXLL))); // i番目までからj個選んで甘さkとなる際のしょっぱさ
    dpc[0][0] = 0;
    ll ans{0};
    srep(i, 1, n+1) {
        swap(dpc, dpp);
        rep(j, i+1) {
            rep(k, x+1) {
                dpc[j][k] = min(dpc[j][k], dpp[j][k]);
                auto idx = min(k + ab[i].first, x+1);
                dpc[j][idx] = min(dpp[j][idx], ((j > 0 && dpp[j-1][k] <= y) ? (dpp[j-1][k] + ab[i].second) : MAXLL));
                if(dpc[j][idx] < MAXLL || dpc[j][k] < MAXLL) {
                    ans = max(ans, j);
                }
            }
        }
        /* cout << "-------------" << endl; */
        /* rep(i, dpc.size()) { */
        /*     cout << i << ":"; */
        /*     rep(j, dpc[0].size()) { */
        /*         if(dpc[i][j] < MAXLL) { */
        /*             cout << "(" << j << "," << dpc[i][j] << ") "; */
        /*         } else { */
        /*             /1* cout << "MAXLL "; *1/ */
        /*         } */
        /*     } */
        /*     cout << endl; */
        /* } */
        /* cout << "-------------" << endl; */
    }
    cout << ans << endl;
#else
    // i番目まで使って、甘さとしょっぱさがj, kとなる最大個数のDP
    // 10^4 * 10^4 * 2
    // で、今と前のデータのみ保持すればintならMLEは回避できるはず
    // しかし10^8を80回ではTLEでは？？ いつもより1.5倍の制限ではあるが。。。
    vi2 dpc(x+2, vi(y+2, 0)), dpp(x+2, vi(y+2, 0));
    int ans{0};
    srep(i, 1, n+1) {
        swap(dpc, dpp);
        rep(j, x+1) {
            rep(k, y+1) {
                int ta = j + ab[i].first;
                int tb = k + ab[i].second;
                if(ta > x+1) ta = x+1;
                if(tb > y+1) tb = y+1;
                dpc[ta][tb] = max(dpp[ta][tb], dpp[j][k] + 1);
                ans = max(ans, dpc[ta][tb]);
            }
        }
        /* cout << "-------------" << endl; */
        /* rep(i, 10) { */
        /*     rep(j, 10) { */
        /*         cout << dpc[i][j] << " "; */
        /*     } */
        /*     cout << endl; */
        /* } */
        /* cout << "-------------" << endl; */
    }
    /* int ans{0}; */
    /* rep(i, x+2) { */
    /*     ans = max(ans, *max_element(all(dpc[i]))); */
    /* } */
    cout << ans << endl;
#endif
}
