#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ab(n);

    rep(i, m) {
        int a, b;
        cin >> a >> b;
        ab.at(a-1) |= (1<<(b-1));
        ab.at(b-1) |= (1<<(a-1));
    }
    vector<int> od(n-1);
    rep(i, n-1) {
        od.at(i) = i+1;
    }

    int ans = 0;
    do {
        if(ab.at(0) & (1 << od.at(0))) {
            bool sc = true;
            rep(i, od.size()-1) {
                if(ab.at(od.at(i)) & (1 << od.at(i+1))) {
                } else {
                    sc = false;
                    break;
                }
            }
            if(sc) {
                ans++;
            }
        }
    } while(next_permutation(all(od)));

    cout << ans << endl;
}
