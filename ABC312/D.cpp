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

    string s;
    cin >> s;
    // s.length <= 3000
#if 1
    ll sl = s.length();
    vector<vector<mint>> dp(sl, vector<mint>(sl+1, 0));
    rep(i, sl) {
        if(s[i] != ')') {
            for(ll j = 1; j-1 <= i; j++) {
                dp[i][j] += ((i > 0)?dp[i-1][j-1]:1);
            }
        }
        if(s[i] != '(') {
            for(ll j = 0; j+1 <= i; j++) {
                dp[i][j] += ((i > 0)?dp[i-1][j+1]:1);
            }
        }
    }
    /* cout << "--------" << endl; */
    /* rep(i, dp.size()) { */
    /*     rep(j, dp[0].size()) { */
    /*         cout << dp[i][j].val() << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "--------" << endl; */
    cout << dp[sl-1][0].val() << endl;
#else
    vector<vector<mint>> dp(s.length()+1, vector<mint>(s.length()+1, 0));
    rep(i, dp.size()) dp[i][i] = 1;
    srep(l, 2, s.length()+1) {
        rep(i, s.length()-l+1) {
            /* cout << "DB:" << i << " " << i+l << endl; */
            if(s[i] != ')') {
                srep(j, i+1, i+l) {
                    /* cout << "   " << j << endl; */
                    if(s[j] != '(') {
                        dp[i][i+l] += dp[i+1][j]*dp[j+1][i+l];
                    }
                }
            }
        }
    }
    /* cout << "--------" << endl; */
    /* rep(i, dp.size()) { */
    /*     rep(j, dp[0].size()) { */
    /*         cout << dp[i][j].val() << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "--------" << endl; */
    cout << dp[0][s.length()].val() << endl;
#endif
}
