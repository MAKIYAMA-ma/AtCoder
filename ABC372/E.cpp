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

class UnionFind {
    public:
        vector<int> data;
        vi2 member;

        void init(int n) {
            data.resize(n, -1);
            member.resize(n, vi());
            rep(i, n) {
                member[i].push_back(i);
            }
        }

        int setRoot(int p, int c) {
            if(data.at(c) != p) {

                /* cout << "----------" << endl; */
                /* cout << "DBP:[" << p << "] "; */
                /* rep(i, member[p].size()) { */
                /*     cout << member[p][i] << " "; */
                /* } */
                /* cout << endl; */

                /* cout << "DBC:[" << c << "] "; */
                /* rep(i, member[c].size()) { */
                /*     cout << member[c][i] << " "; */
                /* } */
                /* cout << endl; */
                /* cout << "----------" << endl; */

                copy(all(member[c]), back_inserter(member[p]));
                sort(rall(member[p]));


                if(member[p].size() > 10) {
                    member[p].erase(member[p].begin()+10, member[p].end());
                }
                /* cout << "----------" << endl; */
                /* cout << "DB-M:[" << p << "] "; */
                /* rep(i, member[p].size()) { */
                /*     cout << member[p][i] << " "; */
                /* } */
                /* cout << endl; */
                /* cout << "----------" << endl; */
                data.at(c) = p;
            }
            return p;
        }

        int root(int idx) {
            if(data.at(idx) == -1) {
                return idx;
            } else {
                // 深さ圧縮
                // ただし、同じグループの全要素の値が同じになるとは限らないので注意
                // (idxより根に近い要素の値は書き換わるが、idxより下の要素の値は書き換わらない。
                // その結果、2段にはなりうる。
                /* return (setRoot(root(data.at(idx)), idx)); */
                return (data.at(idx) = root(data.at(idx)));
            }
        }

        int largeElem(int idx, int lvl) {
            int rt = root(idx);
            if(member[rt].size() > lvl) {
                /* cout << "----------" << endl; */
                /* cout << "DB:[" << rt << "] "; */
                /* rep(i, member[rt].size()) { */
                /*     cout << member[rt][i] << " "; */
                /* } */
                /* cout << endl; */
                /* cout << "----------" << endl; */
                return member[rt][lvl];
            } else {
                return -1;
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
                setRoot(ar, br);
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
    Def(q);

    // 連結の管理は通常ならUnionFind
    // しかし、その際、端子番号のソート結果が必要となる
    // 当然ながら、クエリごとにN個の頂点にグループの検索をかけるのは却下。O(QN)でTLE。
    UnionFind uf;
    uf.init(n);
    rep(i, q) {
        Def(o);
        Def(v1);
        Def(v2);
        v1--;
        v2--;

        if(o == 1) {
            uf.merge(v1, v2);
        } else {
            int elm = uf.largeElem(v1, v2);
            if(elm >= 0) {
                cout << elm+1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
}
