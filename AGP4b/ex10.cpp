#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    int i;

    cin >> a >> b;

    i = 0;
    cout << "A:";
    while(i++ < a) {
        cout << "]";
    }
    cout << endl;

    i = 0;
    cout << "B:";
    while(i++ < b) {
        cout << "]";
    }
    cout << endl;
}
