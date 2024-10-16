#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    sort(rall(a));
    sort(rall(b));

    vector<ll> ac(n, 0);
    vector<ll> bc(n, 0);

    ac[0] = a[0];
    rep(i, n-1) {
        ac[i+1] = ac[i] + a[i+1];
    }
    bc[0] = b[0];
    rep(i, n-1) {
        bc[i+1] = bc[i] + b[i+1];
    }
    int ai = upper_bound(all(ac), x) - ac.begin() + 1;
    int bi = upper_bound(all(bc), y) - bc.begin() + 1;
    if(ai >= n) ai = n;
    if(bi >= n) bi = n;
    /* cout << "ai:" << ai << endl; */
    /* cout << "bi:" << bi << endl; */

    cout << min(ai, bi) << endl;
}
