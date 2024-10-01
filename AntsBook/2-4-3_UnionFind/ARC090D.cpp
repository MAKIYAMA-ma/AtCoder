#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

class UnionFind_Weighted {
    public:
        vector<int> data;
        vector<int> weight;

        void init(int n) {
            data.resize(n, -1);
            weight.resize(n, 0);
        }

        int root(int idx) {
            if(data.at(idx) == -1) {
                return idx;
            } else {
                // 深さ圧縮
                int nrt = root(data.at(idx));
                weight.at(idx) += weight.at(data.at(idx));
                return (data.at(idx) = nrt);
            }
        }

        /**
         * @brief aからbまでの重みがwであるようにマージする
         *
         * @param a
         * @param b
         * @param w
         *
         * @return 成功/失敗
         * 失敗は、aとbが既に同一Unionの場合に、wの値が矛盾したら失敗とみなす
         */
        bool merge(int a, int b, int w) {
            int ar, br;
            int nw = 0;

            if(a == b) {
                if(w == 0) {
                    return true;
                } else {
                    return false;
                }
            }

            ar = root(a);
            br = root(b);
            nw = w + weight.at(a) - weight.at(b);
            if(ar != br) {
                data.at(br) = ar;
                weight.at(br) = nw;
                return true;
            } else {
                if(weight.at(br) == nw) {
                    return true;
                } else {
                    return false;
                }
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

        int diff(int a, int b) {
            if(same(a, b)) {
                return weight.at(b) - weight.at(a);
            }
            return -1;
        }
};

int main() {
    int n, m;
    cin >> n >> m;

    UnionFind_Weighted man;
    man.init(n);

    bool ans = true;
    rep(i, m) {
        int l, r, d;
        cin >> l >> r >> d;
        if(!man.merge(l-1, r-1, d)) {
            ans = false;
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
}
