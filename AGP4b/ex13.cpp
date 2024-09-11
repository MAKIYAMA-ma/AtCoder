#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> a(n, 0);

    int ave = 0;
    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
        ave += a.at(i);
    }
    ave /= n;

    for(int i = 0; i < n; i++) {
        cout << abs(a.at(i) - ave) << endl;
    }
}
