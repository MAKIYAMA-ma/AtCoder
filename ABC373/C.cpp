#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    ll n;
    cin >> n;

    ll ma = -1000000000;
    ll mb = -1000000000;
    rep(i, n) {
        ll a;
        cin >> a;
        ma = max(a, ma);
    }
    rep(i, n) {
        ll b;
        cin >> b;
        mb = max(b, mb);
    }

    cout << ma + mb << endl;
}
