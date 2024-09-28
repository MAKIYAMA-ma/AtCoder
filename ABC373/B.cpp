#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    string s;
    cin >> s;
    vector<int> tmp(26, 0);

    rep(i, 26) {
        tmp.at(s[i] - 'A') = i;
    }
    int ans = 0;
    rep(i, 25) {
        ans += abs(tmp.at(i+1) - tmp.at(i));
    }
    cout << ans << endl;
}
