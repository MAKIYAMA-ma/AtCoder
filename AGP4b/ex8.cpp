#include <bits/stdc++.h>
using namespace std;

int main() {
    int pt;
    int p, n;
    string txt;

    cin >> pt;

    if(pt == 2) {
        cin >> txt;
    }

    cin >> p >> n;

    if(pt == 2) {
        cout << txt << "!" << endl;
    }
    cout << p * n << endl;
}
