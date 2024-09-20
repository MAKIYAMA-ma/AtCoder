#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    ll ans = 0;
    for(int i = 0; i < (1 << (s.length() - 1)); i++) {
        ll tmp0 = 0;
        ll tmp1 = 0;

        for(int j = 0; j < s.length(); j++) {
            tmp0 *= 10;
            tmp0 += (s[j] - '0');
            if((j == s.length() - 1) || (i & (1 << j))) {
                tmp1 += tmp0;
                tmp0 = 0;
            }
        }
        ans += tmp1;
    }

    cout << ans << endl;
}
