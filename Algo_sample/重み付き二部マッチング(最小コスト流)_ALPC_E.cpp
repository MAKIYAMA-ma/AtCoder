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
using vs = vector<string>;

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
#define Def(n) ll n; cin >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
const int MAXI = 1e9;
const int MINI = -1e9;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 1 ≤ N ≤ 50
    // 1 ≤ K ≤ N
    // 0 ≤ Ai,j ≤ 10^9
    // 行,列いずれの方向でもK個以内になるようにマスを選び、aの総和を最大化する
    Def(n);
    Def(k);
    vl2 a(n, vl(n));
    rep(i, n) rep(j, n) cin >> a[i][j];

    // 行と列のマッチングを行う。
    // 各行にstartから流量Kの枝を張り、各列からgoalにも流量Kの枝を張る。
    // 各行と列の間は流量1の枝を張り、コストは-aとする。
    // コストを最小化するように、n*kの流量を流す。
    mcf_graph<ll, ll> graph(n*2 + 2);
    int sp = n*2;
    int gp = n*2 + 1;

    // 得点ナシで流すことも許す(n*kを流しきるためにコストを犠牲にする事がないように）
    graph.add_edge(sp, gp, n*k, MAXLL);
    rep(i, n) {
        graph.add_edge(sp, i, k, 0);
        graph.add_edge(n+i, gp, k, 0);
    }
    rep(i, n) {
        rep(j, n) {
            graph.add_edge(i, n+j, 1, MAXLL - a[i][j]);
        }
    }
    auto ans = graph.flow(sp, gp, n*k);
    auto cells = graph.edges();
    vector<vector<char>> map(n, vector<char>(n, '.'));
    for(auto p : cells) {
        if(p.from == sp || p.to == sp || p.from == gp || p.to == gp) continue;
        if(p.flow == 0) continue;
        int pl = p.from;
        int pr = p.to - n;
        map[pl][pr] = 'X';
    }

    cout << -ans.second + MAXLL*ans.first << endl;
    rep(i, n) {
        rep(j, n) {
            cout << map[i][j];
        }
        cout << endl;
    }
}
