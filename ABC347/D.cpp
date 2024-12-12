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

    Def(a);
    Def(b);
    Def(c);

#if 1
    // pc(C) > a+b なら解なし
    // ((a+b) - pc(C)) % 2 == 0なら解あり
    ll pc = __builtin_popcountll(c);
    if(pc > (a+b) || ((a+b-pc)%2) || (a < (b-pc)) || (b < (a-pc))) {
        cout << -1 << endl;
    } else {
        ll df = (a+b-pc)/2;
        ll x{0}, y{0};
        /* cout << "DB:" << a << " " << b << " " << df << endl; */
        /* cout << "   " << c << " " << pc << endl; */

        if(df > (60-pc)) {
            cout << -1 << endl;
            return 0;
        }

        ll one = a-df;
        ll zero = df;
        ll om{-1};
        rep(i, 60) {
            if((c >> i) & 0x01) {
                if(one > 0) {
                    x |= ((ll)1<<i);
                    one--;
                    if(one == 0) om = i;
                }
            } else {
                if(zero > 0) {
                    x |= ((ll)1<<i);
                    zero--;
                }
            }
        }

        one = b-df;
        zero = df;
        rep(i, 60) {
            if((c >> i) & 0x01) {
                if(i > om && one > 0) {
                    y |= ((ll)1<<i);
                    one--;
                }
            } else {
                if(zero > 0) {
                    y |= ((ll)1<<i);
                    zero--;
                }
            }
        }
        cout << x << " " << y << endl;

        /* rrep(i, 60) { */
        /*     if((c >> i) & 0x01) { */
        /*         cout << 1; */
        /*     } else { */
        /*         cout << 0; */
        /*     } */
        /* } */
        /* cout << endl; */
        /* rrep(i, 60) { */
        /*     if((x >> i) & 0x01) { */
        /*         cout << 1; */
        /*     } else { */
        /*         cout << 0; */
        /*     } */
        /* } */
        /* cout << endl; */
        /* rrep(i, 60) { */
        /*     if((y >> i) & 0x01) { */
        /*         cout << 1; */
        /*     } else { */
        /*         cout << 0; */
        /*     } */
        /* } */
        /* cout << endl; */
    }
#else
    // popcount == aの数字のみを順番にたどれるか？
    // それができるなら後はcとXORとってpopcount計算するだけ
    //
    // 順列はO(n!) 単純に60要素で全列挙させると間に合わない
    vb bs(60, false);
    fill(bs.begin(), bs.begin()+a, true);
    do {
        ll x{0};
        rep(i, bs.size()) {
            if(bs[i]) x |= (1 << i);
        }
        ll y = x ^ c;
        /* cout << "DB:" << x << endl; */
        if(__builtin_popcount(y) == b) {
            cout << x << " " << y << endl;
            return 0;
        }
    } while (prev_permutation(all(bs)));
    cout << -1 << endl;
#endif
}
