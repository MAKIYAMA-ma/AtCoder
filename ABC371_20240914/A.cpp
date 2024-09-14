#include <bits/stdc++.h>
using namespace std;

int main() {
    string ab, ac, bc;
    cin >> ab >> ac >> bc;

    if (ab == "<") {
        if(ac == "<" ) {
            if(bc == "<") {
                cout << "B" << endl;
            } else {
                cout << "C" << endl;
            }
        } else {
            cout << "A" << endl;
        }
    } else {
        if(ac == "<" ) {
            cout << "A" << endl;
        } else {
            if(bc == "<") {
                cout << "C" << endl;
            } else {
                cout << "B" << endl;
            }
        }
    }
}
