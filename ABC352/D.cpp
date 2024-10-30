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


class SegmentTree {
    public:
        vl tree;
        int n;

        void init(int n_) {
            n = 1;
            whle(n < n_) n *= 2;
            tree.resize(2 * n, 0);
        }

        void update(int idx, ll val) {
            idx += (n-1);
            tree[idx] = val;
            while(idx > 0) {
                idx = (idx-1) / 2; // 親ノード
                tree[idx] = min(tree[2*idx + 1], tree[2*idx + 2]);
            }
        }

        ll query(int a, int b, int index, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、INT_MAXを返して、操作に影響しないようにする。
            if (a >= right || b <= left) return MAXLL;

            //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
            if (a <= left && b >= right) return tree[idx];

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            ll value_1 = query(a, b, 2 * index + 1, left, (left + right) / 2);
            ll value_2 = query(a, b, 2 * index + 2, (left + right) / 2, right);
            return min(value_1, value_2);
        }

        ll ask(int a, int b) {
            return query(a, b, 0, 0, n);
        }
}


/**
 * @brief indexまでの区間の最大値を管理するためのBIT
 */
class BITMax {
    public:
        vl tree;

        /**
         * @brief indexは1始まりとするため、1多く領域をとる。
         * アクセス時も、1始まりであることに留意。
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
            for(int i = start; i < tree.size(); i += i&(-i)) {
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
            for(int i = ind; i; i -= i&(-i) ) {
                ans = max(ans, tree[i]);
            }
            return ans;
        }
};

/**
 * @brief indexまでの区間の最大値を管理するためのBIT
 */
class BITMin {
    public:
        vl tree;

        /**
         * @brief indexは1始まりとするため、1多く領域をとる。
         * アクセス時も、1始まりであることに留意。
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
            for(int i = start; i < tree.size(); i += i&(-i)) {
                tree[i] = min(tree[i], val);
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
            for(int i = ind; i; i -= i&(-i) ) {
                ans = min(ans, tree[i]);
            }
            return ans;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 連続するK個の数字がまとまっている範囲として、最小の範囲を求めたい。
    Def(n);
    Def(k);
    vi pi(n);
    rep(i, n) {
        Def(p);
        pi[p-1] = i;
    }
    BITMin bmin;
    BITMax bmax;
    bmin.init(n);
    bmax.init(n);
    rep(i, n) {
        bmin.add(i, pi[i]);
        bmax.add(i, pi[i]);
    }

    // TODO BITじゃダメ
    // セグメントツリーが必要

    ll ans = n+1;
    rep(i, n-k) {
        ll mxv = bmax.ask(i+k) - bmax.ask(i);
    }
}
