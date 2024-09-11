#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    string op;
    bool er = false;

    cin >> n >> a;

    for(int i = 0; i < n; i++) {
        cin >> op >> b;
        if(!er) {
            if(op == "+") {
                a += b;
            } else if(op == "-") {
                a -= b;
            } else if(op == "*") {
                a *= b;
            } else if(op == "/") {
                if(b == 0) {
                    cout << "error" << endl;
                    er = true;
                    continue;
                } else {
                    a /= b;
                }
            }
            cout << i+1 << ":" << a << endl;
        }
    }
}
