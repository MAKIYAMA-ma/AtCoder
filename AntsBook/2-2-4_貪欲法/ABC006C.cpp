#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;
    vector<int> bx;

    rep(i, n) {
        int w;
        cin >> w;

        auto lp = lower_bound(all(bx), w);
        if(lp == bx.end()) {
            bx.push_back(w);
        } else {
            *lp = w;
            sort(all(bx));
        }
    }

    cout << bx.size() << endl;
}
