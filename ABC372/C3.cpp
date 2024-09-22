#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int ans = 0;
    rep(i, n-2) {
        if(s.substr(i, 3) == "ABC") {
            ans++;
        }
    }
    /* cout << "DB" << parts.size() << endl; */

    rep(i, q) {
        int x;
        char c;

        cin >> x >> c;
        int tp = x-1;

        for(int j = tp-2; j <= tp; j++) {
            if(j >= 0) {
                if(s.substr(j, 3) == "ABC") {
                    ans--;
                }
            }
        }
        s[tp] = c;
        for(int j = tp-2; j <= tp; j++) {
            if(j >= 0) {
                if(s.substr(j, 3) == "ABC") {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
