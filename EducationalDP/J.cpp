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


double dpf(vector<vd2> &dp, int one, int two, int three, int n) {
    if(dp[one][two][three] >= 0) return dp[one][two][three];
    if(one == 0 && two == 0 && three == 0) {
        dp[one][two][three] = 0.0;
        return 0.0;
    }

    dp[one][two][three] = (one > 0) ? (dpf(dp, one-1, two, three, n) + 1) * ((double)one / n) : 0.0;
    dp[one][two][three] += (two > 0) ? (dpf(dp, one+1, two-1, three, n) + 1) * ((double)two / n) : 0.0;
    dp[one][two][three] += (three > 0) ? (dpf(dp, one, two+1, three-1, n) + 1) * ((double)three / n) : 0.0;
    dp[one][two][three] += ((double)n - (one + two + three)) / n;
    dp[one][two][three] *= ((double)n / ((double)one + two + three));

    /* cout << one << ":" << two << ":" << three << "   " << dp[one][two][three] << endl; */
    return dp[one][two][three];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vi a(n, 0);
    vi cnt(4, 0);
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    // n枚の皿それぞれについて0-3の状態がある
    // しかも、操作をm回やったら終了、とかでもない。低確率ながらずっと終わらないパターンもある
    //
    //
    // 全てのiについて、a[i]以上の回数が出るまでの回数の期待値ということ
    // 全ての目の確率は1/n
    // vi dpc(n, 0), dpp(n, 0) で各皿の残り枚数をカウントする？
    // その場合、どこで終わり、答えが計算できる？
    //
    // 残っている皿の枚数を記録？？
    //
    // i回目の試行でkを引いた場合の、残り枚数でDPは可能か？
    // i+1回目の時点で何が残っているかによる
    //
    // 1枚目を引く際、2枚目、、、ラスト一枚を引く際。。という感じで、reduce(all(a))段のDPにできるか。
    // その場合、遷移は？
    // 残り0の皿の数、、、3の皿の数で4パターン？
    // どれが出るかの確率とその後の遷移は出せるとして、期待値はどこから計算できる？
    vector<vd2> dp(n+1, vd2(n+1, vd(n+1, -1)));
    PrintD(dpf(dp, cnt[1], cnt[2], cnt[3], n));
}
