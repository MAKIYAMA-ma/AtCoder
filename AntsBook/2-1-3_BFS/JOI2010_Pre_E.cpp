#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int judge(vector<vector<bool>> &mp, int sx, int sy, int gx, int gy)
{
    vector<vector<int>> cost(mp.size(), vector<int>(mp.at(0).size(), -1));
    cost.at(sx).at(sy) = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        int x, y;
        x = p.first;
        y = p.second;
        int cc = cost.at(x).at(y);

        if((x == gx) && (y == gy)) {
            /* rep(i, mp.size()) { */
            /*     rep(j, mp.at(0).size()) { */
            /*         cout << cost.at(i).at(j) << " "; */
            /*     } */
            /*     cout << endl; */
            /* } */
            return cc;
        }
        if(x-1 >= 0) {
            if(mp.at(x-1).at(y) && (cost.at(x-1).at(y) < 0)) {
                cost.at(x-1).at(y) = cc+1;
                q.push(make_pair(x-1, y));
            }
        }
        if(y-1 >= 0) {
            if(mp.at(x).at(y-1) && (cost.at(x).at(y-1) < 0)) {
                cost.at(x).at(y-1) = cc+1;
                q.push(make_pair(x, y-1));
            }
        }
        if(x+1 < mp.size()) {
            if(mp.at(x+1).at(y) && (cost.at(x+1).at(y) < 0)) {
                cost.at(x+1).at(y) = cc+1;
                q.push(make_pair(x+1, y));
            }
        }
        if(y+1 < mp.at(0).size()) {
            if(mp.at(x).at(y+1) && (cost.at(x).at(y+1) < 0)) {
                cost.at(x).at(y+1) = cc+1;
                q.push(make_pair(x, y+1));
            }
        }
    }
    return 0;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> x(n+1);
    vector<int> y(n+1);

    vector<vector<bool>> mp(h, vector<bool>(w, true));
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) {
            mp.at(i).at(j) = s[j];
            if(s[j] == 'X') {
                mp.at(i).at(j) = false;
            } else if(s[j] == 'S') {
                x.at(0) = i;
                y.at(0) = j;
            } else if(s[j] != '.') {
                x.at(s[j] - '0') = i;
                y.at(s[j] - '0') = j;
            }
        }
    }

    /* S->1, 1->2...で9まで行く最短をそれぞれ求める。 */
    int ans = 0;
    rep(i, n) {
        ans += judge(mp, x.at(i), y.at(i), x.at(i+1), y.at(i+1));
    }
    cout << ans << endl;
}
