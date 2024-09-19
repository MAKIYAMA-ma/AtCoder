#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> l(n);
    for(int i = 0; i < n; i++) {
        cin >> l.at(i);
    }
    sort(l.begin(), l.end());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(l.at(i) == l.at(j)) {
                continue;
            }
            for(int k = j+1; k < n; k++) {
                if((l.at(i) == l.at(k)) || (l.at(j) == l.at(k))) {
                    continue;
                }
                if(l.at(k) < (l.at(i) + l.at(j))) {
                    /* cout << "DBG:" << l.at(i) << "," << l.at(j) << "," << l.at(k) << endl; */
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}
