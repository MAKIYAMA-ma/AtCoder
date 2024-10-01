#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


int main() {
    int n;
    cin >> n;

    vector<vector<int>> odd(n, vector<int>());
    vector<vector<int>> even(n, vector<int>());
    rep(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        if(w % 2) {
            odd.at(u).push_back(v);
            odd.at(v).push_back(u);
        } else {
            even.at(u).push_back(v);
            even.at(v).push_back(u);
        }
    }

    vector<int> col(n, -1);
    vector<bool> fin(n, false);
    stack<int> st;

    /* cout << "----------" << endl; */
    /* rep(i, n) { */
    /*     cout << i << endl; */
    /*     cout << "  ODD:"; */
    /*     rep(j, odd.at(i).size()) { */
    /*         cout << odd.at(i).at(j) << " "; */
    /*     } */
    /*     cout << endl; */
    /*     cout << "  EVN:"; */
    /*     rep(j, even.at(i).size()) { */
    /*         cout << even.at(i).at(j) << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "----------" << endl; */

    rep(i, n) {
        if(fin.at(i)) {
            continue;
        }

        st.push(i);
        while(!st.empty()) {
            auto pk = st.top();
            st.pop();
            /* cout << pk << endl; */
            if(fin.at(pk)) {
                continue;
            }
            if(col.at(pk) == -1) {
                col.at(pk) = 0;
            }
            fin.at(pk) = true;

            rep(j, odd.at(pk).size()) {
                auto tmp = odd.at(pk).at(j);
                col.at(tmp) = ((col.at(pk) + 1) % 2);
                st.push(tmp);
            }
            rep(j, even.at(pk).size()) {
                auto tmp = even.at(pk).at(j);
                col.at(tmp) = col.at(pk);
                st.push(tmp);
            }
        }
    }
    rep(i, n) {
        cout << col.at(i) << endl;
    }
}
