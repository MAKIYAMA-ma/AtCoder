#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    for (int i = 0; i < 5; i++) {
        cin >> v.at(i);
    }

    for (int i = 0; i < v.size()-1; i++) {
        if(v.at(i) == v.at(i+1)) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
