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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(h, w);
    vs s(h);
    rep(i, h) cin >> s[i];
    vl2 d(h, vl(w, MAXLL));

#if 1
    queue<pl> q;
    vl dh = {1, -1, 0, 0};
    vl dw = {0, 0, 1, -1};
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == 'E') {
                q.push({i, j});
                d[i][j] = 0;
            }
        }
    }
    while(!q.empty()) {
        auto [th, tw] = q.front();
        q.pop();
        if(s[th][tw] == '#') continue;
        rep(j, 4) {
            ll nh = th+dh[j];
            ll nw = tw+dw[j];
            if(nh >= 0 && nh < h && nw >= 0 && nw < w && s[nh][nw] != '#' && d[nh][nw] > (d[th][tw]+1)) {
                d[nh][nw] = d[th][tw]+1;
                q.push({nh, nw});
            }
        }
    }
#else
    vpl st;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == 'E') {
                st.push_back({i, j});
                d[i][j] = 0;
            }
        }
    }
    vl dh = {1, -1, 0, 0};
    vl dw = {0, 0, 1, -1};
    rep(i, st.size()) {
        queue<pl> q;
        q.push({st[i].first, st[i].second});
        while(!q.empty()) {
            auto [th, tw] = q.front();
            q.pop();
            rep(j, 4) {
                ll nh = th+dh[j];
                ll nw = tw+dw[j];
                if(nh >= 0 && nh < h && nw >= 0 && nw < w && s[nh][nw] != '#' && d[nh][nw] > (d[th][tw]+1)) {
                    d[nh][nw] = d[th][tw]+1;
                    q.push({nh, nw});
                }
            }
        }
    }
#endif
    /* rep(i, h) { */
    /*     rep(j, w) { */
    /*         cout << d[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    vector<char> c = {'v', '^', '>', '<'};
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] != '.') continue;
            rep(k, 4) {
                ll nh = i+dh[k];
                ll nw = j+dw[k];
                if(nh >= 0 && nh < h && nw >= 0 && nw < w && s[nh][nw] != '#' && d[i][j] == (d[nh][nw]+1)) {
                    s[i][j] = c[k];
                }
            }
        }
    }
    rep(i, h) cout << s[i] << endl;
}
