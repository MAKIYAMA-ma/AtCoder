#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


/**
 * @brief 深さ可変のループをしたいので、再帰関数で実現
 *
 * @param ar
 * @param r
 * @param k
 * @param tgt
 */
void sch(vector<int> &ar, vector<int> &r, int k, int tgt) {
    if(tgt == ar.size()) {
        int sum = 0;
        rep(i, ar.size()) {
            sum += ar.at(i);
        }
        if(sum % k == 0) {
            rep(i, ar.size()) {
                cout << ar.at(i) << " ";
            }
            cout << endl;
        }
    } else {
        for(int i = 1; i <= r.at(tgt); i++) {
            ar.at(tgt) = i;
            sch(ar, r, k, tgt+1);
        }
    }
    return;
}


int main() {
    int n, k;
    cin >> n >> k;
    vector<int> r(n);
    rep(i, n) {
        cin >> r[i];
    }

    // nが小さいし、全探索でいいと思う
    // でも一つ答えが見つかったらK刻みで十分だが
    // 問題は、こういう時の探索はどうやるのが良いのか？
    vector<int> ar(n, 1);
    sch(ar, r, k, 0);
}
