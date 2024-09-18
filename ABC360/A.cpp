#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;

    cin >> s;

    for(auto c : s) {
        if(c == 'R') {
            cout << "Yes" << endl;
            return 0;
        }
        if(c == 'M') {
            cout << "No" << endl;
            return 0;
        }
    }
}
