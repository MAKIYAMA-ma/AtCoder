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

    // 左からa番目とb番目を交換する操作をk回やる。
    // 0番の位置の期待値は？
    //
    // 今いる場所が出る確率: 1 - ((n-1)/n)^2
    // 移動先の確率:1/n (移動しない場合含め)
    //
    // 最初に1なのが確定であるから、1になる確率だけ別枠
    // 残りは等確率になるはず
    // -> 問題の条件で、K回後に1に戻っている確率は？
    vm2 one(k+1, vm(2, 0));
    mint ttl = 1;
    one[0][1] = 1;
    srep(i, 1, k+1) {
        ttl *= (n*n);
        // i回の試行で1になる確率
        one[i][1] = (one[i-1][1]*((n-1)*(n-1) + 1)) + (one[i-1][0]*2);
        // i回の試行で1にならない確率
        one[i][0] = (ttl - one[i][1]);
        /* cout << "DB:" << i << ":" << one[i][1].val() << " " << one[i][0].val() << endl; */
    }
    /* cout << "ttl:" << ttl.val() << endl; */
    /* cout << "cnt:" << one[k][1].val() << endl; */
    // 2 ~ nまでの合計は、n(n+1)/2 - 1
    // よって、2~nまでの平均はその1/(n-1)であり、約分すると(n+2)/2となる
    // それをもとに分母分子を整数で計算する
    ttl *= 2;
    mint exp = one[k][1] * 2 + one[k][0] * (n+2);
    /* cout << exp.val() << "/" << ttl.val() << endl; */

    // 期待値modの計算
    ll mod = 998244353;
    ll denomi = inv_mod(ttl.val(), mod);
    cout << (exp*denomi).val() << endl;
    /* cout << (exp.val() * denomi) % mod << endl; */
}
