#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    sort(a.rbegin(), a.rend());

    int al = 0, bb = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2) {
            bb += a.at(i);
        } else {
            al += a.at(i);
        }
    }

    cout << al - bb << endl;
}
