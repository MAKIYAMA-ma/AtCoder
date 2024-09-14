#include <bits/stdc++.h>
using namespace std;

/* 28 */
int main() {
    int n;
    int mg, mh;

    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<vector<int>> h(n, vector<int>(n, 0));

    cin >> mg;
    for(int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        g.at(u-1).at(v-1) = 1;
        g.at(v-1).at(u-1) = 1;
    }

    cin >> mh;
    for(int i = 0; i < mh; i++) {
        int u, v;
        cin >> u >> v;
        h.at(u-1).at(v-1) = 1;
        h.at(v-1).at(u-1) = 1;
    }

    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int ain;
            cin >> ain;
            a.at(i).at(j) = ain;
        }
    }

    int min_ans = -1;
    vector<int> ind;
    for(int i = 0; i < n; i++) {
        ind.push_back(i);
    }
    do {
        vector<vector<int>> d(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                d.at(i).at(j) = ((h.at(i).at(j)) != (g.at(ind.at(i)).at(ind.at(j))));
            }
        }
        int ans = 0;
        /* cout << "---------------" << endl; */
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(d.at(i).at(j)) {
                    /* cout << i << " " << j << " " << a.at(i).at(j) << endl; */
                    ans += a.at(i).at(j);
                }
            }
        }
        /* cout << "---------------" << endl; */
        /* cout << ans << endl; */
        if(min_ans < 0) {
            min_ans = ans;
        } else if(min_ans > ans) {
            min_ans = ans;
        }
    } while (next_permutation(ind.begin(), ind.end()));
    cout << min_ans << endl;
}
