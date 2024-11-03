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

class BIT {
    public:
        vl tree;

        void init(int n) {
            tree.resize(n+1, 0);
        }

        void add(int start) {
            for(int i = start; i < tree.size(); i += i&(-i)) {
                tree[i]++;
            }
        }

        ll ask(int ind) {
            ll ans = 0;
            for(int i = ind; i; i -= i&(-i) ) {
                ans += tree[i];
            }
            return ans;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    vl a(n+1, 0);
    rep(i, n) {
        cin >> a[i+1];
        a[i+1] += a[i];
        a[i+1] %= m;
    }

#if 0
    ll ans = 0;
    ll adjc{0};
    BIT bt;
    bt.init(m);
    srep(i, 1, n+1) {
        ans += a[i]*(2*i - n);
        adjc += i - bt.ask(a[i]) - 1;
        bt.add(a[i]);
        /* cout << "DB2:" << a[i] << "," << i << "," << (n-i) << endl; */
    }
#elif 1
    // これだとOK
    // BITが遅い？？？
    ll ans{0};
    ll adjc{0};
    fenwick_tree<ll> fw(m);
    srep(i, 1, n+1) {
        ans += a[i]*(2*i - n);
        /* adjc += i - fw.sum(0, a[i]+1) - 1; */
        adjc += fw.sum(a[i]+1, m);
        fw.add(a[i], 1);
        /* cout << "DB2:" << a[i] << "," << i << "," << (n-i) << endl; */
    }
#else
    ll ans = 0;
    srep(i, 1, n+1) {
        ans += a[i]*i;
        ans -= a[i]*(n-i);
        /* cout << "DB2:" << a[i] << "," << i << "," << (n-i) << endl; */
    }

    // 各aについて、それ未満のインデックスにa[i]より大きい値がいくつあるかカウントしたい
    ll adjc{0};
    BIT bt;
    bt.init(m);
    srep(i, 1, n+1) {
        adjc += i - bt.ask(a[i]) - 1;
        bt.add(a[i]);
    }
#endif

    cout << ans + adjc*m << endl;
}
