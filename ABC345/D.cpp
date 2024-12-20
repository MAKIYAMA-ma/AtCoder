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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(h);
    Def(w);

    Def2A(a, b, n);

    // 1≤N≤7
    // 1≤H,W≤10
    // 1≤Ai,Bi≤10
    // やけに制約が小さい
    //
    // (1) タイルを詰める順序7!
    // (2) 各タイルの向き2^7
    // で全探索
    // 前から順番に詰めて、ラストまで来たらOK、ということなら、そもそもタイルを使うかどうかの選択は不要
    vb2 tl(h, vb(w, false));
    vl od(n, 0);
    rep(i, n) od[i] = i;

    do {
        rep(i, 1<<n) {
            ll num{0};
            bool res{true};
            rep(j, tl.size()) {
                fill(all(tl[j]), false);
            }
            rep(j, n) {
                ll th, tw;
                if(i & (1 << j)) {
                    th = a[od[j]];
                    tw = b[od[j]];
                } else {
                    th = b[od[j]];
                    tw = a[od[j]];
                }
                while(num < (h*w) && tl[num/w][num%w]) num++;
                if(num == h*w) {
                    // 全て埋まった
                    Yes(1);
                    return 0;
                }
                auto luh = num/w;
                auto luw = num%w;

                if(luh+th > h || luw+tw > w) {
                    res = false;
                    /* cout << "DB1:" << endl << "    "; */
                    /* rep(k, od.size()) cout << od[k] << " "; */
                    /* cout << endl; */
                    /* cout << "    " << i << " " << j << endl; */
                    /* cout << "    " << luh << " " << luw << endl; */
                    /* cout << "    " << th << " " << tw << endl; */
                    break;
                } else {
                    srep(k, luh, luh+th) {
                        srep(l, luw, luw+tw) {
                            if(tl[k][l]) {
                                res = false;
                                /* cout << "DB2:" << endl << "    "; */
                                /* rep(k, od.size()) cout << od[k] << " "; */
                                /* cout << endl; */
                                /* cout << "    " << i << " " << j << endl; */
                                break;
                            }
                            tl[k][l] = true;
                        }
                        if(!res) break;
                    }
                }
            }
            if(res) {
                while(num < (h*w) && tl[num/w][num%w]) num++;
                if(num == h*w) {
                    // 最後のタイルで全て埋まった
                    Yes(1);
                    return 0;
                }
            }
        }
    } while (next_permutation(all(od)));
    Yes(0);
}
