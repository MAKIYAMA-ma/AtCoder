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
    int h, w;
    int sx, sy, gx, gy;
    ll ans = 0;

    cin >> h >> w;
    cin >> sx >> sy;
    cin >> gx >> gy;

    vector<vector<int>> p(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            cin >> p.at(i).at(j);
            ans += p.at(i).at(j);
        }
    }

    /* 当然、最終的には全てのマスを回ることになる */
    /* なのでPの値はすべて得る。 */
    /* そのうえで、初回移動時のPの積を最大化したい */
    /* 基本的には、各隣接マスについて、最大値の方向に移動するパスを採用していきたい */
    /* 最初に各マスの各方向へのポイントを計算する（4hw回程度の計算でいける） */
    /* そのうえで、点数の高いパスから順に採用していく */
    /* 未連結の2点間なら経路が作れる？ */
    /* 全て訪れたら終了。後は通った後のパスとかで適当につながる */
    priority_queue<pair<int, pair<pair<int, int>, pair<int, int>>>> q;
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    UnionFind con;
    con.init(h*w);
    rep(i, h) {
        rep(j, w) {
            rep(k, 4) {
                auto nbx = i + dx.at(k);
                auto nby = j + dy.at(k);
                if((nbx >= 0) && (nbx < h) && (nby >= 0) && (nby < w)) {
                    auto cost = p.at(i).at(j) * p.at(nbx).at(nby);
                    q.emplace(make_pair(cost, make_pair(make_pair(i, j), make_pair(nbx, nby))));
                }
            }
        }
    }
    while(!q.empty()) {
        auto cost = q.top().first;
        auto pt1 = q.top().second.first;
        auto pt2 = q.top().second.second;
        auto pt1i = pt1.first*w + pt1.second;
        auto pt2i = pt2.first*w + pt2.second;
        q.pop();

        /* cout << "DB:" << pt1i << " " << pt2i << endl; */
        if(con.same(pt1i, pt2i)) {
            continue;
        } else {
            ans += cost;
            con.merge(pt1i, pt2i);
        }
    }
    cout << ans << endl;
}
