#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> rd(n);
    vector<pair<int, int>> bl(n);
    rep(i, n) {
        cin >> rd.at(i).first >> rd.at(i).second;
    }
    rep(i, n) {
        cin >> bl.at(i).first >> bl.at(i).second;
    }
    sort(all(rd));
    sort(all(bl));

    int ans = 0;
    queue<pair<int, int>> rdq;
    rep(i, n) {
        rdq.push(rd.at(i));
    }
    while(!rdq.empty()) {
        auto rp = rdq.front();
        rdq.pop();

        queue<pair<int, int>> blcp;
        copy_if(all(bl), back_inserter(blcp), [](const pair<int, int> &a) {
                return ((a.first > rp.first) && (a.second > rp.second));
                });


        auto bp = upper_bound(all(bl), rp, [](const pair<int, int> &a, const pair<int, int> &b) {
                return ((a.first < b.first) && (a.second < b.second));
                });
        if(bp != bl.end()) {
            ans++;
            bl.erase(bp);
        }
    }

    cout << ans << endl;
}
