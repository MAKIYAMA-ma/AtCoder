#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int root(int a, vector<int> &pl) {
    if(pl.at(a) == 0) {
        return a;
    } else {
        return (pl.at(a) = root(pl.at(a), pl));
    }
}

bool same(int a, int b, vector<int> &pl) {
    int ar, br;
    int tmp = a;

    if(a == b) {
        return true;
    }

    ar = root(a, pl);
    br = root(b, pl);

    return (ar == br);
}

void merge(int a, int b, vector<int> &pl) {
    int ar, br;
    int tmp = a;

    if(a == b) {
        return;
    }

    ar = root(a, pl);
    br = root(b, pl);

    if(ar != br) {
        /* cout << "DB:" << ar << " " << br << endl; */
        pl.at(br) = ar;
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> ps(n+1, 0);
    rep(i, q) {
        int p, a, b;
        cin >> p >> a >> b;

        if(p) {
            // 判定クエリ
            cout << (same(a, b, ps) ? "Yes" : "No") << endl;
        } else {
            // 連結クエリ
            merge(a, b, ps);
        }
    }
}
