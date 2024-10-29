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

ll count(ll n) {
    ll ans = 0;
    ll keta = 0;
    ll tmp = n;
    ll maxn = 0;

    while(tmp > 0) {
        keta++;
        if(tmp < 10) maxn = tmp;
        tmp /= 10;
    }

    ll odr = 1;
    rep(i, keta-2) odr *= 10;

    cout << (keta-1) << endl;
    cout << (maxn) << endl;
    cout << (odr) << endl;
    rep(i, maxn-1) {
        ans += (i + 45*(keta-1)) * odr;
    }
    ans += maxn*(n%odr + 1);
    return ans;
}

int main() {
    int d, n;
    cin >> d >> n;
    vi l(n), r(n), h(n);
    rep(i, n) cin >> l[i] >> r[i] >> h[i];

    // 各iについて、li <= di <= riの区間はmaxがh[i]
    // -> 各diについて、その日を含むすべてのiについて、min(h[i])働けばよい。
    // 制約ぬるいので何も考えずそのまま計算
    vi w(d, 24);
    rep(i, n) {
        srep(j, l[i]-1, r[i]) {
            w[j] = min(w[j], h[i]);
        }
    }
    cout << reduce(all(w)) << endl;
}
