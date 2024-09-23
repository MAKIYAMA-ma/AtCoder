#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> range(n);

    rep(i, n) {
        int x, l;
        cin >> x >> l;
        range.at(i).first = (x+l);
        range.at(i).second = (x-l);
    }
    /* 終了が早い順にソート */
    sort(all(range));

    int acpt = 0;
    /* かぶらない範囲でなるべく残り時間が多い（終了が早い）ものを選択する */
    /* 終了が早い順ソートしているので、前から順にかぶらないのを選べばよい */
    int latest = range.at(0).second;
    rep(i, n) {
        /* cout << "DB:" << latest << " " << range.at(i).second << endl; */
        if(latest <= range.at(i).second) {
            // 採用
            latest = range.at(i).first;
            acpt++;
        } else {
            // 予定キャンセル
        }
    }
    cout << acpt << endl;
}
