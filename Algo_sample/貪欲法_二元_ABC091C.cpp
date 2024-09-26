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
    sort(rd.rbegin(), rd.rend());
    sort(all(bl));

    int ans = 0;
    /* RのX最大から降順に貪欲する */
    queue<pair<int, int>> rdq;
    rep(i, n) {
        rdq.push(rd.at(i));
    }
    while(!rdq.empty()) {
        /* 残るRからX最大のものを取得 */
        auto rp = rdq.front();
        rdq.pop();

        /* 残るBから、rpとペアになれる点のリストを取得 */
        vector<pair<int, int>> blcp;
        copy_if(all(bl), back_inserter(blcp), [rp](const pair<int, int>& a) {
                return ((a.first > rp.first) && (a.second > rp.second));
                });
        if(blcp.size()) {
            /* 候補が存在した場合、その中からY最小のものを選んでペアとして使用する */
            /* 候補の点は、残存RのうちX最大の点よりXが多い点たちなので、Xの観点ではどれを残しても今後のペア形成に影響しない */
            /* なので、Y最弱の点を選べば最善 */
            sort(all(blcp), [](const pair<int, int>& a, const pair<int, int>& b) {
                    if(a.second == b.second) { return (a.first < b.first); }
                    else { return (a.second < b.second); }
                    });
            /* そもそもblからコピーしたので絶対存在する */
            auto blp = find(all(bl), *blcp.begin());
            bl.erase(blp);
            ans++;
        }
    }

    cout << ans << endl;
}
