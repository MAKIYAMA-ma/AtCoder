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
    int n, m, q;
    cin >> n >> m;

    vector<vector<pair<int, int>>> edge(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;

        edge.at(u).push_back(make_pair(v, w));
        /* edge.at(v).push_back(make_pair(u, w)); */
    }

    cin >> q;

    // 合併前のグループで既に捨てられていた辺が採用されることはない
    // あるのは、新規のグループとの辺を追加した結果、もともと使っていた辺が不要となるケース
    // -> キューに積まれたうえで使われなかった辺は、edgeから削除する？
    UnionFind con;
    con.init(n);
    vector<vector<int>> ignore(n, vector<int>(n, false));
    rep(i, q) {
        int p1, p2;
        cin >> p1 >> p2;

        // 全頂点の結合状況の管理
        con.merge(p1, p2);

        // グループ内の頂点を両端とする辺の抽出
        // 改めて抽出ではなく、一度選択した辺群を使いまわせない？
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> eq;
        int rt = con.root(p1);
        int grpsize = 0;
        rep(j, n) {
            if(con.root(j) == rt) {
                /* rep(k, edge.at(j).size()) { */
                for(int k = 0; k < edge.at(j).size();) {
                    auto cost = edge.at(j).at(k).second;
                    auto tgt = edge.at(j).at(k).first;

                    // 無視リストに入っていた辺は不採用とし、辺データからも消してしまう
                    if(ignore.at(j).at(tgt)) {
                        edge.at(j).erase(edge.at(j).begin() + k);
                    } else {
                        if(con.root(tgt) == rt) {
                            eq.emplace(make_pair(cost, make_pair(j, tgt)));
                        }
                        k++;
                    }
                }
                grpsize++;
            }
        }

        // グループ内の最小全域木の構成
        UnionFind tmp;
        int cnt = 0;
        ll ans = 0;
        tmp.init(n);
        while(!eq.empty()) {
            auto cost = eq.top().first;
            auto pk1 = eq.top().second.first;
            auto pk2 = eq.top().second.second;
            eq.pop();

            if(tmp.same(pk1, pk2)) {
                ignore.at(pk1).at(pk2) = true;
                continue;
            }
            ans += cost;
            tmp.merge(pk1, pk2);
            cnt++;
            if(cnt >= grpsize-1) {
                break;
            }
        }
        if(cnt >= grpsize-1) {
            cout << ans << endl;
            /* 余った辺は今後も不要なので無視リストに入れる */
            while(!eq.empty()) {
                auto pk1 = eq.top().second.first;
                auto pk2 = eq.top().second.second;
                eq.pop();
                ignore.at(pk1).at(pk2) = true;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
