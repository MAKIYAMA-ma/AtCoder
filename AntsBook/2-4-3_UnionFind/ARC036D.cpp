#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

class UnionFind {
    public:
        vector<int> data;

        void init(int n) {
            data.resize(n, -1);
        }

        int root(int idx) {
            if(data.at(idx) == -1) {
                return idx;
            } else {
                // 深さ圧縮
                // ただし、同じグループの全要素の値が同じになるとは限らないので注意
                // (idxより根に近い要素の値は書き換わるが、idxより下の要素の値は書き換わらない。
                // その結果、2段にはなりうる。
                return (data.at(idx) = root(data.at(idx)));
            }
        }

        void merge(int a, int b) {
            int ar, br;

            if(a == b) {
                return;
            }

            ar = root(a);
            br = root(b);
            if(ar != br) {
                data.at(br) = ar;
            }
        }

        bool same(int a, int b) {
            int ar, br;

            if(a == b) {
                return true;
            }

            ar = root(a);
            br = root(b);

            return (ar == br);
        }
};

int main() {
    int n, q;
    cin >> n >> q;

    UnionFind cty;
    cty.init(n+1);

    set<pair<int, int>> er; // 奇数の道で結ばれた根のペア

    rep(i, q) {
        int w, x, y, z;
        cin >> w >> x >> y >> z;

        if(w == 1) {
            // 道路敷設
            if(z % 2) {
                // 奇数距離の道
                // 根同士の接続としてerに記録する
                // 同一群間でも記録に含める
                /* a-b間に奇数距離の道が敷設されれば、bとcはグループ化できる。 */
                /* aから奇数距離のグループが複数個あることはありえない。 */
                /* （複数個あれば、そのグループ通しが統合できる） */
                /* 統合処理は解答時にまとめて行う */
                auto xr = cty.root(x);
                auto yr = cty.root(y);
                er.insert(make_pair(xr, yr));
                if(xr != yr) {
                    er.insert(make_pair(yr, xr));
                }
            } else {
                // 偶数距離の道
                // 群どうしを即マージでOK
                cty.merge(x, y);
            }
        } else {
            // 確認
            bool changed = true;
            while(changed) {
                /* cout << "------------" << endl; */
                /* for(auto ert : er) { */
                /*     cout << ert.first << " " << ert.second << endl; */
                /* } */
                /* cout << "------------" << endl; */

                changed = false;

                /* 根の更新 */
                /* 登録後の偶数距離道の敷設で根が変わっているかもしれないので、更新 */
                for (auto iert = er.begin(); iert != er.end(); ) {
                    auto ertx = cty.root(iert->first);
                    auto erty = cty.root(iert->second);

                    if((ertx != iert->first) || (erty != iert->second)) {
                        auto updated_it = er.erase(iert);
                        er.insert({ertx, erty});
                        iert = updated_it;
                    } else {
                        iert++;
                    }
                }
                /* a群-b群、a群-b群がそれぞれ奇数距離道でつながっていれば、 */
                /* bとcはマージしてOK */
                /* マージの結果根が変わるので、処理が不要になるまで回す */
                for (auto iert = er.begin(); iert != er.end(); ) {
                    auto nxt = next(iert);
                    if(nxt == er.end()) {
                        break;
                    }
                    if(iert->first == nxt->first) {
                        cty.merge(iert->second, nxt->second);
                        er.erase(nxt);
                        changed = true;
                    } else {
                        iert++;
                    }
                }
            }

            /* 処理後、同一グループかどうかで返す */
            cout << (cty.same(x, y) ? "YES" : "NO") << endl;
        }
    }
}
