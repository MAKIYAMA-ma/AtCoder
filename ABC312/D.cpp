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

mint check(string &s, ll st, ll tl, vector<vector<mint>> &dp, vb2 &fin) {
    if(fin[st][tl]) return dp[st][tl];
    if(st > tl) {
        dp[st][tl] = 0;
    } else if(st == tl) {
        dp[st][tl] = 1;
    } else {
        mint ans{0};
        if(s[st] != ')') {
            srep(i, st+1, tl) {
                if(s[i] != '(') {
                    ans += check(s, st+1, i, dp, fin) * check(s, i+1, tl, dp, fin);
                }
            }
        }
        dp[st][tl] = ans;
    }
    fin[st][tl] = true;
    /* cout << "DB:" << st << " " << tl << " " << dp[st][tl].val() << endl; */
    return dp[st][tl];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    // s.length <= 3000
    // 当然再帰だと思うのだが
    vector<vector<mint>> dp(s.length()+1, vector<mint>(s.length()+1, 0));
    vb2 ac(s.length()+1, vb(s.length()+1, false));
    cout << (check(s, 0, s.length(), dp, ac)).val() << endl;
    /* rep(i, s.length()+1) { */
    /*     cout << i << ":"; */
    /*     rep(j, s.length()+1) { */
    /*         cout << dp[i][j].val() << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
}
