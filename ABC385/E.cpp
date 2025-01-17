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

    // どこを根にすべきか先に決定可能か否か
    // 各点を根にした場合に最大のユ木の頂点数を調べられるか？
    //
    // 子の個数、各子の下の孫の個数が確定すれば全体の頂点数はO(1)
    // -> 削除する個数もO(1)
    //
    // 各頂点に幾つ頂点が隣接しているかをカウント
    //
    // 各根に置いて、孫の数を幾つにするか、全て試すとTLE
    // そもそも現状の孫の個数のどれかが解になるはずだから、
    // 1ずつインクリメントではなく孫の個数のsetに対してのみチェックすれば良い
    vector<set<ll>> uv(n, set<ll>());
    rep(i, n-1) {
        Def(u);
        Def(v);
        u--; v--;
        uv[u].insert(v);
        uv[v].insert(u);
    }

    ll ans{0};
    rep(i, n) {
        vl cc;
        set<ll> cand;
        for(auto cn : uv[i]) {
            if(uv[cn].size() > 1) {
                cc.push_back(uv[cn].size()-1);
                cand.insert(uv[cn].size()-1);
            }
        }
        sort(all(cc));
        for(auto j : cand) {
            ll nm = cc.end() - lower_bound(all(cc), j);
            if(nm <= 0) break;
            ans = max(ans, 1 + nm + nm*j);
        }
    }
    cout << n-ans << endl;
}
