#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> wh(n);
    rep(i, n) {
        cin >> wh.at(i).first >> wh.at(i).second;
    }
    sort(all(wh));

    int curw = 0;
    int ans = 0;
    vector<int> l(n, pow(10, 5)+1);
    rep(i, n) {
        if(curw < wh.at(i).first) {
            int tgt = wh.at(i).second;
            auto next = lower_bound(all(l), tgt);
            curw = wh.at(i).first;
            if(next != l.end()) {
                *next = tgt;
                ans = max(ans, (int)(next - l.begin()));
            }
            /* cout << "L:"; */
            /* rep(j, n) { */
            /*     cout << l.at(j) << " "; */
            /* } */
            /* cout << endl; */
        }
    }

    cout << ans + 1 << endl;
}
