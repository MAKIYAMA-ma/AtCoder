#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    int a, b;

    cin >> n >> m;

    vector<vector<char>> r(n, vector<char>(n, '-'));

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        r.at(a-1).at(b-1) = 'o';
        r.at(b-1).at(a-1) = 'x';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << r.at(i).at(j);
            if(j == n-1) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}
