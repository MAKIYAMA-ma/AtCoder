#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    string s;
    cin >> s;
    rep(i, s.length()) {
        if(s[i] != '.') {
            cout << s[i];
        }
    }
    cout << endl;
}
