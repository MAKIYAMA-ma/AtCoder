#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    bitset<100> l;
    l.reset();

    for(int i = 0; i < m; i++) {
        int a;
        string b;
        cin >> a >> b;

        if(b == "M") {
            if(l.test(a-1)) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
                l.set(a-1);
            }
        } else {
            cout << "No" << endl;
        }
    }
}
