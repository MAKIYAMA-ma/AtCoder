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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vector<string> as(n);
    vl a(n);
    rep(i, n) {
        cin >> as[i];
        a[i] = stoll(as[i]);
    }

    // 今度はiによって、上で出る回数と下で出る回数が異なる。
    // また、上で出る場合のシフト量も異なる
    //
    // 後から何個目の要素までに、何桁の数字が何個あるかを累積カウントする
    // それに沿って上側の方をカウントする
    vl2 kn(n, vl(11, 0));
    kn[n-1][as[n-1].length()]++;
    rrep(i, n-1) {
        rep(j, 11) {
            kn[i][j] = kn[i+1][j];
        }
        kn[i][as[i].length()]++;
    }

    /* cout << "----------" << endl; */
    /* rep(i, n) { */
    /*     rep(j, 11) cout << kn[i][j] << " "; */
    /*     cout << endl; */
    /* } */
    /* cout << "----------" << endl; */

    mint ans = 0;
    rep(i, n) {
        ans += ((mint)a[i])*(i);
        /* cout << "DB1:" << ans.val() << endl; */
        if(i < n-1) {
            srep(j, 1, 11) {
                ans += ((mint)a[i])*Pow(10, j)*kn[i+1][j];
            }
        }
        /* cout << "DB2:" << ans.val() << endl; */
    }
    cout << ans.val() << endl;
}
