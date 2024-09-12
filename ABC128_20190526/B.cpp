#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<tuple<string, int, int>> lst(n);
    for(int i = 0; i < n; i++) {
        cin >> get<0>(lst.at(i)) >> get<1>(lst.at(i));
        get<2>(lst.at(i)) = i;
    }
    sort(lst.begin(), lst.end());
    for(int i = 0; i < n; i++) {
        cout << get<2>(lst.at(i)) << endl;
    }
}
