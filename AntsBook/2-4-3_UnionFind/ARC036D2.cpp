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
    // 後半n個は奇数位置
    cty.init(2*n+1);

    rep(i, q) {
        int w, x, y, z;
        cin >> w >> x >> y >> z;

        if(w == 1) {
            // 道路敷設
            if(z % 2) {
                // 奇数距離の道
                // 偶数位置と奇数位置をマージする
                cty.merge(y, n+x);
                cty.merge(x, n+y);
            } else {
                // 偶数距離の道
                // 偶数位置同士、奇数位置同士でマージする
                cty.merge(x, y);
                cty.merge(x+n, y+n);
            }
        } else {
            // 確認
            /* 処理後、同一グループかどうかで返す */
            /* cout << "----------" << endl; */
            /* for(int j = 1; j <= n; j++) { */
            /*     cout << cty.root(j) << " "; */
            /* } */
            /* cout << endl; */
            /* for(int j = n+1; j <= 2*n; j++) { */
            /*     cout << cty.root(j) << " "; */
            /* } */
            /* cout << endl; */
            /* cout << "----------" << endl; */
            cout << ((cty.same(x, y) || cty.same(n+x, n+y)) ? "YES" : "NO") << endl;
        }
    }
}
