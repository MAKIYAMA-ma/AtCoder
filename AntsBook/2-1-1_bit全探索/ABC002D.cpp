#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> xy(n, 0);
    for(int i = 0; i < n; i++) {
        xy.at(i) |= (1 << i);
    }
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        xy.at(x-1) |= (1 << (y-1));
        xy.at(y-1) |= (1 << (x-1));
    }

    int ans = 0;
    for(int i = 0; i < (1 << n); i++) {
        bool sc = true;
        for(int j = 0; j < n; j++) {
            if(i & (1<<j)) {
                if((xy.at(j) & i) == i) {
                } else {
                    sc = false;
                    break;
                }
            }
        }
        if(sc) {
            int cnt = __builtin_popcount(i);
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;
}
