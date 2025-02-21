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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    vs s(n);
    rep(i, n) cin >> s[i];

    // n, m <= 200
    // 到達可能な位置のマップは作れる
    // その中で最長のものはどれか
    //
    // 途中の経路次第で同じ2点間でも追加得点が変わる
    // 経路が決まったらその経路が何点かは分かるが。。。
    // 複数回踏むマスを加味して最長のパスをどう探すのが良いのか
    // 別の点として管理する？
#if 1
    vl2 st(n, vl(m, 0));
    vb2 fin(n, vb(m, false));
    st[1][1] = 1;
    queue<pl> q;
    q.push({1, 1});

    vl dn = {1, -1, 0, 0};
    vl dm = {0, 0, 1, -1};

    while(!q.empty()) {
        auto [tn, tm] = q.front();
        q.pop();
        if(fin[tn][tm]) continue;
        fin[tn][tm] = true;

        rep(i, 4) {
            ll pn, pm;
            ll nn = tn;
            ll nm = tm;
            while(s[nn][nm] != '#') {
                st[nn][nm] = 1;
                pn = nn;
                pm = nm;
                nn += dn[i];
                nm += dm[i];
            }
            q.push({pn, pm});
        }
    }
    ll ans{0};
    rep(i, n) ans += reduce(all(st[i]));
    cout << ans << endl;
#else
    // 勘違いしてた。。。
    // 一筆書きで最大何マス踏めるかの話かと。。。
    ll ans{1};
    vl2 st(n, vl(m, 0));
    st[1][1] = 1;
    queue<pair<pl, vl2>> q;
    q.push({{1, 1}, st});

    vl dn = {1, -1, 0, 0};
    vl dm = {0, 0, 1, -1};

    vl2 pt(n, vl(m, 0));

    while(!q.empty()) {
        auto tp = q.front();
        q.pop();
        auto [tn, tm] = tp.first;

        ll curp{0};
        rep(i, tp.second.size()) {
            curp += reduce(all(tp.second[i]));
        }
        ans = max(ans, curp);

        /* cout << "DB:" << tn << " " << tm << ":" << curp << endl; */
        /* rep(i, tp.second.size()) { */
        /*     rep(j, tp.second[i].size()) { */
        /*         cout << tp.second[i][j]; */
        /*     } */
        /*     cout << endl; */
        /* } */

        if(pt[tn][tm] >= curp) continue;
        pt[tn][tm] = curp;

        rep(i, 4) {
            auto tst = tp.second;
            ll pn, pm;
            ll nn = tn;
            ll nm = tm;
            while(s[nn][nm] != '#') {
                tst[nn][nm] = 1;
                pn = nn;
                pm = nm;
                nn += dn[i];
                nm += dm[i];
            }
            q.push({{pn, pm}, tst});
        }
    }
    cout << ans << endl;
#endif
}
