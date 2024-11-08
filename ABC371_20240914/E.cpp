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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vector<set<int>> a(n);
    rep(i, n) {
        Def(val);
        val--;
        a[val].insert(i);
    }

    // lとrで普通にカウントすればO(N2)でドボン
    // f(l, r) は、f(l, r-1)と等しい or +1になる
    // でも、1増えるかどうかの判定にはどの数字が使用済みかの情報が必要
    //
    // 逆にどの数字がどの座標にあるかを管理したらなんか出来たりしない？
    // 範囲の数は1~nの総和
    // そのうち、[0, n)のiについて、Aiが含まれる領域数は(i+1)*(n-i)個
    // 同じ数字がi < jの二か所にいる場合、(i+1)*(n-i) + (j-i)*(n-j)個
    ll ans{0};
    rep(i, n) {
        int st{-1};
        for(auto v : a[i]) {
            ans += (v-st)*(n-v);
            st = v;
        }
    }
    cout << ans << endl;
}
