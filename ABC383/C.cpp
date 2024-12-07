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

    Def(h);
    Def(w);
    Def(d);
    vs s(h);
    rep(i, h) cin >> s[i];

    set<pl> heater;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == 'H') {
                heater.insert(make_pair(i, j));
            }
        }
    }
    vl2 st(h, vl(w, -1));
    vl dh = {1, -1, 0, 0};
    vl dw = {0, 0, 1, -1};
    for(auto ht : heater) {
        queue<pl> q;
        q.push(ht);
        st[ht.first][ht.second] = 0;
        while(!q.empty()) {
            auto tgt = q.front();
            q.pop();
            auto nv = st[tgt.first][tgt.second]+1;
            if(nv > d) continue;
            rep(i, 4) {
                auto nh = tgt.first + dh[i];
                auto nw = tgt.second + dw[i];
                if(nh >= 0 && nh < h && nw >= 0 && nw < w && s[nh][nw] == '.' && (st[nh][nw] == -1 || st[nh][nw] > nv)) {
                    st[nh][nw] = nv;
                    q.push(make_pair(nh, nw));
                }
            }
        }
    }
    ll ans{0};
    /* rep(i, h) { */
    /*     rep(j, w) { */
    /*         cout << st[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    rep(i, h) {
        rep(j, w) {
            if(st[i][j] >= 0) ans++;
        }
    }
    cout << ans << endl;
}
