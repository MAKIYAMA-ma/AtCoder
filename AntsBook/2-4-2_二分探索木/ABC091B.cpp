#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n, m;
    map<string, int> mp;

    cin >> n;
    rep(i, n) {
        string s;
        cin >> s;
        mp[s]++;
    }

    cin >> m;
    rep(i, m) {
        string s;
        cin >> s;
        mp[s]--;
    }

    int ans = 0;
    for(auto p: mp) {
        ans = max(ans, p.second);
    }

    cout << ans << endl;
}
