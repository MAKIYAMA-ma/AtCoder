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

    vector<ll> a(n);
    rep(i,n) {
        cin >> a.at(i);
    }

    vector<vector<ll>> b(n, vector<ll>(2, 0));
    b.at(0).at(1) = a.at(0);
    rep(i, n-1) {
        b.at(i+1).at(0) = max(b.at(i).at(0), b.at(i).at(1) + a.at(i+1)*2);
        b.at(i+1).at(1) = max(b.at(i).at(1), b.at(i).at(0) + a.at(i+1));
    }
    cout << max(b.at(n-1).at(0), b.at(n-1).at(1)) << endl;
}
