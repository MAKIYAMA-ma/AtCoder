#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


int main() {
    int n, m;
    cin >> n >> m;

    // 奇数距離にあり、かつ直接の辺がないのが追加できる辺
    // 別ルートで偶数距離があっても、奇数のパスがあればOK
    vector<vector<int>> ab(n, vector<int>());
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        ab.at(a).push_back(b);
        ab.at(b).push_back(a);
    }

    vector<int> grp(n, -1);
    vector<bool> fin(n, false);
    stack<int> st;

    int grp0 = 0;
    int grp1 = 0;
    bool bing = true;

    // 連結グラフなので、一点からの探索で全てたどれる
    grp.at(0) = 0;
    grp0++;
    st.push(0);
    while(!st.empty()) {
        auto tmp = st.top();
        st.pop();
        if(fin.at(tmp)) {
            continue;
        }
        rep(i, ab.at(tmp).size()) {
            auto tmp2 = ab.at(tmp).at(i);
            int ngrp = (grp.at(tmp) + 1) % 2;

            if(grp.at(tmp2) == -1) {
                grp.at(tmp2) = ngrp;
                if(ngrp) {
                    grp1++;
                } else {
                    grp0++;
                }
            } else if(grp.at(tmp2) != ngrp){
                bing = false;
                goto finish;
            }
            st.push(tmp2);
        }
        fin.at(tmp) = true;
    }

finish:
    if(bing) {
        cout << (ll)grp0 * grp1 - m << endl;
    } else {
        cout << (ll)n*(n-1)/2 - m << endl;
    }
}
