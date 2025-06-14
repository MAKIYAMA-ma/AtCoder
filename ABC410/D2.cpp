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
#define Def3A(a, b, c, n) vl a(n); vl b(n); vl c(n); rep(i, n) cin >> a[i] >> b[i] >> c[i];
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

typedef struct {
    ll from;
    ll to;
    ll cost;
} ST_EDGE;

bool BellmanFord(vector<ST_EDGE> &edges, vector<ll> &cost, ll start, ll goal, ll INF) {
    bool result = true;
    ll goal_cost = INF;
    cost.at(start) = 0;
    rep(i, cost.size()) {
        bool changed = false;
        for(const auto &edge : edges) {
            if(cost.at(edge.from) == INF) {
                continue;
            }
            ll nc = cost.at(edge.from) | edge.cost;
            if(nc < cost.at(edge.to)) {
                cost.at(edge.to) = nc;
                changed = true;
            }
        }
        if(!changed) {
            break;
        }
        if(goal < 0) {
            // ゴールの指定がない（-1）なら、ループがあるとNG
            if(i == cost.size()-1) {
                result = false;
            }
        } else {
            // ゴールが指定されている場合、たとえループがあってもゴールのコストは変わらないならOKとする
            // -> ループ内でコストがプラスマイナス0になる
            if(i == cost.size()-2) {
                goal_cost = cost.at(goal);
            } else if(i == cost.size()-1) {
                if(goal_cost != cost.at(goal)) {
                    result = false;
                }
            }
        }
    }

    return result;
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(n, m);
    // ビットごとに分けて、上のビットから確定していくべき
    // 閉路を複数周回するのは無意味。0or1周の2択。

    UnionFind uf;
    uf.init(n);
    vector<ST_EDGE> edges;
    rep(i, m) {
        Def3(a, b, w);
        a--; b--;
        uf.merge(a, b);
        edges.push_back({a, b, w});
    }
    if(!uf.same(0, n-1)) {
        cout << -1 << endl;
        return 0;
    }

}
