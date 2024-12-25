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
 * @brief 遅延SegmentTreeクラス
 * init時、操作をtypeで指定する。
 * 0: 総和
 * 1: MAX
 * 2: MIN
 */
class LazySegmentTree {
    public:
        vl tree, lazy;
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
            switch(type) {
                case 0: lazy.resize(2 * n, 0); break;
                case 1: lazy.resize(2 * n, MINLL); break;
                case 2: lazy.resize(2 * n, MAXLL); break;
            }
        }

        /**
         * @brief idx番の要素をvalに更新する
         *
         * @param idx
         * @param val
         */
        void update(int a, int b, ll val) {
            /* cout << "DB:" << a << " " << b << " " << val << endl; */
            switch(type) {
                case 0: update_add(a, b, val, 0, 0, n); break;
                case 1: update_max(a, b, val, 0, 0, n); break;
                case 2: update_min(a, b, val, 0, 0, n); break;
            }
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
        /* 総和の場合の関数群 */
        void update_add(int a, int b, ll val, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれない
            if (a >= right || b <= left) return;

            //考えようとしている区間が[a,b)に完全に含まれている
            if (a <= left && b >= right) {
                lazy[idx] += val*(right-left);
                return;
            }

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            update_add(a, b, val, 2 * idx + 1, left, (left + right) / 2);
            update_add(a, b, val, 2 * idx + 2, (left + right) / 2, right);
            tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
        }

        ll query_add(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、0を返して、操作に影響しないようにする。
            if (a >= right || b <= left) return 0;

            // 参照される際に初めて遅延評価する
            eval_add(idx, left, right);

            //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
            if (a <= left && b >= right) return tree[idx];

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            ll value_1 = query_add(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_add(a, b, 2 * idx + 2, (left + right) / 2, right);
            return value_1 + value_2;
        }

        void eval_add(int idx, int left, int right) {
            if(lazy[idx] != 0) {
                tree[idx] += lazy[idx];
                if(right - left > 1) {
                    lazy[2 * idx + 1] += lazy[idx]/2;
                    lazy[2 * idx + 2] += lazy[idx]/2;
                }
                lazy[idx] = 0;
            }
        }

        /* 最大の場合の関数群 */
        void update_max(int a, int b, ll val, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれない
            if (a >= right || b <= left) return;

            //考えようとしている区間が[a,b)に完全に含まれている
            if (a <= left && b >= right) {
                lazy[idx] = max(lazy[idx], val);
                return;
            }

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            update_max(a, b, val, 2 * idx + 1, left, (left + right) / 2);
            update_max(a, b, val, 2 * idx + 2, (left + right) / 2, right);
            tree[idx] = max(tree[2*idx + 1], tree[2*idx + 2]);
        }

        ll query_max(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、MINを返して、操作に影響しないようにする。
            if (a >= right || b <= left) return MINLL;

            eval_max(idx, left, right);

            if (a <= left && b >= right) return tree[idx];

            ll value_1 = query_max(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_max(a, b, 2 * idx + 2, (left + right) / 2, right);
            return max(value_1, value_2);
        }

        void eval_max(int idx, int left, int right) {
            if(lazy[idx] != MINLL) {
                tree[idx] = max(tree[idx], lazy[idx]);
                if(right - left > 1) {
                    lazy[2 * idx + 1] = max(lazy[2 * idx + 1], lazy[idx]);
                    lazy[2 * idx + 2] = max(lazy[2 * idx + 2], lazy[idx]);
                }
                lazy[idx] = MINLL;
            }
        }

        /* 最小の場合の関数群 */
        void update_min(int a, int b, ll val, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれない
            if (a >= right || b <= left) return;

            //考えようとしている区間が[a,b)に完全に含まれている
            if (a <= left && b >= right) {
                lazy[idx] = min(lazy[idx], val);
                return;
            }

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            update_min(a, b, val, 2 * idx + 1, left, (left + right) / 2);
            update_min(a, b, val, 2 * idx + 2, (left + right) / 2, right);
            tree[idx] = min(tree[2*idx + 1], tree[2*idx + 2]);
        }

        ll query_min(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、MAXを返して、操作に影響しないようにする。
            if (right <= a || b <= left) return MAXLL;

            eval_min(idx, left, right);

            if (a <= left && right <= b) return tree[idx];

            ll value_1 = query_min(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_min(a, b, 2 * idx + 2, (left + right) / 2, right);
            return min(value_1, value_2);
        }

        void eval_min(int idx, int left, int right) {
            if(lazy[idx] != MAXLL) {
                tree[idx] = min(tree[idx], lazy[idx]);
                if(right - left > 1) {
                    lazy[2 * idx + 1] = min(lazy[2 * idx + 1], lazy[idx]);
                    lazy[2 * idx + 2] = min(lazy[2 * idx + 2], lazy[idx]);
                }
                lazy[idx] = MAXLL;
            }
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);

    DefA(a, n);
    DefA(b, m);

    // 箱Biの中身を、次の箱から順に1個ずつ分配して行く
    // n, m <= 2*10^5, a <= 10^9
    // O(mn)ならできるだろうけどTLE
    //
    // 前の操作が後の操作に影響するから、境界だけメモっといて最後に累積で計算とかも無理か
    LazySegmentTree lst;
    lst.init(n, 0);
    rep(i, n) {
        lst.update(i, i+1, a[i]);
    }
    rep(i, m) {
        ll bl = lst.ask(b[i], b[i]+1);
        lst.update(b[i], b[i]+1, -bl);

        ll ech = bl/n;
        if(ech) lst.update(0, n, ech);
        auto tail = bl%n + b[i] + 1;
        if(tail <= n) {
            lst.update(b[i]+1, tail, 1);
        } else {
            lst.update(0, tail%n, 1);
            lst.update(b[i]+1, n, 1);
        }
        /* cout << "--------" << endl; */
        /* rep(i, n) { */
        /*     cout << lst.ask(i, i+1) << " "; */
        /* } */
        /* cout << endl << "--------" << endl; */
    }
    rep(i, n) {
        cout << lst.ask(i, i+1) << " ";
    }
    cout << endl;
}
