#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

//        |このあたりで切ればまとめて対応可能
// -----------
//     -----------------
//       ---
//             -----------
//                             ---
// -> 貪欲法で区間スケジューリングとして解けばよい。
// 最多の範囲を選択したら、それらは全て個別に分割必要。
// 選ばれなかった区間群は、他の区間を切る際に一緒に切れるということ。

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> ab(m);
    rep(i, m) {
        int a, b;
        cin >> ab.at(i).second >> ab.at(i).first;
    }
    sort(all(ab));

    int ans = 0;
    int cur = 0;
    rep(i, m) {
        if(cur <= ab.at(i).second) {
            ans++;
            cur = ab.at(i).first;
        }
    }

    cout << ans << endl;
}
