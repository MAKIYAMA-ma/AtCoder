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
    vpl2 cn(n, vpl());
    UnionFind uf;
    uf.init(n);
    rep(i, m) {
        Def(x);
        Def(y);
        Def(z);
        x--; y--;
        cn[x].push_back({y, z});
        cn[y].push_back({x, z});
        uf.merge(x, y);
    }
    vl2 a(n, vl(60, -1));
    map<ll, set<ll>> gm;
    rep(i, n) {
        gm[uf.root(i)].insert(i);
    }

    for(auto &[_, grp] : gm) {
        // XORなら、ビットごとに管理できると2値になるから分かりやすかったりする
        rep(i, 60) {
            ll oc{0};
            ll bg = *(grp.begin());
            queue<ll> q;
            a[bg][i] = 0;
            q.push(bg);
            while(!q.empty()) {
                auto tp = q.front();
                q.pop();
                for(auto [nxt, z] : cn[tp]) {
                    ll val = ((z>>i)&0x01) ^ (a[tp][i]);
                    if(a[nxt][i] == -1) {
                        a[nxt][i] = val;
                        oc += val;
                        q.push(nxt);
                    } else if(a[nxt][i] != val) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
            // 1のほうが多くなっているなら、01を逆にする
            if(oc*2 > grp.size()) {
                for(auto v : grp) {
                    a[v][i] = 1-a[v][i];
                }
            }
        }
    }

    rep(i, n) {
        ll val{0};
        rep(j, 60) {
            val += (a[i][j] << j);
        }
        cout << val << " ";
    }
    cout << endl;
}
