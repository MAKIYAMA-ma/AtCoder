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
using vd = vector<double>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;

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
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


ll check(string s, int l, int r, vl2 &dp) {
    if(dp[l][r] >= 0) return dp[l][r];
    if(l == r) {
        dp[l][r] = 1;
    } else if(r - l == 1) {
        dp[l][r] = ((s[l] == s[r]) ? 2 : 1);
    } else {
        dp[l][r] = max({(s[l] == s[r]) ? (check(s, l+1, r-1, dp) + 2) : 0,
                check(s, l+1, r, dp), check(s, l, r-1, dp)});
    }
    return dp[l][r];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    // l ~ rの最長回文のDP
    // どういう遷移になる？
    // 中央部が1個/2個の2パターンがある
    // 端に追加する際に回文が長くなるかどうかを知るためには、
    // 回文部分の両端座標を知ったうえで検索する必要がある？
    // -> 両側が等しいかどうか観ながら進めばよい

    vl2 dp(n, vl(n, -1));
    cout << check(s, 0, n-1, dp) << endl;

/*     cout << "-------------" << endl; */
/*     rep(i, n) { */
/*         rep(j, n) { */
/*             cout << dp[i][j] << " "; */
/*         } */
/*         cout << endl; */
/*     } */
/*     cout << "-------------" << endl; */
}
