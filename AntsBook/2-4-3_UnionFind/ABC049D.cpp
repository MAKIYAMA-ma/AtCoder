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
    int n, k, l;
    cin >> n >> k >> l;

    UnionFind rd, ll;
    rd.init(n+1);
    ll.init(n+1);

    rep(i, k) {
        int p, q;
        cin >> p >> q;
        rd.merge(p, q);
    }
    rep(i, l) {
        int r, s;
        cin >> r >> s;
        ll.merge(r, s);
    }

    // 道と鉄道の根の組合せごとに都市数をカウント
    // mapを使ってO(N)でカウントする
    map<pair<int, int>, int> grp;
    for(int i = 1; i <= n; i++) {
        grp[make_pair(rd.root(i), ll.root(i))]++;
    }
    for(int i = 1; i <= n; i++) {
        cout << grp[make_pair(rd.root(i), ll.root(i))] << " ";
    }
    cout << endl;
}