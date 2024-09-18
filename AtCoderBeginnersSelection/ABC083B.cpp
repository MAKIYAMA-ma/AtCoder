#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int val = 0;
        int tmp = i;
        while(tmp > 0) {
            val += (tmp%10);
            tmp /= 10;
        }
        if((val >= a) && (val <= b)) {
            ans += i;
        }
    }
    cout << ans << endl;
}
