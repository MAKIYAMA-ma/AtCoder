#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

/* 全探索 */
/* これだとTLE */
bool judge(string &s, string &t, vector<int> &q, int pos, int cr) {
    if((pos >= q.size()) || (cr > 26)) {
        return (s.find(t) != string::npos);
    } else {
        s[q.at(pos)] = 'a' + cr;
        rep(i, 26) {
            if(judge(s, t, q, pos+1, i)) {
                return true;
            }
        }
        return false;
    }
}

int main() {
    string sd, t;
    cin >> sd >> t;

    vector<int> q;
    rep(i, sd.length()) {
        if(sd[i] == '?') {
            q.push_back(i);
        }
    }
    if(judge(sd, t, q, 0, 0)) {
        cout << sd << endl;
    } else {
        cout << "UNRESTORABLE" << endl;
    }
}
