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

    Def(n);
    Def(m);

    // 流量1ずつだと、分岐する際の扱いが。。。
    // TODO A->Bについて、Bだけ採用はありうる
    //
    // n: start, n+1:goal
    mf_graph<ll> grp(n + 2);
    int st = n;
    int gl = n+1;

    ll maxpt{0};
    rep(i, n) {
        Def(p);
        if(p >= 0) {
            // 無制限の場合の最大コストを計算
            maxpt += p;
            // 加点される場合は、s -> i に加点分を流量として設定する
            grp.add_edge(st, i, p);
        } else {
            // 減点される場合は、i -> g に減点分を流量として設定する
            grp.add_edge(i, gl, -p);
        }
    }
    rep(i, m) {
        Def(a);
        Def(b);
        a--; b--;

        // 連動するなら、a -> bに無限に流す。
        grp.add_edge(a, b, MAXLL);
    }
    // 流量を設定する。
    // - 制限に絡まない点については何も流れない
    // - 減点の点から加点の点へ流れる制限がある場合も、何も流れない
    // - 加点の点から減点の点へ流れる制限がある場合は、加点と減点の小さいほうの流量が流れる。
    // -> 加点のみを足した最大値から、このグラフの最大フローを引くと最大の点数が求まる。
    cout << maxpt - grp.flow(st, gl) << endl;
}
