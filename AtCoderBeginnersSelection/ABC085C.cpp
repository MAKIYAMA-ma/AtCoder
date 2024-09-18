#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, y;
    cin >> n >> y;

    int n10, n5, n1;
    bool sc = false;

    for(int i = 0; i <= n; i++) {
        n10 = i;
        for(int j = 0; j <= (n-n10); j++) {
            n5 = j;
            n1 = n - (n10 + n5);

            if((10000*n10 + 5000*n5 + 1000*n1) == y) {
                sc = true;
                break;
            }
        }
        if(sc) {
            break;
        }
    }

    if(sc) {
        cout << n10 << " " << n5 << " " << n1 << endl;
    } else {
        cout << -1 << " " << -1 << " " << -1 << endl;
    }
}
