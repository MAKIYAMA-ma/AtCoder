#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        tmp--;
        a.at(i) = tmp;
    }

    vector<int> grp(n, -1);
    vector<bool> fin(n, false);
    int ans0 = 0;
    int ans1 = 0;
    stack<int> st;

    rep(i, n) {
        if(fin.at(i)) {
            continue;
        }
        grp.at(i) = 0;
        ans0++;
        st.push(i);
        while(!st.empty()) {
            auto tgt = st.top();
            st.pop();
            if(fin.at(tgt)) {
                continue;
            }
            auto ngrp = ((grp.at(tgt)+1)%2);
            /* cout << "DB:" << a.at(tgt) << " " << grp.at(a.at(tgt)) << " " << ngrp << endl; */
            if(grp.at(a.at(tgt)) == -1) {
                grp.at(a.at(tgt)) = ngrp;
                if(ngrp) {
                    ans1++;
                } else {
                    ans0++;
                }
            } else if(grp.at(a.at(tgt)) != ngrp) {
                cout << -1 << endl;
                return 0;
            }
            fin.at(tgt) = true;
            st.push(a.at(tgt));
        }
    }
    /* cout << "--------------" << endl; */
    /* rep(i, n) { */
    /*     cout << grp.at(i) << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "--------------" << endl; */
    cout << max(ans0, ans1) << endl;
}
