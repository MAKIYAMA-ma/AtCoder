#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;

    vector<int> k(n);
    rep(i, n) {
        cin >> k.at(i);
    }

    ll ans = 1e18;
    for(ll i = 0; i < (1 << n); i++) {
        ll t1 = 0;
        ll t2 = 0;

        rep(j, n) {
            if(i & (1 << j)) {
                t1 += k.at(j);
            } else {
                t2 += k.at(j);
            }
        }
        ans = min(ans, max(t1, t2));
    }
    cout << ans << endl;
}
