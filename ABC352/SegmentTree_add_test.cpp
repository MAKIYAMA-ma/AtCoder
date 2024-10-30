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
        int type;   // 0:累積, 1:max, 2:min

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

        void update(int idx, ll val) {
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
        }

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
            //考えようとしている区間が、[a,b)に全く含まれないなら、INT_MAXを返して、操作に影響しないようにする。
            if (a >= right || b <= left) return 0;

            //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
            if (a <= left && b >= right) return tree[idx];

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            ll value_1 = query_add(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_add(a, b, 2 * idx + 2, (left + right) / 2, right);
            return value_1 + value_2;
        }

        ll query_max(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、INT_MAXを返して、操作に影響しないようにする。
            if (a >= right || b <= left) return MINLL;

            //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
            if (a <= left && b >= right) return tree[idx];

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            ll value_1 = query_max(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_max(a, b, 2 * idx + 2, (left + right) / 2, right);
            return max(value_1, value_2);
        }

        ll query_min(int a, int b, int idx, int left, int right) {
            //考えようとしている区間が、[a,b)に全く含まれないなら、INT_MAXを返して、操作に影響しないようにする。
            if (right <= a || b <= left) return MAXLL;

            //考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
            if (a <= left && right <= b) return tree[idx];

            //どちらでもない場合、tree[idx]の2つの子ノードに対して再帰的に操作を行う。
            ll value_1 = query_min(a, b, 2 * idx + 1, left, (left + right) / 2);
            ll value_2 = query_min(a, b, 2 * idx + 2, (left + right) / 2, right);
            return min(value_1, value_2);
        }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 連続するK個の数字がまとまっている範囲として、最小の範囲を求めたい。
    Def(n);
    Def(k);
    DefA(p, n);

    SegmentTree stadd;
    stadd.init(n, 0);

    rep(i, n) {
        stadd.update(i, p[i]);
    }

    rep(i, n-k+1) {
        cout << stadd.ask(i, i+k) << endl;
    }
}
