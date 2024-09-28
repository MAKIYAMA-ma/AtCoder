#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    vector<string> s(12);
    rep(i, 12) cin >> s.at(i);

    int ans = 0;
    rep(i, 12) {
        if(s.at(i).length() == i+1) {
            ans++;
        }
    }
    cout << ans << endl;
}
