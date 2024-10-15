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


int main() {
    int n;
    string s;
    cin >> n >> s;

    // 高橋君の手は、常にあいこと勝ちの二択
    // 連続してはいけない
    // そのうえで勝ちを最大化する
    // dpで
    vector tk(n+1, vector(3, 0));
    rep(i, n) {
        int ao;
        if(s[i] == 'R') {
            ao = 0;
        } else if(s[i] == 'P') {
            ao = 1;
        } else if(s[i] == 'S') {
            ao = 2;
        }
        tk[i+1][(ao+2)%3] = 0;  // 負ける手は不可。0にしとけば次にMaxとる過程で捨てられる
        tk[i+1][ao] = max(tk[i][(ao+1)%3], tk[i][(ao+2)%3]);    // あいこ
        tk[i+1][(ao+1)%3] = max(tk[i][(ao)%3]+1, tk[i][(ao+2)%3]+1);    // 勝ち
    }

    cout << max(tk[n][0], max(tk[n][1], tk[n][2])) << endl;
}
