#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

void print_map(vector<vector<int>> & c) {
    rep(i, c.size()) {
        rep(j, c.at(0).size()) {
            char m = '.';
            switch(c.at(i).at(j)) {
                case 0 : m = '.'; break;
                case 1 : m = '#'; break;
                case 2 : m = 's'; break;
                case 3 : m = 'g'; break;
                case 4 : m = '-'; break;
            }
            cout << m;
        }
        cout << endl;
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    int sx, sy;

    vector<vector<int>> c(h, vector<int>(w));
    rep(i, h) {
        string s;
        cin >> s;

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

        /* cout << "~~~~~~" << p.first << " " << p.second << "~~~~~~" << endl; */
        /* print_map(c); */

        if(c.at(p.first).at(p.second) == 3) {
            cout << "Yes" << endl;
            return 0;
        }
        c.at(p.first).at(p.second) = 4;

        if(p.first > 0) {
            if(c.at(p.first-1).at(p.second) == 0) {
                sch.push(make_pair(p.first-1, p.second));
            } else if(c.at(p.first-1).at(p.second) == 3) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if(p.second > 0) {
            if(c.at(p.first).at(p.second-1) == 0) {
                sch.push(make_pair(p.first, p.second-1));
            } else if(c.at(p.first).at(p.second-1) == 3) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if(p.first < h-1) {
            if(c.at(p.first+1).at(p.second) == 0) {
                sch.push(make_pair(p.first+1, p.second));
            } else if(c.at(p.first+1).at(p.second) == 3) {
                cout << "Yes" << endl;
                return 0;
            }
        }
        if(p.second < w-1) {
            if(c.at(p.first).at(p.second+1) == 0) {
                sch.push(make_pair(p.first, p.second+1));
            } else if(c.at(p.first).at(p.second+1) == 3) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
