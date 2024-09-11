#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string op;
    string res;

    cin >> a >> op >> b;
    if(op == "+") {
        res = to_string(a + b);
    } else if(op == "-") {
        res = to_string(a - b);
    } else if(op == "*") {
        res = to_string(a * b);
    } else if(op == "/") {
        if(b == 0) {
            res = "error";
        } else {
            res = to_string(a / b);
        }
    } else {
        res = "error";
    }

    cout << res << endl;

    return 0;
}
