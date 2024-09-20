#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

/* stackを用いてDFSを行う */
bool judge_stack(vector<vector<int>> mp, int l, int x, int y)
{
    stack<pair<int, int>> st;
    int cnt = 0;

    mp.at(x).at(y) = 1;
    st.push(make_pair(x, y));
    while(!st.empty()) {
        auto p = st.top();
        st.pop();

        if(mp.at(p.first).at(p.second) == 1) {
            cnt++;
            mp.at(p.first).at(p.second) = 2;

            if(cnt >= l) {
                return true;
            }

            if(p.first > 0) {
                if(mp.at(p.first-1).at(p.second) == 1) {
                    st.push(make_pair(p.first-1, p.second));
                }
            }
            if(p.first < 9) {
                if(mp.at(p.first+1).at(p.second) == 1) {
                    st.push(make_pair(p.first+1, p.second));
                }
            }
            if(p.second > 0) {
                if(mp.at(p.first).at(p.second-1) == 1) {
                    st.push(make_pair(p.first, p.second-1));
                }
            }
            if(p.second < 9) {
                if(mp.at(p.first).at(p.second+1) == 1) {
                    st.push(make_pair(p.first, p.second+1));
                }
            }
        }
    }
    if(cnt >= l) {
        return true;
    } else {
        return false;
    }
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
                if(judge_stack(mp, land+1, i, j)) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
