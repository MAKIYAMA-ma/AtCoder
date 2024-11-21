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


typedef struct {
    ll size;
    ll index;
    ll length;
    ll cut;
} ST_CUT;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(l);
    Def(k);
#if 1
    DefA(a, n);
    vl sz(n+1, 0);
    rep(i, n) {
        sz[i] = a[i] - ((i > 0) ? a[i-1] : 0);
    }
    sz[n] = l - a[n-1];

    // 答えの二分探索でO(NlogN)でいける
    int lft{0};
    int rgt = l;
    while(rgt - lft > 1) {
        int m = (rgt + lft)/2;
        int cnt{0};
        int cur{0};
        bool res{false};
        rep(i, n+1) {
            cur += sz[i];
            if(cur >= m) {
                cnt++;
                cur = 0;
                if(cnt >= k+1) {
                    res = true;
                    break;
                }
            }
        }
        if(res) {
            lft = m;
        } else {
            rgt = m;
        }
    }
    cout << lft << endl;
#else
    vl a(n+1);
    rep(i, n) cin >> a[i];
    a[n] = l;

    // aをk+1個に分割し、最小の領域を最大の大きさにしたい
    // 単純にいうなら、二つの並びが最小の場所見つけ、そこを合体
    // というのをK+1パーツに減るまで繰り返せば答えが出る。
    // 毎回要素を削除するのはO(N)かかってしまう。
    // 何番のIndexが残っているかを管理？
    // 合体時の長さとIndexをpriority_queueで管理
    // 最小のを取り出し、それを合体する。
    // Indexを参考に数値を調整
    priority_queue<ST_CUT, vector<ST_CUT>, greater<ST_CUT>> pq;
    vl cs(n, 0);
    rep(i, n) {
        ll sz = a[i+1] - ((i > 0) ? a[i-1] : 0);
        cs[i] = sz;
        pq.push({sz, i, 1, i+1});
    }
    vb cut(n, true);
    rep(i, n-k) {
        auto tp = pq.top();
        pq.pop();

        cut[tp.cut] = false;
        // 新しく融合された結果に合わせて次の融合候補を作ろうとすると、
        // pq内の要素を消せないとおかしくなる。。。
    }
#endif
}
