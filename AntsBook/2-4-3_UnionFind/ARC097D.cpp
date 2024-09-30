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
    int n, m;
    cin >> n >> m;

    vector<int> p(n+1, 0);
    UnionFind xy;
    xy.init(n+1);

    rep(i, n) cin >> p.at(i+1);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        xy.merge(x, y);
    }

    /**
     * もともとあっている場所を入れ替える意味はない
     * 入れ替えても、スコアは0 or -1
     * 一つ犠牲にすることで、後々スコアを増やせるということもないはず
     *
     * xyで繋がっている各要素は、順序を好きなように入れ替えられる
     * -> xyで繋がっているグループごとに、index列と、そこに現在含まれる数値列の、重複要素数が最大スコア
     * (1) xyでUnionFindを作る
     * (2) 現在入っている各要素と、そのindexの親を対応づける
     **/
    vector<int> vg(n+1, -1);
    for(int i = 1; i <= n; i++) {
        auto val = p.at(i);
        vg.at(val) = xy.root(i);
    }

    /* cout << "------------" << endl; */
    /* for(int i = 1; i <= n; i++) { */
    /*     cout << vg.at(i) << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "------------" << endl; */
    /* for(int i = 1; i <= n; i++) { */
    /*     cout << xy.root(i) << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "------------" << endl; */

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vg.at(i) == xy.root(i)) {
            ans++;
        }
    }
    cout << ans << endl;
}
