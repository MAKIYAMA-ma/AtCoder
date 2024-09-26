#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;

    vector<int> pt;
    pt.push_back(0);

    rep(i, n) {
        int p;
        cin >> p;
        int tmp = pt.size();
        rep(j, tmp) {
            pt.push_back(pt.at(j) + p);
        }
        sort(all(pt));
        pt.erase(unique(all(pt)), pt.end());
    }

    cout << pt.size() << endl;
}
