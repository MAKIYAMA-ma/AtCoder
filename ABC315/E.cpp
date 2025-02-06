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

    // 読むべき本の列挙はたやすい
    // 順序の決定はどうするか
    // 1冊読むごとに他の本の前提を再整理だとO(n^2)になってしまう
    // -> あとに続く本も管理すれば良い
    //
    vl c(n);
    vector<set<ll>> p(n, set<ll>());
    vector<set<ll>> nx(n, set<ll>());
    rep(i, n) {
        cin >> c[i];
        rep(j, c[i]) {
            Def(tmp);
            tmp--;
            p[i].insert(tmp);
            nx[tmp].insert(i);
        }
    }

    vl ans;
    set<ll> nd;
    vb nc(n, false);
    queue<ll> q;
    queue<ll> cand;
    q.push(0);
    nd.insert(0);
    while(!q.empty()) {
        auto tp = q.front();
        q.pop();
        for(auto v : p[tp]) {
            if(nd.find(v) == nd.end()) {
                nd.insert(v);
                q.push(v);
                nc[v] = true;
            }
        }
    }
    rep(i, n) {
        if(nc[i] && p[i].size() == 0) {
            nd.erase(i);
            cand.push(i);
        }
    }

    while(!cand.empty()) {
        auto tp = cand.front();
        set<ll> er;
        cand.pop();
        if(tp == 0) break;
        ans.push_back(tp);
        for(auto v : nx[tp]) {
            p[v].erase(tp);
            if(p[v].size() == 0 && nd.find(v) != nd.end()) {
                nd.erase(v);
                cand.push(v);
            }
        }
    }
    for(auto v : ans) {
        cout << v+1 << " ";
    }
    cout << endl;
}
