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

bool check(vs &s, ll h, ll w, ll mh, ll mw) {
    /* cout << "DB2:" << h << ", " << w << endl; */
    ll cnt{0};
    if(h-1 >= 0 && s[h-1][w] == '#') cnt++;
    if(w-1 >= 0 && s[h][w-1] == '#') cnt++;
    if(h+1 < mh && s[h+1][w] == '#') cnt++;
    if(w+1 < mw && s[h][w+1] == '#') cnt++;
    return (cnt == 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(h, w);
    vs s(h);
    rep(i, h) cin >> s[i];

    ll ans{0};
    queue<pl> q;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                ans++;
                q.push({i, j});
            }
        }
    }
    vl dh = {1, -1, 0, 0};
    vl dw = {0, 0, 1, -1};
    while(true) {
        set<pl> nb;
        while(!q.empty()) {
            auto [th, tw] = q.front();
            q.pop();
            rep(i, 4) {
                ll nh = th+dh[i];
                ll nw = tw+dw[i];
                if(nh < 0 || nw < 0 || nh >= h || nw >= w) continue;
                if(s[nh][nw] == '#') continue;
                if(check(s, nh, nw, h, w)) {
                    /* cout << "DB:" << nh << ", " << nw << endl; */
                    /* s[nh][nw] = '#'; */
                    nb.insert({nh, nw});
                }
            }
        }
        if(nb.size() > 0) {
            ans += nb.size();
            for(auto [nh, nw] : nb) {
                s[nh][nw] = '#';
                q.push({nh, nw});
            }
        } else {
            break;
        }
    }
    /* cout << "--------------" << endl; */
    /* rep(i, h) cout << s[i] << endl; */
    /* cout << "--------------" << endl; */
    cout << ans << endl;
}
