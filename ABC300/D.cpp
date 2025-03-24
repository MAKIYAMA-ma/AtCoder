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

using sl = set<ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;
using vs = vector<string>;
using vsl = vector<sl>;

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
#define Def2(m, n) ll m, n; cin >> m >> n;
#define Def3(l, m, n) ll l, m, n; cin >> l >> m >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define DefPA(a, n) vl a(n); rep(i, n) cin >> a[i].first >> a[i].second;

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

// 1 以上 N 以下の整数が素数かどうかを返す
// エラストスのふるい
vector<bool> Eratosthenes(ll N) {
    vector<bool> isprime(N+1, true);

    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;

    // ふるい
    for (ll p = 2; p <= N; ++p) {
        if (!isprime[p]) continue;

        for (ll q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    return isprime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    // n <= 10^12
    // a, bを当たったらcがあるかはO(N)
    // 素数は何個あるのか？
    // -> 10^12以下なら、37,607,912,018個
    // 10^6以下なら約80000個
    // 実際には更にはるかに早くnを超える
    // 総当たりで大丈夫では。
    auto isPrm = Eratosthenes((ll)sqrt(n/2));
    vl pl;
    rep(i, isPrm.size()) if(isPrm[i]) pl.push_back(i);

    /* cout << "DB:" << pl.size() << endl; */
    ll ans{0};
    rep(i, pl.size()) {
        ll a = pl[i];
        srep(j, i+1, pl.size()) {
            ll b = pl[j];
            if((ull)a*a*b*b*b >= n) break;
            srep(k, j+1, pl.size()) {
                ll c = pl[k];
                ull val = (ull)a*a*b*c*c;
                if(val <= n && val >= 300) {
                    /* cout << "DB:" << a << " " << b << " " << c << ":" << (a*a*b*c*c) << endl; */
                    ans++;
                } else {
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}
