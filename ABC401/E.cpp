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

    Def2(n, m);
    vl2 edge(n, vl());
    rep(i, m) {
        Def2(u, v);
        u--; v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    rep(i, n) sort(all(edge[i]));

#if 1
    vb rch(n, false);
    unordered_set<ll> pool; // 現状到達不能の点
    rch[0] = true;
    srep(i, 1, n) {
        // iが0から到達可能かチェック
        bool ok{false};
        rep(j, edge[i].size()) {
            if(edge[i][j] > i) break;
            if(pool.find(edge[i][j]) == pool.end()) {
                ok = true;
                break;
            }
        }
        if(ok) {
            // iが0から到達可能なら、iから到達可能な点をpoolから除去
            queue<ll> q;
            rep(j, edge[i].size()) {
                if(edge[i][j] > i) break;
                q.push(edge[i][j]);
            }
            while(!q.empty()) {
                auto tp = q.front();
                q.pop();
                if(pool.find(tp) != pool.end()) {
                    pool.erase(tp);
                    rep(j, edge[tp].size()) {
                        if(edge[tp][j] > i) break;
                        q.push(edge[tp][j]);
                    }
                }
            }
        } else {
            pool.insert(i);
        }
        // 到達不能なi以下の点がないならOK
        rch[i] = (pool.size() == 0);
    }
#else
    // TODO
    // iが1から到達可能、
    // かつiに直結されていないj < iについて、すべてのjが到達可能である必要がある
    // でもこれ普通にチェックしようとするとTLEでは？
    // 到達可能か判定
    vb rch(n, false);
    rch[0] = true;
    srep(i, 1, n) {
        rep(j, edge[i].size()) {
            if(edge[i][j] > i) break;
            if(rch[edge[i][j]]) {
                rch[i] = true;
                break;
            }
        }
    }

    vb clr(n, false);
    clr[0] = true;
    sl pool; // 現状到達不能の点
    rep(i, n) {
        if(!rch[i]) {
            pool.insert(i);
        } else {
            queue<ll> q;
            rep(j, edge[i].size()) {
                if(edge[i][j] > i) break;
                q.push(edge[i][j]);
            }
            while(!q.empty()) {
                auto tp = q.front();
                q.pop();
                if(pool.find(tp) != pool.end()) {
                    pool.erase(tp);
                    rep(j, edge[tp].size()) {
                        if(edge[tp][j] > i) break;
                        q.push(edge[tp][j]);
                    }
                }
            }
        }
        clr[i] = (pool.size() == 0);
    }
#endif

    vl ans(n, 0);
    srep(i, 1, n) {
        // iに接続された最小の点jがi以下である場合、jまで残す場合~i-1まで残すまでの場合の間は、
        // iは削除が必要
        if(edge[i].size() > 0 && i >= edge[i][0]) {
            ans[edge[i][0]]++;
            ans[i]--;
        }
    }
    srep(i, 1, n) {
        ans[i] += ans[i-1];
    }
    rep(i, n) {
        if(!rch[i]) {
            cout << -1 << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
}
