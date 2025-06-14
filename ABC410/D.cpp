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
    vpl2 mp(n, vpl());
    rep(i, m) {
        Def3(a, b, w);
        a--; b--;
        mp[a].push_back({b, w});
        uf.merge(a, b);
    }
    if(!uf.same(0, n-1)) {
        cout << -1 << endl;
        return 0;
    }

    ll ans{0};
    vb ar(n*2, true);
    rrep(i, 11) {
        UnionFind uf2;
        vl2 mp2(n*2, vl());
        vl2 mp2_r(n*2, vl());
        uf2.init(n*2);
        rep(j, m) {
            for(auto [dst, w] : mp[j]) {
                if(w & (1 << i)) {
                    if(ar[j] && ar[dst+n]) {
                        mp2[j].push_back(dst+n);
                        mp2_r[dst+n].push_back(j);
                        uf2.merge(j, dst+n);
                    }
                    if(ar[j+n] && ar[dst]) {
                        mp2[j+n].push_back(dst);
                        mp2_r[dst].push_back(j+n);
                        uf2.merge(j+n, dst);
                    }
                } else {
                    if(ar[j] && ar[dst]) {
                        mp2[j].push_back(dst);
                        mp2_r[dst].push_back(j);
                        uf2.merge(j, dst);
                    }
                    if(ar[j+n] && ar[dst+n]) {
                        mp2[j+n].push_back(dst+n);
                        mp2_r[dst+n].push_back(j+n);
                        uf2.merge(j+n, dst+n);
                    }
                }
            }
        }
        cout << "---------" << endl;
        rep(j, n*2) {
            cout << j << ":";
            for(auto d: mp2[j]) cout << d << " ";
            cout << endl;
        }
        cout << "---------" << endl;
        if(uf2.same(0, n-1)) {
            vb cn1(n*2, false);
            vb cn2(n*2, false);
            queue<ll> q;
            q.push(0);
            while(!q.empty()) {
                auto tp = q.front();
                q.pop();
                cn1[tp] = true;
                for(auto d : mp2[tp]) {
                    q.push(d);
                }
            }
            queue<ll> q2;
            q2.push(n-1);
            while(!q2.empty()) {
                auto tp = q2.front();
                q2.pop();
                cn2[tp] = true;
                for(auto d : mp2_r[tp]) {
                    q2.push(d);
                }
            }
            rep(j, n*2) {
                if(!(cn1[j] && cn2[j])) {
                    ar[j] = false;
                }
            }
            rep(j, n*2) cout << cn1[j] << " ";
            cout << endl;
            rep(j, n*2) cout << cn2[j] << " ";
            cout << endl;
        } else {
            ans |= (1 << i);
        }
        rep(j, n*2) cout << ar[j] << " ";
        cout << endl;
    }
    cout << ans << endl;
}
