#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    string s, t;
    cin >> s >> t;
    rep(i, s.length()) {
        if(s[i] != t[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    if(s.length() != t.length()) {
        cout << min(s.length(), t.length())+1 << endl;
    } else {
        cout << 0 << endl;
    }
}
