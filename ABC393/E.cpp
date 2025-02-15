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

vl2 era(ll mxn) {
    vl2 div(mxn+1);
    srep(i, 1, mxn+1) {
        for(ll j = i; j <= mxn; j += i) {
            div[j].push_back(i);
        }
    }
    return div;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(k);
    DefA(a, n);

    // n <= 1.2*10^6
    // a <= 10^6
    // aiの倍数がいるならそれは採用
    // とかいう細かい選別を各iでやるのは当然無理なんだろう

    vl2 predv = era(*max_element(all(a)));
    map<ll, ll> mp;
    rep(i, n) {
        rep(j, predv[a[i]].size()) {
            mp[predv[a[i]][j]]++;
        }
    }

    rep(i, n) {
        rrep(j, predv[a[i]].size()) {
            if(mp[predv[a[i]][j]] >= k) {
                cout << predv[a[i]][j] << endl;
                break;
            }
        }
    }
}
