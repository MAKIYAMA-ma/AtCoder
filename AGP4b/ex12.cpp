#include <bits/stdc++.h>
using namespace std;

int main() {
    string st;
    int a = 1;

    getline(cin, st);

    for(int i = 1; i < st.size(); i = i+2) {
        if(st.at(i) == '+') {
            a += 1;
        } else if(st.at(i) == '-') {
            a -= 1;
        }
    }

    cout << a << endl;
}
