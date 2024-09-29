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

// TODO これだとTLE
int main() {
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> rd(n+1, 0);
    vector<int> ll(n+1, 0);
    rep(i, k) {
        int p, q;
        cin >> p >> q;
        merge(p, q, rd);
    }
    rep(i, l) {
        int r, s;
        cin >> r >> s;
        merge(r, s, ll);
    }

    for(int i = 1; i <= n; i++) {
        int ans = 0 ;
        for(int j = 1; j <= n; j++) {
            if(same(i, j, rd) && same(i, j, ll)) {
                /* cout << "DB:" << i << " " << j << endl; */
                ans++;
            }
        }
        cout << ans << " ";
    }
    cout << endl;
}
