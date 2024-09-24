#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    string sd, t;
    cin >> sd >> t;

    vector<string> cand;
    rep(i, sd.length() - t.length() + 1) {
        bool ok = true;
        /* ?込みでTが作れるかどうか判定 */
        rep(j, t.length()) {
            if((sd[i+j] != '?') && (sd[i+j] != t[j])) {
                ok = false;
                break;
            }
        }
        /* Tが作れるなら、該当部分はT、残りの?はaで埋めた文字列を生成 */
        if(ok) {
            string tmp;
            rep(j, sd.length()) {
                if(sd[j] == '?') {
                    tmp += 'a';
                } else {
                    tmp += sd[j];
                }
            }
            rep(j, t.length()) {
                tmp[i+j] = t[j];
            }
            /* cout << "[" << tmp << "]" << endl; */
            cand.push_back(tmp);
        }
    }
    if(cand.size() == 0) {
        cout << "UNRESTORABLE" << endl;
    } else {
        /* 候補の中から辞書最小要素を出力 */
        sort(all(cand));
        cout << cand.at(0) << endl;
    }
}
