#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int h, w;
    cin >> h >> w;
    int sy, sx, gy, gx;

    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    vector<vector<bool>> mp(h, vector<bool>(w, true));
    vector<vector<int>> cost(h, vector<int>(w, -1));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            if(s[j] == '#') {
                mp.at(i).at(j) = false;
            } else if(s[j] == 's') {
                sx = i;
                sy = j;
            } else if(s[j] == 'g') {
                gx = i;
                gy = j;
            }
        }
    }

    cost.at(sx).at(sy) = 0;
    deque<pair<int, int>> sch;
    sch.push_front(make_pair(sx, sy));
    while(!sch.empty()) {
        auto p = sch.front();
        sch.pop_front();

        // ゴール
        if((p.first == gx) && (p.second == gy)) {
            if(cost.at(gx).at(gy) <= 2) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            return 0;
        }

        int x = p.first;
        int y = p.second;
        rep(i, 4) {
            int tx = x + dx.at(i);
            int ty = y + dy.at(i);
            bool f = true;

            if((tx < 0) || (ty < 0) || (tx >= h) || (ty >= w)) {
                continue;
            }
            if(cost.at(tx).at(ty) < 0) {
                int tmp = 0;
                if(mp.at(tx).at(ty)) {
                    tmp = cost.at(x).at(y);
                    f = true;
                } else {
                    tmp = (cost.at(x).at(y) + 1);
                    f = false;
                }
                cost.at(tx).at(ty) = tmp;

                if((tx == gx) && (ty == gy)) {
                    if(cost.at(gx).at(gy) <= 2) {
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                    return 0;
                } else {
                    // 追加コスト0なら前に追加
                    // 追加コスト1なら後に追加
                    if(f) {
                        sch.push_front(make_pair(tx, ty));
                    } else {
                        sch.push_back(make_pair(tx, ty));
                    }
                }
            }
        }

/*         rep(i, h) { */
/*             rep(j, w) { */
/*                 cout << cost.at(i).at(j) << " "; */
/*             } */
/*             cout << endl; */
/*         } */
    }
}
