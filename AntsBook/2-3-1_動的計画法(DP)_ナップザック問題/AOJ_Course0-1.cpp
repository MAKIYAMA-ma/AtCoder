#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<int ,int>> vw(n);

    rep(i, n) cin >> vw.at(i).first >> vw.at(i).second;

    vector<vector<int>> dp(n, vector<int>(w+1));
    for(int i = 0; i < vw.at(0).second; i++) {
        dp.at(0).at(i) = 0;
    }
    for(int i = vw.at(0).second; i <= w; i++) {
        dp.at(0).at(i) = vw.at(0).first;
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < vw.at(i).second; j++) {
            dp.at(i).at(j) = dp.at(i-1).at(j);
        }
        for(int j = vw.at(i).second; j <= w; j++) {
            dp.at(i).at(j) = max(dp.at(i-1).at(j-vw.at(i).second) + vw.at(i).first, dp.at(i-1).at(j));
        }
        /* cout << "------------" << endl; */
        /* rep(j, n) { */
        /*     rep(k, w+1) { */
        /*         cout << dp.at(j).at(k) << " "; */
        /*     } */
        /*     cout << endl; */
        /* } */
        /* cout << "------------" << endl; */
    }

    cout << dp.at(n-1).at(w) << endl;
}
