#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int r, c;
    int sy, sx, gy, gx;

    cin >> r >> c;
    cin >> sy >> sx;
    cin >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;

    vector<vector<bool>> mp(r, vector<bool>(c, false));
    vector<vector<int>> cost(r, vector<int>(c, -1));
    rep(i, r) {
        string s;
        cin >> s;
        rep(j, c) {
            if(s[j] == '.') {
                mp.at(i).at(j) = true;
            }
        }
    }

    cost.at(sy).at(sx) = 0;
    queue<pair<int, int>> sch;
    sch.push(make_pair(sy, sx));
    while(!sch.empty()) {
        int x, y;
        auto p = sch.front();
        sch.pop();

        // ゴール
        if((p.first == gy) && (p.second == gx)) {
            cout << cost.at(gy).at(gx) << endl;
            return 0;
        }
        if(!mp.at(p.first).at(p.second)) {
            continue;
        }

        int curc = cost.at(p.first).at(p.second);
        y = p.first - 1;
        x = p.second;
        if(y >= 0) {
            if(cost.at(y).at(x) < 0) {
                cost.at(y).at(x) = curc+1;
                if((y == gy) && (x == gx)) {
                    cout << cost.at(gy).at(gx) << endl;
                    return 0;
                } else {
                    sch.push(make_pair(y,x));
                }
            }
        }
        y = p.first + 1;
        x = p.second;
        if(y < r) {
            if(cost.at(y).at(x) < 0) {
                cost.at(y).at(x) = curc+1;
                if((y == gy) && (x == gx)) {
                    cout << cost.at(gy).at(gx) << endl;
                    return 0;
                } else {
                    sch.push(make_pair(y,x));
                }
            }
        }
        y = p.first;
        x = p.second-1;
        if(x >= 0) {
            if(cost.at(y).at(x) < 0) {
                cost.at(y).at(x) = curc+1;
                if((y == gy) && (x == gx)) {
                    cout << cost.at(gy).at(gx) << endl;
                    return 0;
                } else {
                    sch.push(make_pair(y,x));
                }
            }
        }
        y = p.first;
        x = p.second+1;
        if(x < c) {
            if(cost.at(y).at(x) < 0) {
                cost.at(y).at(x) = curc+1;
                if((y == gy) && (x == gx)) {
                    cout << cost.at(gy).at(gx) << endl;
                    return 0;
                } else {
                    sch.push(make_pair(y,x));
                }
            }
        }
    }

    /* rep(i, r) { */
    /*     rep(j, c) { */
    /*         cout << cost.at(i).at(j) << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
}
