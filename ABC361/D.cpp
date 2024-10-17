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
    string s, t;
    cin >> n >> s >> t;

    s = s + "..";
    t = t + "..";

    // 隣接する2個単位で要素を移動して行くことにより、sをtにできるか？
    // できるなら何手で可能か？
    // 不可能なら-1とする
    // BWBWBW..
    // BW..BWBW
    // BWWBB..W
    // ..WBBBWW
    // WWWBBB..
    // NとN+1をセットで移動することもあり得るので2個単位で交換するのとは違う
    //
    // 実際の手順を探索するというよりは、
    // 違う石の数や配置から計算できたりしそうな気も。
    // ---> BFSらしい

    queue<string> q;
    map<string, int> cost;

    cost[s] = 0;
    q.push(s);
    while(!q.empty()) {
        bool finish = false;
        auto nxt = q.front();
        q.pop();

        int ep = 0; // 空き位置
        rep(i, nxt.length() - 1) {
            if(nxt[i] == '.') {
                ep = i;
                break;
            }
        }
        int ns_cost = cost[nxt] + 1;
        rep(i, nxt.length() - 1) {
            if((i >= ep-1) && (i <= ep+1)) {
                continue;
            }
            string ns = nxt;
            ns[ep] = ns[i];
            ns[ep+1] = ns[i+1];
            ns[i] = '.';
            ns[i+1] = '.';

            /* cout << "DB:" << nxt << ":" << ns << endl; */

            auto nsc = cost.find(ns);
            if(nsc == cost.end()) {
                cost[ns] = ns_cost;
                q.push(ns);
                if(ns == t) {
                    finish = true;
                    break;
                }
            }
        }
        if(finish) {
            break;
        }
    }

    auto ans = cost.find(t);
    if(ans != cost.end()) {
        cout << (ans->second) << endl;
    } else {
        cout << -1 << endl;
    }
}
