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

ll get_lca(ll u, ll v, vl &d, vl2 &prt, ll LOGN) {
    if (d[u] < d[v]) swap(u, v);

    rrep(i, LOGN) {
        if(prt[u][i] != -1 && d[prt[u][i]] >= d[v]) {
            u = prt[u][i];
        }
    }

    if (u == v) return u;

    rrep(i, LOGN) {
        if(prt[u][i] != -1 && prt[u][i] != prt[v][i]) {
            u = prt[u][i];
            v = prt[v][i];
        }
    }

    return prt[u][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 対象のグラフは木
    // n <= 10^5
    Def(n);
    DefA(x, n);
    vpl2 t(n, vpl());
    rep(i, n-1) {
        Def3(u, v, w);
        u--; v--;
        t[u].push_back({v, w});
        t[v].push_back({u, w});
    }

    ll LOGN = 17;
    vl2 prt(n, vl(LOGN, -1));
    vl d(n, -1);
    d[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()) {
        ll tp = q.front();
        q.pop();
        rep(i, t[tp].size()) {
            if(d[t[tp][i].first] < 0) {
                d[t[tp][i].first] = d[tp]+1;
                q.push(t[tp][i].first);
            }
        }
    }
    srep(i, 1, LOGN) {
        rep(j, n) {
            if(prt[j][i-1] != -1) {
                prt[j][i] = prt[prt[j][i-1]][i-1];
            } else {
                prt[j][i] = -1;
            }
        }
    }


    priority_queue<pl> q;
    rep(i, n) {
        q.push({t[i].size(), i});
    }
    vb fin(n, false);
    ll ans{0};
    while(!q.empty()) {
        auto [, tp] = q.top();
        q.pop();
        if(fin[tp]) continue;
        priority_queue<pl> q2;
        rep(i, t[tp].size()) {
            if(!fin[t[tp][i]]) q2.push({t[tp][i].second, t[tp][i].first});
        }
        while(!q2.empty()) {
            quto [,tp2] = q2.top();
            q2.pop();
            if(x[tp]*x[tp2] < 0) {
                ll lca = get_lca(tp, tp2, d, prt, LOGN);
                if(abs(x[tp]) == abs(x[tp2])) {
                    x[tp] = 0;
                    x[tp2] = 0;
                    fin[tp] = true;
                    fin[tp2] = true;
                    break;
                } else if(abs(x[tp]) > abs(x[tp2])) {
                    x[tp] += x[tp2];
                    x[tp2] = 0;
                    fin[tp2] = true;
                } else if(abs(x[tp]) < abs(x[tp2])) {
                    x[tp2] += x[tp];
                    x[tp] = 0;
                    fin[tp] = true;
                    break;
                }
            }
            if(!x[tp]) break;
        }
    }
}
