#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int m;
    cin >> m;

    vector<int> a(11, 0);
    int n = 0;
    for(int i = 0; i <= 10; i++) {
        int base = 3;
        if((m % base) != 0) {
            a.at(i) = (m%base);
            /* cout << "DE:" << i << " " << a.at(i) << endl; */
            n += a.at(i);
        }
        m/=3;
    }
    cout << n << endl;
    rep(i, a.size()) {
        rep(j, a.at(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}
