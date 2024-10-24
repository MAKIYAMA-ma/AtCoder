#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


mint check(vector<set<int>> &xy, int pt, int blk, vm2 &ptn, vb2 &visited) {
    if(visited[pt][blk]) return ptn[pt][blk];
    if(!xy[pt].size()) {
        ptn[pt][blk] = 1;
    } else {
        ptn[pt][blk] = 1;
        for(auto y : xy[pt]) {
            xy[y].erase(pt);
            mint tmp = check(xy, y, 0, ptn, visited);
            if(!blk) {
                tmp += check(xy, y, 1, ptn, visited);
            }
            ptn[pt][blk] *= tmp;
        }
    }
    visited[pt][blk] = true;
    return ptn[pt][blk];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    // 与えられるグラフは木なので絶対塗れる
    // 各連結要素の塗り方は二通りずつしかないはず（一つ色を決めたら他は全て決まる）
    // 連結要素数kを数えて、2^kすればいい気がするが。。。DPなのかこれ？？？
    //
    // -> 違う。隣同士黒がNGだが、白同士はOK。なので連結要素の色は2種類じゃない。
    // 黒の隣接頂点は白だが、白の隣接頂点は白or黒
    //
    // でも隣接要素ごとに独立なのはその通り、
    // 各グループのパターン数の積が解
    // グループごとに考えるべき？？？
    // 各頂点が2通りずつのN段マトリクスとかは当然無理
    //
    // 点kまでで、kが白になるパターンと黒になるパターン
    // --> でもk+1番を追加するさい、これがjと隣接しているならjの色が必要。
    //
    // 辺を順になめるとかで何かできたりは？？？？
    //
    // 点を選ぶ。
    // 隣接点があればメモ化再帰で呼ぶ。
    // 木なので、戻ってくることはない。
    // でも、呼んだ相手から元の呼び出しもとをたどれてしまう。
    // かといって双方向にしないと一度で更新しきれない。
    // たどっていくなら、未更新の奴らだけ。。。
    //
    // 未チェックの点からたどっていき、その連結要素の結果が最終的に返ってくる。
    // 連結先に渡す際、そこの連結は切断する。
    // ループで回して、結果をかけていく。

    vector<set<int>> xy(n, set<int>());
    rep(i, n-1) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        xy[x].insert(y);
        xy[y].insert(x);
    }

    vm2 ptn(n, vm(2, 0));
    vb2 visited(n, vb(2, false));
    mint ans = 1;
    rep(i, n) {
        if(!visited[i][0]) {
            ans *= (check(xy, i, 0, ptn, visited) + check(xy, i, 1, ptn, visited));
        }
    }
    /* cout << "--------------" << endl; */
    /* rep(i, n) { */
    /*     cout << "> " << ptn[i][0].val() << ", " << ptn[i][1].val() << endl; */
    /* } */
    /* cout << "--------------" << endl; */
    cout << ans.val() << endl;
}
