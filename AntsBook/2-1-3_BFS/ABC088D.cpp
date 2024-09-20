#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int h, w;
    cin >> h >> w;
    int w_cnt = 0;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    vector<vector<bool>> s(h, vector<bool>(w, true));
    rep(i, h) {
        string t;
        cin >> t;
        rep(j, w) {
            if(t[j] == '#') {
                s.at(i).at(j) = false;
            } else {
                w_cnt++;
            }
        }
    }

    queue<pair<int, int>> sch;
    vector<vector<int>> cost(h, vector<int>(w, -1));
    sch.push(make_pair(0, 0));
    cost.at(0).at(0) = 1;
    int mn = 0;
    while(!sch.empty()) {
        auto p = sch.front();
        sch.pop();
        int x = p.first;
        int y = p.second;

        if((x == h-1) && (y == w-1)) {
            break;
        }
        rep(i, 4) {
            int tx = x + dx.at(i);
            int ty = y + dy.at(i);

            if((tx < 0) || (ty < 0) || (tx >= h) || (ty >= w)) {
                continue;
            }
            if(s.at(tx).at(ty) && (cost.at(tx).at(ty) < 0)) {
                cost.at(tx).at(ty) = (cost.at(x).at(y) + 1);
                sch.push(make_pair(tx, ty));
                if((tx == h-1) && (ty == w-1)) {
                    break;
                }
            }
        }
    }
    /* rep(i, h) { */
    /*     rep(j, w) { */
    /*         cout << cost.at(i).at(j) << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    if(cost.at(h-1).at(w-1) < 0) {
        cout << -1 << endl;
    } else {
        cout << w_cnt - cost.at(h-1).at(w-1) << endl;
    }
}
