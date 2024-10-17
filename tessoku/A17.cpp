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
    int n;
    cin >> n;
    vector<ll> a(n, MAXLL);
    vector<ll> b(n, MAXLL);
    rep(i, n-1) cin >> a[i+1];
    rep(i, n-2) cin >> b[i+2];

    vector<ll> tm(n, MAXLL);
    tm[0] = 0;
    tm[1] = a[1];
    for(int i{2}; i < n; i++) {
        tm[i] = min(tm[i-2]+b[i], tm[i-1]+a[i]);
    }

    vector<int> ans(1, n-1);
    int pos = n-1;
    while(pos > 0) {
        if(pos >= 2 && tm[pos] - b[pos] == tm[pos-2]) {
            pos -= 2;
            ans.push_back(pos);
        } else if(tm[pos] - a[pos] == tm[pos-1]) {
            pos--;
            ans.push_back(pos);
        }
    }
    cout << ans.size() << endl;
    rep(i, ans.size()) {
        cout << ans[ans.size()-1-i]+1 << " ";
    }
    cout << endl;
}
