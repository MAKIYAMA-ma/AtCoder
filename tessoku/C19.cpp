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
    Def(l);
    Def(k);

#if 1
    // i~i+1 kmの区間を進むためのガソリンは、i-K~i-1の区間の最安値で入れればよい
    Def2A(a, c, n);

    SegmentTree st;
    st.init(l, 2);

    // 同じ地点に複数スタンドがある場合は最安値のみ考慮
    vl minc(l+1, MAXLL);
    rep(i, n) {
        minc[a[i]] = min(minc[a[i]], c[i]);
    }
    rep(i, l+1) {
        st.update(i, minc[i]);
    }
    ll ans{0};
    rep(i, l-k) {
        ans += st.ask(i+1, i+k+1);
        if(ans >= MAXLL) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
#elif 1
    // 到達可能範囲で最安のスタンドでガソリンを入れる。
    // Kキロ以内にもっと安いスタンドがあればそこまで到達可能なガソリンを入れる
    // ないなら満タンまで入れる
    // を繰り返せば良いはず。
    // ただし、最後はゴールまでの分だけ入れれば良い。
    vpl ac(n+2, {0, 0});
    rep(i, n) {
        cin >> ac[i+1].first >> ac[i+1].second;
    }
    ac[n+1].first = l;
    sort(all(ac));
    vl a(n+2, 0), c(n+2, 0);
    rep(i, n+2) {
        a[i] = ac[i].first;
        c[i] = ac[i].second;
    }
    rep(i, n+1) {
        if(a[i+1] - a[i] > k) {
            cout << -1 << endl;
            return 0;
        }
    }

    ll pos{0};
    ll tgt{0};
    ll ans{0};
    ll rest = k;
    while(pos < n+1) {
        ll mv{MAXLL}, mi{0};
        tgt = pos;
        while(a[++tgt] - a[pos] <= k) {
            if(c[tgt] <= c[pos]) {
                break;
            } else if(c[tgt] <= mv) {
                mv = c[tgt];
                mi = tgt;
            }
        }
        /* cout << "    " << mi << " " << tgt << endl; */

        if(a[tgt] - a[pos] <= k) {
            ans += c[pos]*(a[tgt]-a[pos]-rest);
            /* cout << "DB1:" << pos << "-->" << tgt << " " << ans << endl; */
            rest = 0;
            pos = tgt;
        } else {
            ans += c[pos]*(k-rest);
            /* cout << "DB2:" << pos << "-->" << mi << " " << ans << endl; */
            rest = k-(a[mi]-a[pos]);
            pos = mi;
        }
    }
    cout << ans << endl;
#else
    ll pos{0};
    ll ans{0};
    ll rest = k;
    auto up = upper_bound(all(a), a[pos] + k) - a.begin();
    auto ming = min_element(c.begin() + pos + 1, c.begin() + up) - c.begin();
    while(pos < n+1) {
        if(up - pos == 1) {
            cout << -1 << endl;
            return 0;
        }
        /* cout << "rest:" << rest << " " << a[ming] << " " << a[pos] << "--->"; */
        rest -= (a[ming] - a[pos]);
        /* cout << rest << endl; */
        /* cout << "DD:" << up << " " << ming << endl; */

        auto up2 = upper_bound(all(a), a[ming] + k) - a.begin();
        auto ming2 = min_element(c.begin() + ming + 1, c.begin() + up2) - c.begin();
        /* cout << "DD2:" << up2 << " " << *min_element(c.begin() + ming + 1, c.begin() + up2) << endl; */
        /* cout << "DD:" << ming << ":" << c[ming] << " " << ming2 << ":" << c[ming2] << endl; */
        if(c[ming] <= c[ming2]) {
            // 満タンにする
            ans += (c[ming]*(k-rest));
            rest = k;
            /* cout << "DB2:" << ming << " " << ans << endl; */
        } else {
            srep(i, ming+1, up2) {
                if(c[ming] >= c[i]) {
                    ming2 = i;
                    break;
                }
            }
            // ming2までの分を入れる
            ans += (c[ming]*(a[ming2]-a[ming]-rest));
            rest = a[ming2]-a[ming];
            /* cout << "DB3:" << ming << " " << ans << endl; */
        }
        pos = ming;
        up = up2;
        ming = ming2;
    }
    cout << ans << endl;
#endif
}
