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

ll check(vector<map<vl, ll>> &dp, vector<vs> &sl, string t, ll tail, vl &elm) {
    if(dp[tail].find(elm) != dp[tail].end()) return dp[tail][elm];
    if(tail == 0) {
        return 0;
    }

    dp[tail][elm] = MAXLL;
    srep(i, 1, min(tail, (ll)10)+1) {
        auto pt = t.substr(tail-i, i);
        rep(j, elm.size()) {
            rrep(k, elm[j]) {
                if(pt == sl[j][k]) {
                    auto tmp = elm[j];
                    elm[j] = k;
                    auto chk = check(dp, sl, t, tail-i, elm);
                    elm[j] = tmp;
                    dp[tail][elm] = min(dp[tail][elm], chk+1);
                    break;
                }
            }
        }
    }
    return dp[tail][elm];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string t;
    cin >> t;
    Def(n);
    vector<vs> sl(n, vs());
    vl sz(n, 0);
    rep(i, n) {
        Def(a);
        sz[i] = a;
        rep(j, a) {
            string s;
            cin >> s;
            sl[i].push_back(s);
        }
    }

    // 各文字列プールの文字列は順番にしか使えない
    // その縛りのもとで、プールされた文字列を繋いでTが作れるか？
    // 作れるなら、最小のパーツ数は？
    //
    // 1 <= N <= 100
    // 1 <= a <= 10
    // Tのi文字目までを作る場合の最小コストDPは可能？
    // 各プールを何番まで使っているかも欲しい
    // でも添え字100個はしんどい。完全に全パターンだと10^100になるし。
    // 100要素のvectorをkeyにしたmapとか？？
    // それでメモ化再帰ならいけないかな
    //
    // 結果の二分探索はちょっと微妙なような。
    // i点で作れるかどうかの判定、というのが高速には無理か？
    //
    // i個の要素で作る場合、、、というDPは？
    //
    //
    // 問題を勘違いしていた。。。。
    // 各袋から順に一つとる or とらないを続け、N袋まで行ったら終了らしい
    vector<map<vl, ll>> dp(t.length()+1, map<vl, ll>());
    ll ans = check(dp, sl, t, t.length(), sz);
    if(ans >= MAXLL) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
