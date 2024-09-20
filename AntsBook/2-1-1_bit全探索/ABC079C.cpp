#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    for(int i = 0; i < (1 << 4); i++) {
        int val = s[0] - '0';
        for(int j = 0; j < 3; j++) {
            int c = s[j+1] - '0';
            if(i & (1 << j)) {
                val += c;
            } else {
                val -= c;
            }
        }

        if(val == 7) {
            for(int j = 0; j < 3; j++) {
                cout << s[j];
                if(i & (1 << j)) {
                    cout << "+";
                } else {
                    cout << "-";
                }
            }
            cout << s[3] << "=7" << endl;
            return 0;
        }
    }
}
