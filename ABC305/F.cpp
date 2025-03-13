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
#define Def2(m, n) ll m, n; cin >> m >> n;
#define Def3(l, m, n) ll l, m, n; cin >> l >> m >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define DefPA(a, n) vl a(n); rep(i, n) cin >> a[i].first >> a[i].second;

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

    Def2(n, m);
    // 連結単純無向グラフ
    // 地図がない状態で、2N回の移動でゴールにたどり着く
    // 地図に沿って探索するなら当然BFSなのだが。。。
    //
    // 全部網羅で、最悪ほぼ全ての辺を往復する場合N^2回程度になってしまうので回数オーバー
    // 同じ点には一往復分しか訪問しない、という探索が必要
    // DFSしていき、知らない点が出なくなったら、知らない点がある場所まで戻るというのを繰り返せばいいはず
    // どう管理すればいい？
    // -> stack

    vb fin(n+1, false);
    fin[0] = true;
    fin[1] = true;
    stack<ll> st;
    st.push(1);
    while(true) {
        Def(k);

        // 失敗
        if(k == -1) break;

        bool ok{false};
        DefA(v, k);
        /* for(auto nxt : v) { */
        // ゴールが含まれるならゴールが選ばれるように、後からたどってみる
        rrep(i, v.size()) {
            auto nxt = v[i];
            if(!fin[nxt]) {
                cout << nxt << endl;
                fin[nxt] = true;
                if(nxt == n) {
                    // OKなはず
                    string s;
                    cin >> s;
                    return 0;
                } else {
                    ok = true;
                    st.push(nxt);
                    break;
                }
            }
        }
        if(!ok) {
            if(!st.empty()) {
                st.pop();
                auto nxt = st.top();
                cout << nxt << endl;
            } else {
                // ありえないはず
                return 0;
            }
        }
    }
}
