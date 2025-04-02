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

using sl = set<ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;
using vs = vector<string>;
using vsl = vector<sl>;

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

class BITMax {
    public:
#if 1
        unordered_map<ll, ll> tree;
        ll mx;
        void init(int n) {
            mx = n+1;
        }
#else
        vl tree;

        /**
         * @brief indexは1始まりとするため、1多く領域をとる。
         *
         * @param n
         */
        void init(int n) {
            tree.resize(n+1, 0);
        }
#endif

        /**
         * @brief start以上のindexの要素について、val以下の要素はvalで更新する
         *
         * @param start
         * @param val
         */
        void add(int start, ll val) {
#if 1
            for(int i = start+1; i < mx; i += i&(-i)) {
#else
            for(int i = start+1; i < tree.size(); i += i&(-i)) {
#endif
                tree[i] = max(tree[i], val);
            }
        }

        /**
         * @brief indまでの要素の最大値を返す
         *
         * @param ind
         *
         * @return 
         */
        ll ask(int ind) {
            ll ans = 0;
            for(int i = ind+1; i; i -= i&(-i) ) {
                ans = max(ans, tree[i]);
            }
            return ans;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(n, q);
    DefA(a, n);
    Def2A(r, x, q);
    // n, q <= 2*10^5
    // a <= 10^9
    //
    // a[i]を最後尾とする単調増加列の長さを求めたとする
    // R[i]までの間でx[i]以下の各要素までの列の長さの最大値を求められれば良い
    vpl odr;
    rep(i, q) {
        odr.push_back({r[i], i});
    }
    sort(all(odr));

    // rの昇順に処理して時短
    vl ln(n, MAXLL);
    vl ans(q, 0);
    ll idx{0};
    BITMax bt;
    ll mxv = *max_element(all(a));
    bt.init(mxv+1);
    // forループがq回
    // while分ではidxが最大Rに達するまででアリ、トータルでn回までの処理
    // whileの中の処理は、検索がO(logN), bt.addがO((logN)^2)
    // bt.askがO((logN)^2)
    // トータルでO(q(logN)^2 + N(log(N)^2))とかではない？
    // なぜTLE...
    for(auto [rt, it] : odr) {
        while(idx < rt) {
            auto lp = lower_bound(all(ln), a[idx]) - ln.begin();
            ln[lp] = a[idx];
            // rtまでの範囲での、a[idx]を末尾とする単調増加列の長さを最大lp+1に更新
            bt.add(a[idx], lp+1);
            idx++;
        }
        // x[it]以下の値を末尾とする単調増加列の長さの最大値を取得
        // indexがBITの初期化範囲を超えないように注意
        ans[it] = bt.ask(min(mxv, x[it]));
    }
    rep(i, q) cout << ans[i] << endl;
}
