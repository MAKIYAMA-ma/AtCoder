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
const int MAXI = 1e9;
const int MINI = -1e9;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

/**
 * @brief 累乗
 *
 * @param x
 * @param n
 *
 * @return 
 */
mint Pow(ll x, ll n) {
    mint ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

/**
 * @brief 0 ~ nの整数で、第pビット（0始まり）が立つ数字が何個あるか
 *
 * @param n
 * @param p
 *
 * @return 
 */
ll CountBit(ll n, int p) {
    ll ans = 0;
    ll cycle = ((ll)1 << (p + 1));     // 第p bitはcycle/2回0となり、cycle/2回1となるのを繰り返す
    ll cycle_num = (n+1) / cycle;  // 0~nの整数で、cycleが何個入るか

    ans = cycle_num * (cycle/2);
    ans += max((ll)0, ((n+1) % cycle) - (cycle/2)); // 余剰分に含まれる1の個数。0区間が終わった残りがあれば、その分は1

    /* cout << p << ":" << ans << endl; */
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    // 0からnまでの各整数とmの&をとった値のpopcountの総和が欲しい
    // n <= 2^60
    // なのでO(n)ではアウト
    //
    // mp = popcount(m)
    // とすると、加算する値のパターンは2^mpパターン
    // それぞれ、2^(bit数(n) - mp)回足される
    //
    // しかし、最悪 m = 2^60 - 1
    // だとすると、結局2^mpパターンを見るのに結局TLEする
    // -> 計算可能
    // 各ビットの値は、2^(mp-1)回足される。
    //
    //
    // でもこの計算は、mがbmビットとした場合、
    // n = 1 << bm - 1
    // である場合の話。
    // n < m ならmのビットのうち使われないものも出てくるし、
    // 使われても等回数とはならない。
    //
    // -> 各ビットについて、n以下の整数で何回ビットが立つか計算できる必要がある。
    // 第0bitは2回に一回
    // 第1bitは2回おきに2回ずつ
    // 第2bitは4回おきに4回ずつ
    // 第nbitは2^n回おきに2^n回ずつ立つ

#if 1
    mint ans = 0;
    int pos = 0;
    while(m > 0) {
        if(m & 0x01) {
            ans += CountBit(n, pos);
        }
        pos++;
        m >>= 1;
    }
#else
    ll mp = __builtin_popcount(m);
    ll bn = 0;
    ll tmp = n;
    while(tmp > 0) {
        bn++;
        tmp >>= 1;
    }

    vi mbpos;
    tmp = m;
    int cnt = 0;
    while(tmp > 0) {
        if(tmp & (1 << cnt)) {
            mbpos.push_back(cnt);
        }
        cnt++;
        tmp >>= 1;
    }

    mint ans = 0;
    mint kai = Pow(2, mp-1);
    for(auto pos : mbpos) {
        ans += Pow(2, pos) * kai;
    }
    ans *= Pow(2, (bn - mp));
#endif
    cout << ans.val() << endl;
}
