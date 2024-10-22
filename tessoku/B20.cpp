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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s, t;
    cin >> s >> t;

    // LCSの文字数を確認
    // LCS部分を維持しての操作と考えると
    // 各LCSの文字間の文字数の最大値の合計を求めれば良い？
    // -> 同じ位置に該当文字が複数あるケースがたぶんある。。。
    //
    // -> LCS部分も変更したほうが良いケースもある。

    // 編集距離
    // LCSとは逆に、文字が異なるパスで加算していくDP
    vi2 dp(s.size()+1, vi(t.length()+1, 0));
    rep(i, s.size()+1) {
        dp[i][0] = i;
    }
    rep(j, t.size()+1) {
        dp[0][j] = j;
    }
    srep(i, 1, s.size()+1) {
        srep(j, 1, t.size()+1) {
            dp[i][j] = min({dp[i-1][j-1] + ((s[i-1] == t[j-1]) ? 0 : 1), dp[i-1][j] + 1, dp[i][j-1] + 1});
        }
    }
    /* cout << "-----------" << endl; */
    /* cout << "   - "; */
    /* rep(i, t.size()+1) { */
    /*     cout << t[i] << " "; */
    /* } */
    /* cout << endl; */
    /* rep(i, s.size()+1) { */
    /*     if(i == 0) { */
    /*         cout << "-: "; */
    /*     } else { */
    /*         cout << s[i-1] << ": "; */
    /*     } */
    /*     rep(j, t.size()+1) { */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "-----------" << endl; */

    cout << dp[s.size()][t.size()] << endl;
}
