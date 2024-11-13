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


/**
 * @brief 行列の積
 *
 * @param x
 * @param y
 *
 * @return 
 */
vector<vector<ll>> MultiArray(vector<vector<ll>> &x, vector<vector<ll>> &y) {
    vector<vector<ll>> ans(x.size(), vector<ll>(y[0].size(), 0));
    rep(i, x.size()) {
        rep(j, y[0].size()) {
            rep(k, x[0].size()) {
                ans[i][j] += (x[i][k] * y[k][j]);
            }
        }
    }
    return ans;
}


/**
 * @brief 行列の累乗
 *
 * @param x
 * @param n
 *
 * @return 
 */
vector<vector<ll>> PowArray(vector<vector<ll>> &x, ll n) {
    vector<vector<ll>> ans(x.size(), vector<ll>(x.size(), 0));
    rep(i, x.size()) {
        ans[i][i] = 1;
    }

    while(n > 0) {
        if(n % 2) {
            ans = MultiArray(ans, x);
        }
        x = MultiArray(x, x);
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(k);

    // 1 ≤ N ≤2×10^5
    // 0 ≤ K ≤10^18
    // 1 ≤ Xi ≤ N
    // 1 ≤ Ai ≤ 2×10^5
    //
    // Ai' = Axi
    // をK回繰り返す。
    // Kの制約から言って、行列演算かダブリングとかじゃないのか。
    // (A1 A2 --- An)に、i行目のXiビット目を1としたNxN行列をK回かければ答えが出る
#if 1
    vl2 x(60, vl(n, 0));
    rep(i, n) {
        cin >> x[0][i];
        x[0][i]--;
    }
    DefA(ac, n);
    vl ap(n, 0);

    srep(i, 1, 60) {
        rep(j, n) {
            x[i][j] = x[i-1][x[i-1][j]];
        }
    }

    ll lvl{0};
    while(k > 0) {
        /* cout << "DB1:" << lvl << " " << k << endl; */
        swap(ap, ac);
        if(k & 0x01) {
            rep(i, n) {
                ac[i] = ap[x[lvl][i]];
            }
        }
        lvl++;
        k >>= 1;
        /* cout << "DB:"; */
        /* for(auto a : ac) cout << a << " "; */
        /* cout << endl; */
    }

    for(auto a : ac) cout << a << " ";
    cout << endl;
#else
    // TODO これだとnの制約からメモリがあふれるっぽい
    // xについて、実際はn個の1が入るだけなんだから、データの持ち方で削減する必要があるか。
    vl2 x(n, vl(n, 0));
    rep(i, n) {
        Def(tmp);
        x[tmp-1][i] = 1;
    }
    vl2 a(1, vl(n, 0));
    rep(i, n) cin >> a[0][i];

    auto tran = PowArray(x, k);
    auto ans = MultiArray(a, tran);
    for(auto v : ans[0]) cout << v << " ";
    cout << endl;
#endif
}
