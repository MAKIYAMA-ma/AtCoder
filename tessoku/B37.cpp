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
ll Pow(ll x, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

ll count(ll n) {
    ll ans{0};
    int keta{0};
    int topn;

    if(n == 0) return 0;

    ll tmp = n;
    while(tmp > 0) {
        keta++;
        if(tmp < 10) topn = tmp;
        tmp /= 10;
    }

    if(keta == 1) {
        rep(i, topn+1) {
            ans += i;
        }
    } else {
        ll odr = Pow(10, keta-2);
        ll odr2 = odr*10;
        // 1から9まで1セットで45となる。
        // たとえば0~999の範囲で桁の総和を出すなら、
        // 1,10,100のくらいでそれぞれ1~9のセットが100周するので、
        // 各桁の合計が4500、3桁合わせて13500となる。
        rep(i, topn) {
            ans += (i * odr2 + 45 * odr * (keta-1));
        }
        ll rest = n % odr2;
        // 残った部分を計算する際、最上位桁の数字がrest+1回出現
        ans += topn * (rest + 1);
        // 最上位桁を削った残りの部分を再帰的に計算
        ans += count(rest);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll n;
    cin >> n;
    cout << count(n) << endl;
}
