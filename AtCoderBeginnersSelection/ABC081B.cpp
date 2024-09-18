#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int ans = 0;
    while(true) {
        bool fail = false;
        for(int i = 0; i < n; i++) {
            if(a.at(i) % 2 == 0) {
                a.at(i) /= 2;
            } else {
                fail = true;
                break;
            }
        }
        if(fail) {
            break;
        } else {
            ans++;
        }
    }

    cout << ans << endl;
}
