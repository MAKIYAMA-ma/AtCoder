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
    Def(k);
    DefA(a, k);
    sort(all(a));

    // すでにそろっている組を崩すほうが良いケースはあるか否か？
    // -> ない
    // 1 2 5 7 8 10 -> 5
    // でも貪欲すると7になってしまう。貪欲じゃない。
    // 基本は隣どうしを組むべきなはず。
    //
    // ただ、奇数の時どれを捨てるか
    // 総当たりだとO(N2)でTLE
    ll ans{0};
    if(k%2) {
#if 1
        vl fc(k, 0), bc(k, 0);
        for(ll i = 1; i < k; i += 2) {
            fc[i] = ((i >= 2) ? fc[i-2] : 0) + (a[i]-a[i-1]);
        }
        for(ll i = k-2; i >= 0; i -= 2) {
            bc[i] = ((i < k-2) ? bc[i+2] : 0) + (a[i+1]-a[i]);
        }
        /* srep(i, 1, k) { */
        /*     fc[i] = ((i >= 2) ? fc[i-2] : 0) + (a[i]-a[i-1]); */
        /* } */
        /* for(ll i = k-2; i >= 0; i--) { */
        /*     bc[i] = ((i < k-2) ? bc[i+2] : 0) + (a[i+1]-a[i]); */
        /* } */
        // 使用しないものをまたぐペアを使う組は最適とはならないはず
        ans = MAXLL;
        /* rep(i, k) { */
        for(ll i = 0; i < k; i += 2) {
            auto f = (i == 0) ? 0 : fc[i-1];
            auto b = (i == k-1) ? 0 : bc[i+1];
            ans = min(ans, f+b);
        }
#else
        ans = MAXLL;
        rep(j, k) {
            ll cnt{0};
            for(ll i = 1; i < k; i += 2) {
                if(j == i) {
                    cnt += (a[i+1]-a[i-1]);
                    i++;
                } else if(j == (i-1)) {
                    i++;
                    cnt += (a[i]-a[i-1]);
                } else {
                    cnt += (a[i]-a[i-1]);
                }
            }
            ans = min(ans, cnt);
        }
#endif
    } else {
        for(ll i = 1; i < k; i += 2) {
            ans += (a[i]-a[i-1]);
        }
    }
    cout << ans << endl;
}
