#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;

using vi = vector<int>;
using vl = vector<ll>;
using vp = vector<pi>;
using vb = vector<bool>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vp2 = vector<vp>;

#if 0
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    // そもそもn x nのマトリクスが持てない。
    // (2*10^5)^2 * 4Byte = 149GByte
    // -> どこからどこまで到達可能かを管理しておくのは無理
    //
    // Functional Graphというらしい。
    // 各連結成分ごとに、一つの閉路とその要素を根とする有向木で構成される性質があるそうな。
    //
    // ある点からDSPする
    // いずれ閉路が見つかる
    // -> 根と閉路の個数を記録する
    // 1. 閉路の探索
    // 2. 閉路の各要素から、有向辺を逆にたどって深さの番号を振っていく
    // 3. 全部足す
    vi edge(n, 0);
    vi2 redge(n, vi());
    rep(i, n) {
        int a;
        cin >> a;
        a--;
        edge[i] = a;
        redge[a].push_back(i);
    }

    vb chkd(n, false);
#if 1
    // cycleの構成要素を探す
    // O(N)
    vl cost(n, 0);
    stack<int> cs;
    vi cl(n, 0);
    rep(i, n) {
        if(chkd[i]) {
            continue;
        }

        int pos = i;
        int cnt = 0;
        while(!cl[pos]) {
            cl[pos] = ++cnt;
            pos = edge[pos];
        }
        if(cl[pos] > 0) {
            int cst = cnt - cl[pos] + 1;
            while(cost[pos] == 0) {
                if(redge[pos].size() > 1) {
                    cs.push(pos);
                }
                cost[pos] = cst;
                pos = edge[pos];
            }
        }
        // 確認済みの頂点を改めて-1に更新する
        pos = i;
        while(cl[pos] > 0) {
            cl[pos] = -1;
            pos = edge[pos];
        }
    }
#elif 0
    // cycleの構成要素を探す
    // O(N)
    vl cost(n, 0);
    stack<int> cs;
    vi cl(n, 0);
    rep(i, n) {
        if(chkd[i]) {
            continue;
        }

        int pos = i;
        int cnt = 0;
        // 毎回ゼロのclを用意する処理が重いようだ
        fill(all(cl), 0);
        while(!chkd[pos]) {
            chkd[pos] = true;
            cl[pos] = ++cnt;
            pos = edge[pos];
        }
        if(cl[pos] > 0) {
            int cst = cnt - cl[pos] + 1;
            while(cost[pos] == 0) {
                if(redge[pos].size() > 1) {
                    cs.push(pos);
                }
                cost[pos] = cst;
                pos = edge[pos];
            }
        }
    }
#else
    // cycleの構成要素を探す
    // O(N)
    queue<pi> cp;
    rep(i, n) {
        if(chkd[i]) {
            continue;
        }

        vi cl(n, 0);
        int pos = i;
        int cnt = 0;
        while(!chkd[pos]) {
            chkd[pos] = true;
            cl[pos] = ++cnt;
            pos = edge[pos];
        }
        if(cl[pos] > 0) {
            cp.push(make_pair(pos, cnt - cl[pos] + 1));
        }
    }

    vl cost(n, 0);
    stack<int> cs;
    // cycle部分に点数をつけて、チェックスタックに追加
    // O(N)
    while(!cp.empty()) {
        auto tp = cp.front();
        cp.pop();
        int pos = tp.first;
        int cst = tp.second;
        while(cost[pos] == 0) {
            if(redge[pos].size() > 1) {
                cs.push(pos);
            }
            cost[pos] = cst;
            pos = edge[pos];
        }
    }
#endif

    // O(N)
    while(!cs.empty()) {
        auto tgt = cs.top();
        cs.pop();

        for(auto nxt: redge[tgt]) {
            if(cost[nxt] == 0) {
                cost[nxt] = cost[tgt] + 1;
                cs.push(nxt);
            }
        }
    }

    cout << reduce(all(cost)) << endl;
}
