#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

// bitsetを使う場合
void func1(void) {
    int n, m;
    cin >> n >> m;

    vector<bitset<9>> p(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        p.at(a) |= bitset<9>(0x1 << b);
        p.at(b) |= bitset<9>(0x1 << a);
    }

    vector<int> od(n-1, 0);
    for(int i = 0; i < n-1; i++) {
        od.at(i) = i+2;
    }

    int ans = 0;
    // 二番目以降の頂点の順序を全列挙
    do {
        int cp = 1;
        bool sc = true;
        for(auto np : od) {
            if(p.at(cp).test(np)) {
                cp = np;
            } else {
                sc = false;
                break;
            }
        }
        if(sc) {
            ans++;
        }
    } while (next_permutation(od.begin(), od.end()));

    cout << ans << endl;
}

// intを使う場合
void func2(void) {
    int n, m;
    cin >> n >> m;

    vector<int> p(n+1);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        p.at(a) |= (0x1 << b);
        p.at(b) |= (0x1 << a);
    }

    vector<int> od(n-1, 0);
    for(int i = 0; i < n-1; i++) {
        od.at(i) = i+2;
    }

    int ans = 0;
    // 二番目以降の頂点の順序を全列挙
    do {
        int cp = 1;
        bool sc = true;
        for(auto np : od) {
            if(p.at(cp) & (0x1 << np)) {
                cp = np;
            } else {
                sc = false;
                break;
            }
        }
        if(sc) {
            ans++;
        }
    } while (next_permutation(all(od)));

    cout << ans << endl;
}

int main() {
    func1();
}
