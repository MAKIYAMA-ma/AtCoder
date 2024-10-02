#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


int main() {
    int n, m, s, t;
    ll money = pow(10, 15);

    cin >> n >> m >> s >> t;
    s--;
    t--;

    vector<vector<pair<int, pair<int, int>>>> map(n, vector<pair<int, pair<int, int>>>());
    rep(i, m) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        map.at(u).push_back(make_pair(v, make_pair(a, b)));
        map.at(v).push_back(make_pair(u, make_pair(a, b)));
    }


    /* ダイクストラ法でsからの各都市のyenコストを求める */
    vector<pair<ll, int>> yc(n, {pow(10, 14), 0});
    rep(i, n) {
        yc.at(i).second = i;
    }
    yc.at(s).first = 0;   // 円コストはsからのコスト
    sort(all(yc));

    /* vectorでいいのか？ */
    /* 指定の町のデータにアクセス・更新したい */
    /* コストが最低の町を取り出したい */

    vector<bool> fin(n+1, false);
    int fincnt = 0;
    fin.at(s) = true;
    fincnt++;
    int cty = s;
    while(fincnt < n) {
        int min = pow(10, 9);
        int mc = -1;
        rep(i, map.at(cty).size()) {
            if(!fin.at(map.at(cty).at(i).first)) {
                if(map.at(cty).at(i).second.first < min) {
                    min = map.at(cty).at(i).second.first;
                    mc = map.at(cty).at(i).first;
                }
            }
        }
        if(mc != -1) {
            yc.at(mc) = yc.at(cty) + min;
            fin.at(mc) = true;
            fincnt++;
            cty = mc;
        }
    }



    /* 経路上にある両替都市Xまでの円での最短経路 */
    /* Xからtへのスヌークでの最短経路 */
    /* ただし、Xはiより大きい */

    /* 各都市について、sからxへの円での最短コストを求める */
    /* 各都市について、xからtへのスヌークでの最短コストを求める */
    /* 各iについて、iより大きい都市について、両方の和が最低となる都市を採用する */
}
