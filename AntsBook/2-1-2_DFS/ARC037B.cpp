#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

bool is_tree(vector<vector<bool>> &uv, vector<bool> &visited, int p)
{
    if((p < 0) || (p >= uv.size())) {
        // 範囲外
        // この先はない
        /* cout << "ERR" << endl; */
        return true;
    }
    if(visited.at(p)) {
        // 循環した
        /* cout << "    VISITED:" << p+1 << endl; */
        return false;
    }

    /* cout << "    V:" << p+1 << endl; */
    visited.at(p) = true;
    bool ans = true;
    rep(i, uv.at(p).size()) {
        if(uv.at(p).at(i)) {
            uv.at(p).at(i) = false;
            uv.at(i).at(p) = false;
            /* cout << "  CUT:" << p+1 << "," << i+1 << endl; */

            // is_treeを先に実行しないと、ans=falseになったらその後はis_treeが実行されない
            /* ans = (ans && is_tree(uv, visited, i)); */
            ans = (is_tree(uv, visited, i) && ans);
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> uv(n, vector<bool>(n, false));

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        uv.at(u-1).at(v-1) = true;
        uv.at(v-1).at(u-1) = true;
    }

    int ans = 0;
    vector<bool> visited(n, false);
    rep(i, n) {
        /* cout << "DB:" << i+1 << endl; */
        if(is_tree(uv, visited, i)) {
            ans++;
        }
    }

    cout << ans << endl;
}
