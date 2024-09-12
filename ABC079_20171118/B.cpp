#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int64_t l0 = 2, l1 = 1;
    int64_t ll = l1, lo = l0;

    if(n > 1) {
        for(int i = 2; i <= n; i++) {
            swap(ll, lo);
            ll += lo;
        }
        cout << ll << endl;
    } else {
        cout << l1 << endl;
    }
}
