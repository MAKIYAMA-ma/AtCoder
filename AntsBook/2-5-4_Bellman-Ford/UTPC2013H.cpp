#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> xy(n, {0, 0});
    vector<pair<int, int>> ab(n, {0, 0});
    rep(i, m) {
        cin >> xy.at(i).first >> xy.at(i).second >> ab.at(i).first >> ab.at(i).second;
    }
}
