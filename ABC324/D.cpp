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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    string s;
    cin >> s;

    // n <= 13
    // -> 順列は6.2*10^9
    // しかし実際は各桁0-9のいずれかではあるので、絶対に重複がある
    // 2文字の重複が3つなら実際のターゲットは/8
    // それでも7.8*10^8
    // 制限は4secだが全部チェックは厳しいのでは？？
    //
    // 13桁なら最大が9を13個の数字であり、
    // 平方根の最大は2162277
    // ここまでの数字の2乗の構成数値が並び替えで作れるか確認すればいい

    map<ll, ll> pool;
    rep(i, s.length()) {
        pool[s[i]-'0']++;
    }

    ll mx{0};
    rrep(i, 10) {
        rep(j, pool[i]) {
            mx *= 10;
            mx += i;
        }
    }
    mx = (ll)sqrt(mx) + 1;

    ll ans{0};
    rep(i, mx+1) {
        map<ll, ll> cnt;
        ll t = i*i;
        while(t) {
            cnt[t%10]++;
            t /= 10;
        }
        bool ok{true};
        if(cnt[0] > pool[0]) {
            // 0については、pool側が余る分には、上位につけたと思えば良いのでOKとなる
            ok = false;
        } else {
            srep(j, 1, 10) {
                if(cnt[j] != pool[j]) {
                    ok = false;
                    break;
                }
            }
        }
        /* cout << i << " " << ok << endl; */
        if(ok) ans++;
    }
    cout << ans << endl;
}
