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
 * @brief SegmentTreeクラス
 * init時、操作をtypeで指定する。
 * 0: 総和
 * 1: MAX
 * 2: MIN
 */
class SegmentTree {
    public:
        vl tree;
        int n;
        int type;   // 0:累積, 1:max, 2:min

        /**
         * @brief 初期関数。要素数と演算のタイプを指定する。
         *
         * @param n_
         * @param t
         */
        void init(int n_, int t) {
            type = t;
            n = 1;
            while(n < n_) n *= 2;
            switch(type) {
                case 0: tree.resize(2 * n, 0); break;
                case 1: tree.resize(2 * n, MINLL); break;
                case 2: tree.resize(2 * n, MAXLL); break;
            }
        }

        /**
         * @brief idx番の要素をvalに更新する
         *
         * @param idx
         * @param val
         */
        void update(int idx) {
#if 1
            idx += (n-1);
            tree[idx] = 1-tree[idx];
            while(idx > 0) {
                idx = (idx-1) / 2; // 親ノード
                switch(type) {
                    case 0: tree[idx] = tree[2*idx + 1] + tree[2*idx + 2]; break;
                    case 1: tree[idx] = max(tree[2*idx + 1], tree[2*idx + 2]); break;
                    case 2: tree[idx] = min(tree[2*idx + 1], tree[2*idx + 2]); break;
                }
            }
#else
            idx += (n-1);
            tree[idx] = val;
            while(idx > 0) {
                idx = (idx-1) / 2; // 親ノード
                switch(type) {
                    case 0: tree[idx] = tree[2*idx + 1] + tree[2*idx + 2]; break;
                    case 1: tree[idx] = max(tree[2*idx + 1], tree[2*idx + 2]); break;
                    case 2: tree[idx] = min(tree[2*idx + 1], tree[2*idx + 2]); break;
                }
            }
#endif
        }

        /**
         * @brief [a, b)の範囲の演算結果を取得する
         *
         * @param a
         * @param b
         *
         * @return 演算結果
         */
        ll ask(int a, int b) {
            switch(type) {
                case 0: return query_add(a, b, 0, 0, n); break;
                case 1: return query_max(a, b, 0, 0, n); break;
                case 2: return query_min(a, b, 0, 0, n); break;
            }
            return 0;
        }

    private:
        ll query_add(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、0を返して、操作に影響しないようにする。
            if (a >= right || b <= left) return 0;

            //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
            if (a <= left && b >= right) return tree[idx];

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            ll value_1 = query_add(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_add(a, b, 2 * idx + 2, (left + right) / 2, right);
            return value_1 + value_2;
        }

        ll query_max(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、MINを返して、操作に影響しないようにする。
            if (a >= right || b <= left) return MINLL;

            if (a <= left && b >= right) return tree[idx];

            ll value_1 = query_max(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_max(a, b, 2 * idx + 2, (left + right) / 2, right);
            return max(value_1, value_2);
        }

        ll query_min(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、MAXを返して、操作に影響しないようにする。
            if (right <= a || b <= left) return MAXLL;

            if (a <= left && right <= b) return tree[idx];

            ll value_1 = query_min(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_min(a, b, 2 * idx + 2, (left + right) / 2, right);
            return min(value_1, value_2);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(q);
    string s;
    cin >> s;

    // n, q <= 5 * 10^5
    // 当然O(nq)でそのままやるとTLEする
    //
    // 反転処理の都度lとrを記録しておき、問い合わせ時に累積で反転の計算は可能
    // しかし、それだと反転はO(1)だが問い合わせが累積計算だけでO(N)
    // 間に反転が挟まらなければ累積は不要だが、反転と問い合わせが交互に来たら、5*2.5*10^10になるわけなのでオーバー
    // そもそも良い列かの判定も普通にやればO(N)
    //
    // 良い文字列かを管理できるSegTreeとか可能か？　結局各セルが何なのか個別管理が必要になる
    SegmentTree st;
    st.init(n-1, 0);
    rep(i, n-1) {
        if(s[i] != s[i+1]) st.update(i);
    }
    rep(i, q) {
        Def(od);
        Def(l);
        Def(r);
        l--; r--;

        if(od == 1) {
            // 反転処理
            if(l > 0) st.update(l-1);
            if(r < n-1) st.update(r);
        } else {
            // 問い合わせ
            auto sm = st.ask(l, r);
            /* cout << "DB:" << sm << endl; */
            Yes(sm == (r-l));
        }
    }
}
