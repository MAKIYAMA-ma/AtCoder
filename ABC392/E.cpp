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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    Def2A(a, b, m);

    // 各グループ内の最小の木を見つける
    // 木に含まれないケーブルを別のグループにつなげる
    UnionFind uf;
    uf.init(n+1);
    set<ll> ne;
    rep(i, m) {
        if(uf.same(a[i], b[i])) {
            /* cout << "DB:" << i << endl; */
            ne.insert(i);
        } else {
            uf.merge(a[i], b[i]);
        }
    }
    map<ll, set<ll>> mp;
    map<ll, set<ll>> pk;
    for(auto v : ne) {
        /* cout << "DD:" << uf.root(a[v]) << " " << v << endl; */
        mp[uf.root(a[v])].insert(v);
    }
    set<ll> rtl;
    srep(i, 1, n+1) {
        pk[uf.root(i)].insert(i);
        rtl.insert(uf.root(i));
    }

    vpl rtv2;
    for(auto v : rtl) {
        rtv2.push_back({mp[v].size(), v});
    }
    sort(rall(rtv2));
    vl rtv(rtv2.size());
    rep(i, rtv2.size()) rtv[i] = rtv2[i].second;

    ll cnt{0};
    UnionFind uf2;
    uf2.init(rtv.size());
    cout << rtv.size()-1 << endl;
    rep(i, rtv.size()) {
        for(auto e : mp[rtv[i]]) {
            srep(j, i+1, rtv.size()) {
                if(!uf2.same(i, j)) {
                    cout << e+1 << " " << b[e] << " " << rtv[j] << endl;
                    uf2.merge(i, j);
                    if(++cnt >= rtv.size()-1) return 0;
                    break;
                }
            }
        }
    }
}
