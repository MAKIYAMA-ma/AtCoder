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

#if 1
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


ll merge(vl &ac, int l, int r, vl2 &dp) {
    if(dp[l][r] != MAXLL) return dp[l][r];
    if(l == r) {
        dp[l][r] = 0;
        return dp[l][r];
    }
    srep(i, l, r) {
        dp[l][r] = min(dp[l][r], merge(ac, l, i, dp) + merge(ac, i+1, r, dp) + ac[r] - ((l > 0) ? ac[l-1] : 0));
    }
    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vi2 a(n, vi(n, 0));
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }
    // 上記aの中から、行も列一回ずつのみ使って1を選ぶ組合せ
    // n組目としてmnとwnをペアにする場合。。。とか考えた場合、実際はそのコンビがn組目で1組目でも変わらない。
    // mnとwnがペアになるパターン数。。。とかをDPで出来たりする？
    // --> 最後に、どれか一人について全て足し合わせれば総数が出る
    // でもほかのマスから計算できんやろ
    // 1≤N≤21
    // 男女それぞれについて、誰が残っているかのパターンは2^21
    // その組み合わせで状態を持とうとすると、2^42になる。これを配列で持つのはMLEなはず。
    // 実際の組合せとしては、常に男女同数であり、残り人数が異なる場合のデータ領域は不要
    // それを考慮すると、実際に使うデータ領域のみでデータを持てればMLEは回避できるのかも。
    // でもどう実現できる？
    // nのMAXが21というのは何かのぎりぎりを攻めているのか？
}
