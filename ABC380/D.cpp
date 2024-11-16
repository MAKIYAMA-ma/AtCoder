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

    vs s(2);
    cin >> s[0];
    s[1] = "";
    rep(i, s[0].length()) {
        if(s[0][i] >= 'a' && s[0][i] <= 'z') {
            s[1] += (s[0][i] - 'a' + 'A');
        } else {
            s[1] += (s[0][i] - 'A' + 'a');
        }
    }

    Def(q);
    rep(i, q) {
        Def(k);
        k--;
#if 1
        ll pos = k / (s[0].length());
        ll cnt{0};
        while(pos > 0) {
            ll tmp = pos;
            ll lv{0};
            while(tmp > 0) {
                lv++;
                tmp >>= 1;
            }
            lv--;
            pos -= Pow(2, lv);
            cnt++;
        }
        /* cout << endl << cnt << endl; */
        cout << s[cnt%2][k%s[0].length()] << " ";
#else
        ll cnt{0};
        while(k >= s[0].length()) {
            ll mxcnt{0};
            ll tmp = (k+s[0].length()-1)/(s[0].length());
            while(tmp > 0) {
                mxcnt++;
                tmp >>= 1;
            }
            mxcnt--;
            /* cout << "DB:" << mxcnt << endl; */

            k -= Pow(2, mxcnt)*(s[0].length());
            cnt++;
        }
        cout << s[cnt%2][k] << " ";
#endif
    }
    cout << endl;
}
