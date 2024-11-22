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
    DefA(h, n);

#if 1
    // i番目のカベまで満タンになる時間
    vl tm(n+1, 0);
    stack<pl> st;
    rep(i, n) {
        while(!st.empty() && st.top().first < h[i]) {
            st.pop();
        }
        tm[i] = 0;
        ll pp = -1;
        if(!st.empty()) {
            // iの手前にある、iより高い直近のカベの位置
            pp = st.top().second;
            tm[i] = tm[pp];
        }
        // ppの位置までは、全てh[i]の高さまで水を入れる必要がある
        tm[i] += ((h[i])*(i-pp));
        st.push(make_pair(h[i], i));
    }
    rep(i, n) {
        cout << tm[i]+1 << " ";
    }
    cout << endl;
#else
    stack<pl> st;
    rep(i, n) {
        while(!st.empty() && st.top().first < h[i]) {
            st.pop();
        }
        st.push(make_pair(h[i], i));
    }
    ll ans{0};
    pl nr = {1, n};
    while(!st.empty()) {
        auto tp = st.top();
        st.pop();
        ans += (nr.first * (nr.second - tp.second));
        nr = tp;
    }
    ans += nr.first * (nr.second+1);

    cout << ans << endl;
#endif
}
