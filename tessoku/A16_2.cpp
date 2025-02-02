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
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    int n;
    cin >> n;
    vector<ll> a(n+1, MAXLL);
    vector<ll> b(n+1, MAXLL);
    rep(i, n-1) cin >> a[i+1];
    rep(i, n-2) cin >> b[i+1];

    vl dp(n+1, MAXLL);
    dp[1] = 0;
    srep(i, 1, n) {
        dp[i+1] = min(dp[i] + a[i], dp[i+1]);
        /* cout << "a: " << i+1 << " " << a[i] << " " << dp[i+1] << endl; */
        if(i < n-1) {
            dp[i+2] = min(dp[i] + b[i], dp[i+2]);
            /* cout << "b: " << i+2 << " " << b[i] << " " << dp[i+2] << endl; */
        }
    }
    /* rep(i, n+1) { */
    /*     cout << dp[i] << " "; */
    /* } */
    /* cout << endl; */
    cout << dp[n] << endl;
}
