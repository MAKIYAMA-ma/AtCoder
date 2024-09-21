#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int h, w;
    cin >> h >> w;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    vector<vector<bool>> a(h, vector<bool>(w, true));
    vector<vector<int>> cost(h, vector<int>(w, -1));
    queue<pair<int, int>> sch;
    rep(i, h) {
        string t;
        cin >> t;
        rep(j, w) {
            if(t[j] == '#') {
                a.at(i).at(j) = false;
                sch.push(make_pair(i, j));
                cost.at(i).at(j) = 0;
            }
        }
    }

    int ans = 0;
    while(!sch.empty()) {
        auto p = sch.front();
        sch.pop();
        int x = p.first;
        int y = p.second;
        rep(i, 4) {
            int tx = x + dx.at(i);
            int ty = y + dy.at(i);
            if((tx < 0) || (ty < 0) || (tx >= h) || (ty >= w)) {
                continue;
            }
            if(a.at(tx).at(ty)) {
                a.at(tx).at(ty) = false;
                if(cost.at(tx).at(ty) < 0) {
                    cost.at(tx).at(ty) = cost.at(x).at(y) + 1;
                    sch.push(make_pair(tx, ty));
                    ans = cost.at(tx).at(ty);
                }
            }
        }
        /* cout << "------------" << endl; */
        /* rep(i, h) { */
        /*     rep(j, w) { */
        /*         cout << (a.at(i).at(j) ? '#' : '.') << " "; */
        /*     } */
        /*     cout << endl; */
        /* } */
        /* cout << "------------" << endl; */
    }
    cout << ans << endl;
}
