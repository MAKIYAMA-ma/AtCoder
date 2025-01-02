#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 0
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

    Def(h);
    Def(w);
    vs s(h);
    rep(i, h) cin >> s[i];

    // 現状の連結成分数から、-3~+1の変化をする
    // (1) UnionFindでグループ分ける
    // (2) マトリクスにグループ番号をふる
    // (3) 隣接マスの番号をもとに増減を判断する
    /* vl dh = {1, -1, 0, 0}; */
    /* vl dw = {0, 0, 1, -1}; */
    vl dh = {1, 0}; // 後から出てくるものだけ考慮
    vl dw = {0, 1};

    UnionFind uf;
    uf.init(h*w);
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                rep(k, dh.size()) {
                    auto nh = i + dh[k];
                    auto nw = j + dw[k];
                    if(nh >= 0 && nh < h && nw >= 0 && nw < w && s[nh][nw] == '#') {
                        uf.merge(i*w+j, nh*w+nw);
                    }
                }
            }
        }
    }

    vl2 mp(h, vl(w, -1));
    map<ll,ll> grp;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                mp[i][j] = uf.root(i*w+j);
                grp[mp[i][j]]++;
            }
        }
    }

    vl dh2 = {1, -1, 0, 0};
    vl dw2 = {0, 0, 1, -1};
    mint exp = 0;
    ll ttl{0};
    rep(i, h) {
        rep(j, w) {
            if(mp[i][j] < 0) {
                map<ll, ll> nb;
                rep(k, dh2.size()) {
                    auto nh = i + dh2[k];
                    auto nw = j + dw2[k];
                    if(nh >= 0 && nh < h && nw >= 0 && nw < w && s[nh][nw] == '#') {
                        nb[mp[nh][nw]]++;
                    }
                }
                exp += (grp.size() - (nb.size()-1));
                ttl++;
            }
        }
    }

    // 期待値modの計算
    ll mod = 998244353;
    ll denomi = inv_mod(ttl , mod);
    cout << (exp*denomi).val() << endl;
}
