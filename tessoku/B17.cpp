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

    vector<ll> h(n);
    rep(i, n) cin >> h[i];

    vector<ll> cost(n, MAXLL);
    cost[0] = 0;
    rep(i, n-1) {
        cost[i+1] = min(cost[i+1], cost[i] + abs(h[i+1] - h[i]));
        if(i < n-2) {
            cost[i+2] = min(cost[i+2], cost[i] + abs(h[i+2] - h[i]));
        }
    }

    /* cout << "-------------" << endl; */
    /* rep(i, n) { */
    /*     cout << cost[i] << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "-------------" << endl; */

    vector<int> route;
    int pos = n-1;
    while(pos >= 0) {
        route.push_back(pos+1);
        if(pos-1 >= 0 && cost[pos] - abs(h[pos] - h[pos-1]) == cost[pos-1]) {
            pos--;
        } else if(pos-2 >= 0 && cost[pos] - abs(h[pos] - h[pos-2]) == cost[pos-2]) {
            pos -= 2;
        } else {
            break;
        }
    }

    cout << route.size() << endl;
    for(int i = route.size()-1; i >= 0; i--) {
        cout << route[i] << " ";
    }
    cout << endl;
}
