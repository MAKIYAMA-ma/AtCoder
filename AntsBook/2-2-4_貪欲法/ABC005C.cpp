#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int t, n, m;
    cin >> t >> n;

    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }

    cin >> m;
    vector<int> b(m);
    rep(i, m) {
        cin >> b.at(i);
    }

    rep(i, m) {
        auto tgta = lower_bound(all(a), max(0, b.at(i)-t));
        if(tgta == a.end()) {
            cout << "no" << endl;
            return 0;
        } else if(*tgta > b.at(i)) {
            cout << "no" << endl;
            return 0;
        } else {
            a.erase(tgta);
        }
    }
    cout << "yes" << endl;
}
