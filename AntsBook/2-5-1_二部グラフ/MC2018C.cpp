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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        tmp--;
        a.at(i) = tmp;
    }
    vector<bool> fin(n, false);
    int fincnt = 0;

    UnionFind grp;
    grp.init(n);

    int t1, t2, t3;
    rep(i, n) {
        if(fin.at(i)) {
            continue;
        }
        t1 = i;
        while(true) {
            if(fin.at(t1)) {
                break;
            }
            t2 = a.at(t1);
            t3 = a.at(t2);

            grp.merge(t1, t3);
            fin.at(t1) = true;
            fincnt++;

            t1 = t2;
        }
    }

    int ans = 0;
    int tgt = grp.root(0);
    rep(i, n) {
        if(grp.root(i) == tgt) {
            ans++;
        }
    }
    if(ans == n) {
        cout << -1 << endl;
    } else {
        cout << max(ans, n-ans) << endl;
    }
}
