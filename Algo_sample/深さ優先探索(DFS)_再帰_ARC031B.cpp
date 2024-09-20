#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

// 再帰呼び出しによるDFS
int dfs(vector<vector<int>> &mp, vector<vector<bool>> &visited, int x, int y)
{
    // 範囲外
    if((x < 0) || (y < 0) || (x >= 10) || (y >= 10)) {
        return 0;
    }
    // 訪問済み
    if(visited.at(x).at(y)) {
        return 0;
    }
    // 海
    if(!mp.at(x).at(y)) {
        return 0;
    }

    // 未訪問の陸地なら更に探索
    visited.at(x).at(y) = true;
    return dfs(mp, visited, x-1, y) + dfs(mp, visited, x+1, y) + dfs(mp, visited, x, y-1) + dfs(mp, visited, x, y+1) + 1;
}

int main() {
    vector<vector<int>> mp(10, vector<int>(10));
    int land = 0;

    rep(i, 10) {
        string s;
        cin >> s;
        rep(j, 10) {
            if(s[j] == 'x') {
                mp.at(i).at(j) = 0;
            } else {
                mp.at(i).at(j) = 1;
                land++;
            }
        }
    }

    rep(i, 10) {
        rep(j, 10) {
            if(!mp.at(i).at(j)) {
                vector<vector<bool>> visited(10, vector<bool>(10, false));
                mp.at(i).at(j) = 1;
                if(dfs(mp, visited, i, j) == land+1) {
                    cout << "YES" << endl;
                    return 0;
                }
                mp.at(i).at(j) = 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
