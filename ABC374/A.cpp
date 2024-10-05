#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    string s;
    cin >> s;

    int len = s.length();
    if(s[len-3] == 's' && s[len-2] == 'a' && s[len-1] == 'n') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
