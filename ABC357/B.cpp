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
    string s;
    cin >> s;

    int sd{0}, bd{0};
    rep(i, s.length()) {
        if((s[i] >= 'a') && (s[i] <= 'z')) {
            sd++;
        } else {
            bd++;
        }
    }
    if(bd > sd) {
        int df = 'A' - 'a';
        rep(i, s.length()) {
            if((s[i] >= 'a') && (s[i] <= 'z')) {
                s[i] += df;
            }
        }
    } else {
        int df = 'a' - 'A';
        rep(i, s.length()) {
            if((s[i] >= 'A') && (s[i] <= 'Z')) {
                s[i] += df;
            }
        }
    }
    cout << s << endl;
}
