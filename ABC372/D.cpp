#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) {
        cin >> h.at(i);
    }
    vector<int> cnt(n, 0);
    rep(i, n) {
        int j;
        for(j = i-1; j >= 0; j--) {
            cnt.at(j)++;
            if(h.at(j) > h.at(i)) {
                break;
            }
        }
    }

    rep(i, n) {
        cout << cnt.at(i) << " ";
    }
    cout << endl;
}
