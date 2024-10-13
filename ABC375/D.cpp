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

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    string s;
    cin >> s;

    // 同じ文字のインデックスがどこに現れるか
    vector<vector<ll>> al(26);
    rep(i, s.length()) {
        al.at(s[i]-'A').push_back(i);
    }

    ll ans = 0;
#if 1
    vector<vector<ll>> sum(26);
    // そこまでのIndexの累積を計算
    rep(i, 26) {
        rep(j, al.at(i).size()) {
            if(j == 0) {
                sum.at(i).push_back(al.at(i).at(j));
            } else {
                sum.at(i).push_back(sum.at(i).at(j-1) + al.at(i).at(j));
            }
        }
    }
    // 尺取り法的な感じで
    rep(i, 26) {
        int l = al.at(i).size()-1;
        for(int r = al.at(i).size()-1; r >= 0; r--) {
            for(; l >= 0; l--) {
                if(al.at(i).at(r) >= (al.at(i).at(l) + 2)) {
                    ans += (al.at(i).at(r) - 1) * (l + 1) - sum.at(i).at(l);
                    break;
                }
            }
        }
    }
#else
    // 次の同じ文字までの文字数をカウント
    // これだとO(N2)でTLE
    rep(i, 26) {
        if(al.at(i).size() > 0) {
            rep(l, al.at(i).size()) {
                rep(r, al.at(i).size()) {
                    if(al.at(i).at(r) >= (al.at(i).at(l) + 2)) {
                        ans += (al.at(i).at(r) - al.at(i).at(l) - 1);
                    }
                }
            }
        }
    }
#endif
    cout << ans << endl;
}
