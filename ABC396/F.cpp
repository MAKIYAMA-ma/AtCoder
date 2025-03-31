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

/**
 * @brief indexまでの区間の総和を管理するためのBIT
 */
class BIT {
    public:
        vl tree;

        /**
         * @brief indexは1始まりとするため、1多く領域をとる。
         *
         * @param n
         */
        void init(int n) {
            tree.resize(n+1, 0);
        }

        /**
         * @brief start以上のindexの要素について、val以下の要素はvalで更新する
         *
         * @param start
         * @param val
         */
        void add(int start, ll val) {
            for(int i = start+1; i < tree.size(); i += i&(-i)) {
                tree[i] = tree[i] + val;
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
                ans = ans + tree[i];
            }
            return ans;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(n, m);
    vl a(n);
    vl2 cnt(m, vl());
    rep(i, n) {
        Def(tmp);
        /* a[i] = (tmp%m); */
        a[i] = tmp;
        cnt[a[i]].push_back(i);
    }
    BIT bt;
    bt.init(m);

    // 最初の転倒数をカウント
    ll tt{0};
    rrep(i, n) {
        bt.add(a[i], 1);
        tt += ((a[i]>0)?(bt.ask(a[i]-1)):0);
    }

    cout << tt << endl;
    for(ll i = m-1; i > 0; i--) {
        // 最大値から最小値に変化する要素の分の個数を補正する
        // それ以外の場所は大小関係が変化しない
        // 同じ数字の部分は打ち消しあうから問題ない
        for(auto idx : cnt[i]) {
            tt -= (n-1-idx);
            tt += idx;
        }
        cout << tt << endl;
    }
}
