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
    // 2 <= n <= 100
    // 各行/列に一つずつ正の整数がある
    // 各数値kをk行k列に配置するように行同士/列同士を交換する
    // 最小手数は何か
    //
    // 行の入れ替えと列の入れ替えは独立
    // 行をそろえる手順で列も同様に処理できる。
    // とりあえずiをi行目にする手順で考える
    //
    // 1が2行目、2が1行目なら1手でOK
    // 同様にjこの数字がj行に分散しているなら、j-1手で戻せる
    // 最小のグループ分けをしたい
    //
    // UnionFindでグループ分けして、グループごとの個数を数える
    // -> 任意の行/列でなく、隣接する行列の交換しかできない！！！
    // TODO 間にすでにグループの範囲の別のグループが存在するなら合体させる必要がある
    UnionFind ufc, ufr;
    ufc.init(n);
    ufr.init(n);

    rep(i, n) {
        rep(j, n) {
            Def(p);
            if(p) {
                ufc.merge(i, p-1);
                ufr.merge(j, p-1);
            }
        }
    }
    map<int, pl> cm, rm;
    rep(i, n) {
        auto rt = ufc.root(i);
        if(cm.find(rt) != cm.end()) {
            cm[rt].first = min(cm[rt].first, i);
            cm[rt].second = max(cm[rt].second, i);
        } else {
            cm[rt].first = cm[rt].second = i;
        }

        rt = ufr.root(i);
        if(rm.find(rt) != rm.end()) {
            rm[rt].first = min(rm[rt].first, i);
            rm[rt].second = max(rm[rt].second, i);
        } else {
            rm[rt].first = rm[rt].second = i;
        }
    }

    set<pl> csp, rsp;
    for(auto m : cm) {
        csp.insert(m.second);
    }
    for(auto m : rm) {
        rsp.insert(m.second);
    }

    ll ans{0};
    int l{0}, r{0};
    for(auto m : csp) {
        /* cout << "DB1:" << l << " " << r << "  :  " << m.first << " " << m.second << endl; */
        if(m.first <= r && m.second >= r) {
            r = m.second;
        } else {
            ans += (r - l);
            l = m.first;
            r = m.second;
        }
    }
    ans += (r - l);
    l = 0;
    r = 0;
    for(auto m : rsp) {
        /* cout << "DB2:" << l << " " << r << "  :  " << m.first << " " << m.second << endl; */
        if(m.first <= r && m.second >= r) {
            r = m.second;
        } else {
            ans += (r - l);
            l = m.first;
            r = m.second;
        }
    }
    ans += (r - l);
    cout << ans << endl;
}
