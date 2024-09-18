#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int ans = 0;
    for(int i = 0; i <= a; i++) {
        int rest = x - i*500;
        if(rest < 0) {
            break;
        }
        for(int j = 0; j <= b; j++) {
            if(rest < 0) {
                break;
            }
            if(rest / 50 <= c) {
                ans++;
                /* cout << ">>" << i << "," << j << "," << (rest/50) << endl; */
            }
            rest -= 100;
        }
    }

    cout << ans << endl;
}
