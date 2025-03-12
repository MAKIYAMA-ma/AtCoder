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
#define Def2(m, n) ll m, n; cin >> m >> n;
#define Def3(l, m, n) ll l, m, n; cin >> l >> m >> n;
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

    Def3(n, m, k);
    vl2 edge(n, vl());
    rep(i, m) {
        Def2(a, b);
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    Def2A(p, h, k);
    // k,h <= n <= 2*10^5
    // 各警備員からBFSとかだとO(n^2)になるのでTLE
    // WarshallFloydとかやったらO(n^3)
    //
    // 全頂点から同時にBFSすればほぼO(n)に近いオーダーで行けるのでは？？

    priority_queue<pl> pq;
    vl wc(n, -1);
    rep(i, k) {
        wc[p[i]-1] = h[i];
    }
    rep(i, n) pq.push({wc[i], i});

    vb fin(n, false);
    set<ll> ans;
    while(!pq.empty()) {
        auto [w, idx] = pq.top();
        pq.pop();

        if(w < 0) break;
        if(fin[idx]) continue;

        ans.insert(idx);
        fin[idx] = true;
        for(auto v : edge[idx]) {
            if(wc[v] < (w-1)) {
                wc[v] = w-1;
                pq.push({wc[v], v});
            }
        }
    }

    cout << ans.size() << endl;
    for(auto v : ans) cout << v+1 << " ";
    cout << endl;
}
