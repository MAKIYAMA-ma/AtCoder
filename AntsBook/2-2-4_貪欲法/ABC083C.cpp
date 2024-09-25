#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    ll x, y;
    cin >> x >> y;

    int ans = 1;
    while(x <= y) {
        x *= 2;
        ans++;
    }

    cout << ans - 1 << endl;
}
