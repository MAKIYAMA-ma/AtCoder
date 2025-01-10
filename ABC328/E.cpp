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

class UnionFind {
    public:
        vector<int> data;

        void init(int n) {
            data.resize(n, -1);
        }

        int root(int idx) {
            if(data.at(idx) == -1) {
                return idx;
            } else {
                // 深さ圧縮
                // ただし、同じグループの全要素の値が同じになるとは限らないので注意
                // (idxより根に近い要素の値は書き換わるが、idxより下の要素の値は書き換わらない。
                // その結果、2段にはなりうる。
                return (data.at(idx) = root(data.at(idx)));
            }
        }

        void merge(int a, int b) {
            int ar, br;

            if(a == b) {
                return;
            }

            ar = root(a);
            br = root(b);
            if(ar != br) {
                data.at(br) = ar;
            }
        }

        bool same(int a, int b) {
            int ar, br;

            if(a == b) {
                return true;
            }

            ar = root(a);
            br = root(b);

            return (ar == br);
        }
};

typedef struct {
    ll p1, p2;
    ll cost;
} EDGE;

ll check(vector<EDGE> &edge, set<ll> sel, ll pos, ll pn, ll k) {
    if(sel.size() == pn-1) {
        ll sum{0};
        // 選んだn-1本の枝が木になっているか確認
        UnionFind uf;
        uf.init(pn);
        for(auto s : sel) {
            if(uf.same(edge[s].p1, edge[s].p2)) {
                // 木じゃないので、影響を与えないように極大を返す
                return MAXLL;
            }
            uf.merge(edge[s].p1, edge[s].p2);
            sum += edge[s].cost;
        }
        // 木ならコスト返す
        return (sum % k);
    } else if(pos >= edge.size()) {
        // 木になる本数の枝がそろわないので、影響を与えないように極大を返す
        return MAXLL;
    } else {
        // posの枝を使わない場合と使う場合でコストを計算
        // これ以降の枝の組合せの最小コストを返す
        ll a1 = check(edge, sel, pos+1, pn, k);
        sel.insert(pos);
        ll a2 = check(edge, sel, pos+1, pn, k);
        sel.erase(pos);
        return min(a1, a2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    Def(k);

    // 単なる最小全域木ならクラスカルでいいのだが。。
    // このコスト定義だと貪欲は厳しいか。
    // N <= 8
    // 基本は全探索な感じの制約か？
    // 辺がMAXで56だから最大組合せ数は56C8 = 3108105
    // O(N)程度で個別の計算が完了できれば間に合う
    vector<EDGE> edge;
    rep(i, m) {
        Def(u);
        Def(v);
        Def(c);
        u--; v--;
        edge.push_back({u, v, c});
    }
    set<ll> sel;
    cout << check(edge, sel, 0, n, k) << endl;
}
