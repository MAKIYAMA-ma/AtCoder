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

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(ll i = (ll)(s); i < (ll)(n); i++)
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

void dijkstra(vpl2 &graph, ll start, vl &cost) {
    priority_queue<pl, vpl, greater<pl>> q;   // {cost, index}
    cost.at(start) = 0;
    q.push(make_pair(0, start));

    while(!q.empty()) {
        auto from = q.top().second;
        auto cst = q.top().first;
        q.pop();

        if(cost.at(from) < cst) {
            // 取得した情報が古い（最短でない）
            continue;
        }
        rep(i, graph.at(from).size()) {
            int to = graph.at(from).at(i).first;
            ll nc = graph.at(from).at(i).second + cst;

            if(nc < cost.at(to)) {
                cost.at(to) = nc;
                q.push(make_pair(nc, to));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);

    vpl2 ab(n, vpl());
    ll total{0};
    rep(i, n-1) {
        Def(a);
        Def(b);
        Def(c);
        a--; b--;
        total += c;
        ab[a].push_back(make_pair(b, c));
        ab[b].push_back(make_pair(a, c));
    }

    // 2 ≤ N ≤ 2×10^5
    // 1 ≤ Ai,Bi ≤ N
    // 1 ≤ Ci ≤ 10^9
    // 全ての都市を最短距離で回る巡回セールスマン問題
    // しかし、通常の巡回セールスマン問題だと、効率的な手法でもO(n^2 * 2^n)とからしい
    // 当然それでは話にならない。
    // 何か削減できる要因が…？
    //
    // -> 道がn-1本で全連結なんだから、単なる連結グラフではなく木である。
    // 出発地が決まったら後の順路は深さ優先でほぼ自明なはず。
    // 問題は出発地をどこに定めるか。
    // 全ての点を出発地としてDFSしたら、O(N(N+N-1)) -> O(N2)となってしまう
    // 基本は、出発地候補は葉のどこかになるはず（往復の手間を省く）だが、葉の数のMAXはN-1だから意味がない。
    //
    // 直近の分岐点までの深さが最大の葉が始点になるはず。
    // 終点も同様？　いや、でも間の経路が長いなら結局別の終点が良かったりするかも。。。
    // DFSで深さを確認して始点を決定 O(N + N-1)
    // そこから更にDFSで距離を確認 O(N + N-1)
    // でO(4N)でいけるんちゃうか？
    //
    // 最も遠い二点を求めて始点/終点とする（ダイクストラ2回？　O(NlogN))
    // そこからDFS O(N)とかで行けるのでは

    // (1) 任意の点から最も遠い点A
    // (2) Aから最も遠い点B
    // を求めると、A-Bが木の中の最大距離のペア
    vl dist(n, MAXLL);
    // 始点
    dijkstra(ab, 0, dist);
    auto stp = max_element(all(dist)) - dist.begin();

    // 終点
    rep(i, n) dist[i] = MAXLL;
    dijkstra(ab, stp, dist);
    auto glp = max_element(all(dist)) - dist.begin();

    // stp-glp間の最短パス以外の枝は、往復二回通る
    /* cout << total << ", " << dist[glp] << endl; */
    cout << (total - dist[glp]) * 2 + dist[glp] << endl;
}
