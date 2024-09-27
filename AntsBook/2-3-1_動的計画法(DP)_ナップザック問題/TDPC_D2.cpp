#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    ll d;
    cin >> n >> d;

    vector<int> elm(3, 0);
    while(!(d % 2)) {
        d /= 2;
        elm.at(0)++;
    }
    while(!(d % 3)) {
        d /= 3;
        elm.at(1)++;
    }
    while(!(d % 5)) {
        d /= 5;
        elm.at(2)++;
    }
    if(d != 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<vector<vector<double>>>> dp(n+1, vector<vector<vector<double>>>(elm.at(0)+1, vector<vector<double>>(elm.at(1)+1, vector<double>(elm.at(2)+1, 0))));
    dp.at(0).at(0).at(0).at(0) = 1;

    // 各サイコロの目に2, 3, 5がそれぞれ幾つ含まれるか
    vector<int> c2 = {0, 1, 0, 2, 0, 1};
    vector<int> c3 = {0, 0, 1, 0, 0, 1};
    vector<int> c5 = {0, 0, 0, 0, 1, 0};
    for(int i = 1; i <= n; i++) {
        rep(x2, elm.at(0)+1) {
            rep(x3, elm.at(1)+1) {
                rep(x5, elm.at(2)+1) {
                    rep(j, 6) {
                        int g2 = min(elm.at(0), x2 + c2.at(j));
                        int g3 = min(elm.at(1), x3 + c3.at(j));
                        int g5 = min(elm.at(2), x5 + c5.at(j));
                        dp.at(i).at(g2).at(g3).at(g5) += dp.at(i-1).at(x2).at(x3).at(x5)/6;
                    }
                }
            }
        }
    }

    /* for(int i = 0; i <= n; i++) { */
    /*     rep(x2, elm.at(0)+1) { */
    /*         rep(x3, elm.at(1)+1) { */
    /*             rep(x5, elm.at(2)+1) { */
    /*                 cout << dp.at(i).at(x2).at(x3).at(x5) << " "; */
    /*             } */
    /*         } */
    /*     } */
    /*     cout << endl; */
    /* } */

    cout << fixed << setprecision(8) << dp.at(n).at(elm.at(0)).at(elm.at(1)).at(elm.at(2)) << endl;
}
