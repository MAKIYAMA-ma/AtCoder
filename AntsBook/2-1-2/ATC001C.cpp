#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int h, w;
    cin >> h >> w;
    int sx, sy;

    cout << "DB:" << h << " " << w << endl;
    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h) {
        string s;
        cin >> s;
        cout << "DB:" << s << endl;

        rep(j, w) {
            if(s[j] == 's') {
                c.at(i).at(j) = 2;
                sx = i;
                sy = j;
            } else if(s[j] == 'g') {
                c.at(i).at(j) = 3;
            } else if(s[j] == '.') {
                c.at(i).at(j) = 0;
            } else if(s[j] == '#') {
                c.at(i).at(j) = 1;
            }
        }
    }

    stack<pair<int, int>> sch;
    sch.push(make_pair(sx, sy));

    while(!sch.empty()) {
        auto p = sch.top();
        sch.pop();

        if(c.at(p.first).at(p.second) == 3) {
            cout << "Yes" << endl;
            return 0;
        }

        if(p.first > 0) {
            if(c.at(p.first-1).at(p.second) == 1) {
                sch.push(make_pair(p.first-1, p.second));
            }
        }
        if(p.second > 0) {
            if(c.at(p.first).at(p.second-1) == 1) {
                sch.push(make_pair(p.first, p.second-1));
            }
        }
        if(p.first < h-1) {
            if(c.at(p.first+1).at(p.second) == 1) {
                sch.push(make_pair(p.first+1, p.second));
            }
        }
        if(p.second < w-1) {
            if(c.at(p.first).at(p.second+1) == 1) {
                sch.push(make_pair(p.first, p.second+1));
            }
        }
    }

    cout << "No" << endl;
    return -1;
}
