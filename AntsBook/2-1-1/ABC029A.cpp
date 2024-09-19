#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    rep(i, n) cin >> t.at(i);

    int ans = -1;
    for(int i = 0; i < (1 << n); i++) {
        int t0 = 0;
        int t1 = 0;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                t1 += t.at(j);
            } else {
                t0 += t.at(j);
            }
        }
        int tm = max(t0, t1);
        if(ans < 0) {
            ans = tm;
        } else {
            ans = min(ans, tm);
        }
    }
    cout << ans << endl;
}
