#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    bool sc = true;
    cin >> s >> t;

    for(int i = 1; i < s.length(); i++) {
        for(int j = 0; j < i; j++) {
            if(i*t.length()+j <= s.length()-1) {
                /* cout << "NG0:" << i << " " << j << endl; */
                continue;
            } else if(i*(t.length()-1) + j > s.length()-1) {
                /* cout << "NG1:" << i << " " << j << endl; */
                continue;
            }

            int ind = j;
            int indt = 0;
            sc = true;
            while(ind < s.length()) {
                if(s[ind] != t[indt]) {
                    sc = false;
                    /* cout << "NG:" << i << " " << j << endl; */
                    /* cout << "   " << s[ind] << " " << t[indt] << endl; */
                    break;
                } else {
                    /* cout << "    " << s[ind] << endl; */
                    ind += i;
                    indt++;
                }
            }
            if(sc) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
