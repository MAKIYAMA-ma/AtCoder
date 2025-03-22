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
    vsl edge(n, sl());
    rep(i, n-1) {
        Def2(u, v);
        u--; v--;
        edge[u].insert(v);
        edge[v].insert(u);
    }

    vl pt(n, -1);
    pt[0] = 0;
    queue<ll> q;
    q.push(0);
    while(!q.empty()) {
        auto tp = q.front();
        q.pop();
        for(auto v : edge[tp]) {
            if(pt[v] < 0) {
                pt[v] = pt[tp]+1;
                q.push(v);
            }
        }
    }

    set<pl> cand;
    rep(i, n) {
        srep(j, i+1, n) {
            if((pt[i]%2 != pt[j]%2) && (edge[i].find(j) == edge[i].end())) {
                cand.insert({i, j});
            }
        }
    }

    /* cout << "-----" << endl; */
    /* for(auto [f, s] : cand) cout << f << " " << s << endl; */
    /* cout << "-----" << endl; */

    if(cand.size()%2) {
        cout << "First" << endl;
        auto ply = *cand.begin();
        cout << ply.first+1 << " " << ply.second+1 << endl;
        cand.erase(ply);
    } else {
        cout << "Second" << endl;
    }

    while(true) {
        Def2(tu, tv);
        if(tu == -1 && tv == -1) return 0;
        tu--; tv--;
        cand.erase({min(tu, tv), max(tu, tv)});
        auto ply = *cand.begin();
        cout << ply.first+1 << " " << ply.second+1 << endl;
        cand.erase(ply);
    }
}
