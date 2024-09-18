#include <bits/stdc++.h>
using namespace std;

int main() {
    bool ans = true;
    int n;
    cin >> n;

    vector<int> t(n+1, 0), x(n+1, 0), y(n+1, 0);
    vector<pair<int, int>> xy(n);
    for(int i = 1; i <= n; i++) {
        cin >> t.at(i) >> x.at(i) >> y.at(i);
    }

    for(int i = 1; i <= n; i++) {
        int diff_t = t.at(i) - t.at(i-1);
        int diff = abs(x.at(i) - x.at(i-1)) + abs(y.at(i) - y.at(i-1));

        /* cout << "DBG:" << diff_t << " " << diff << " "; */
        diff = diff_t - diff;
        /* cout << diff << endl; */

        if(diff < 0) {
            ans = false;
            break;
        } else if(diff % 2) {
            ans = false;
            break;
        }
    }

    if(ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
