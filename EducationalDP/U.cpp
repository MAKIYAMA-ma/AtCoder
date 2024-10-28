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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

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

    int n;
    cin >> n;

    vl2 a(n, vl(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    // 各グループの点数を計算
    vl pt(1 << n, 0);
    rep(i, 1 << n) {
        int base = -1;
        rep(j, n) {
            if(i & (1 << j)) {
                if(base < 0) {
                    base = j;
                    pt[i] = pt[i & ~(1 << j)];
                } else {
                    pt[i] += a[base][j];
                }
            }
        }
    }
    /* cout << "----------" << endl; */
    /* rep(i, 1 << n) { */
    /*     cout << pt[i] << endl; */
    /* } */
    /* cout << "----------" << endl; */

    vl dp(1 << n, 0);
    // iのウサギでのグループ分けで最大の得点を表すDP
    // --> iの部分集合を検索する方法は？
    rep(i, 1 << n) {
        rep(j, i+1) {
            if((i & j) == j) {
                dp[i] = max(dp[i], dp[i & ~j] + pt[j]);
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;

    // グループ数の指定はないので、1~nグループ
    // なるべく、＋のコンビを同グループにしつつ-のコンビを引き離したいということ。
    // aii = 0であるので、nグループに分ければ0点
    // n-1グループに分けるなら、一番仲の良い組をグループ化する
    // しかし、そこからn-2への遷移は？
    // そもそも、k-2グループ作って最大得点のグループ分けは、
    // k-1グループの最大から二つ合併したものかというとそうとは限らないのでは。
    //
    // グループ分けだとUnionFindとか使いたくもなるが
    // N <= 16
    // かなり制約が小さい
    // 各グループにどのウサギがいるか、ビットで管理？ 2^16 = 65536しかグループの構成はない
    // 各グループ構成の点数は、2^16 * 16^2 = 16777216 のオーダーで全て計算できる。
    // メモ化DP的な感じで更に早く計算可能だとは思う。
    //
    // そこから、全ビット1となる組合せで最大得点を計算できるか？
    //
    // 最初のk羽のウサギでの最大得点からK+1を追加
    // これも、やはり全く違うグループに変更したほうが良い気はする。
    // 最初のK羽で、グループ分け{S}をしている。
    // ここにk+1羽目を追加した場合の最大
    // ということなら分かる。
    //
    // これをkの時点での全sに対して計算 -> {S}ごとのグループ分けをインデックスとして管理する方法は？
}
