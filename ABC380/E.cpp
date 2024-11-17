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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(q);

    // 一度同色になった隣接マスは以後ずっと同色
    // 各色の範囲とかで管理できないか。。。
    // 色の数の検索が必要
    // 位置の検索も必要
    // SegTreeとかの系統のデータ構造で何かできる？
    vl col(n, 1);
    set<ll> lft;
    rep(i, n) lft.insert(i);
    vl arcol(n);
    rep(i, n) arcol[i] = i;

    rep(i, q) {
        Def(o);
        if(o == 1) {
            Def(x);
            Def(c);
            x--;
            c--;

            // xが含まれるエリアの先頭アドレス
            auto it = lft.upper_bound(x);
            it--;
            auto pt = it;
            auto l = *it;
            int r;
            pt++;
            if(pt == lft.end()) {
                r = n;
            } else {
                r = *pt;
            }

            // 書き換え対象色
            auto tc = arcol[*it];
            arcol[*it] = c;
            col[tc] -= (r-l);
            col[c] += (r-l);

            // 右側の隣接エリアが同色な限り消していく
            while(pt != lft.end() && arcol[*pt] == c) {
                pt = lft.erase(pt);
            }

            // 左側の隣接エリアが同色な限り右のエリアを消していく
            pt = it;
            auto pre = pt;
            pt--;
            while(pre != lft.begin() && arcol[*pt] == c) {
                lft.erase(pre);
                pre = pt;
                pt--;
            }
        } else {
            Def(c);
            c--;
            cout << col[c] << endl;
        }
    }
}
