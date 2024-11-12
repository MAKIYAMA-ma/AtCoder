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

void WarshallFloyd(vector<vector<ll>> &cost) {
    rep(k, cost.size()) {
        rep(i, cost.size()) {
            rep(j, cost.size()) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);

    // 各bを一回ずつ通る、1-nへの最短経路を求めたい
    // (1) どの順でBを使うか？
    //      K <= 5だから120通り。
    //      それぞれ順逆あるから*2^5通りで3840通り
    //      毎回総当たりで良いか？
    //      Q <= 3000だからO(3840Q)でもなんとかなるか。
    // (2) 各島の間の最短時間は？
    //      N <= 400だからWF法でも間に合うはず。

    vector<pair<pl, ll>> brd(m);
    vl2 cost(n, vl(n, MAXLL));
    rep(i, m) {
        Def(u);
        Def(v);
        Def(t);
        u--; v--;
        brd[i] = make_pair(make_pair(u, v), t);
        cost[u][v] = min(t, cost[u][v]);
        cost[v][u] = min(t, cost[v][u]);
    }
    rep(i, n) {
        cost[i][i] = 0;
    }

    WarshallFloyd(cost);

    /* cout << "--------------" << endl; */
    /* rep(i, n) { */
    /*     rep(j, n) { */
    /*         cout << cost[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "--------------" << endl; */

    Def(q);
    vl b(5);
    rep(i, q) {
        Def(k);
        rep(j, k) {
            cin >> b[j];
        }
        ll ans{MAXLL};
        // 逆向きの考慮も必要
        do {
            rep(l, (1 << k)) {
                ll tmp{0};
                int st = 0;
                rep(j, k) {
                    auto bd = brd[b[j]-1];
                    auto dst = (l & (1 << j)) ? bd.first.first : bd.first.second;
                    tmp += cost[st][dst] + bd.second;
                    st = (l & (1 << j)) ? bd.first.second : bd.first.first;
                }
                tmp += cost[st][n-1];
                /* cout << "-----------" << endl; */
                /* rep(o, k) cout << b[o] << " "; */
                /* cout << ": " << tmp << endl; */
                /* cout << "-----------" << endl; */
                ans = min(ans, tmp);
            }
        } while (next_permutation(b.begin(), b.begin()+k));
        cout << ans << endl;
    }
}
