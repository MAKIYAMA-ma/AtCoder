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

ll Factorical(ll n, ll m) {
    ll ans = 1;
    for(ll i = n; i > m; i--) {
        ans *= i;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    ll fact = 1;
    map<char, ll> mp;
    rep(i, n) {
        fact *= (i+1);
        mp[s[i]]++;
    }

    ll dup = 1;
    for(auto ch : mp) {
        dup *= Factorical(ch.second, 1);
    }

    vector<int> od(n, 0);
    rep(i, n) od[i] = i;
    ll ans = 0;
    do {
        rep(i, n-k+1) {
            bool jdg = true;
            rep(j, k) {
                if(s[od[i+j]] != s[od[i+k-1-j]]) {
                    jdg = false;
                    break;
                }
            }
            if(jdg) {
                /* rep(j, n) { */
                /*     cout << s[od[j]]; */
                /* } */
                /* cout << endl; */
                ans++;
                break;
            }
        }
    } while (next_permutation(all(od)));

    /* cout << "DB:" << fact << " " << dup << " " << ans << endl; */
    cout << (fact - ans)/dup << endl;
}
