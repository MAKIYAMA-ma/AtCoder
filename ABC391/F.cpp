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

typedef struct st_pos{
    ll a, b, c;

    bool operator<(const struct st_pos &other) const {
        return tie(a, b, c) < tie(other.a, other.b, other.c);
    }
} ST_POS;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(n, k);
    DefA(a, n);
    DefA(b, n);
    DefA(c, n);
    sort(rall(a));
    sort(rall(b));
    sort(rall(c));

    priority_queue<pair<ll, ST_POS>> pq;
    pq.push({a[0]*b[0] + b[0]*c[0] + c[0]*a[0], {0, 0, 0}});

    ll nm{0};
    ll ans{0};
    set<ST_POS> fin;
    vl da = {1, 0, 0};
    vl db = {0, 1, 0};
    vl dc = {0, 0, 1};
    while(nm < k) {
        if(pq.empty()) break;   // 来ないはず
        auto [val, pos] = pq.top();
        pq.pop();

        if(fin.find(pos) != fin.end()) continue;
        fin.insert(pos);

        ans = val;
        /* cout << "DB:" << val << endl; */
        rep(i, 3) {
            ST_POS np = {pos.a + da[i], pos.b + db[i], pos.c + dc[i]};
            if(np.a < n && np.b < n && np.c < n) {
                pq.push({a[np.a]*b[np.b] + b[np.b]*c[np.c] + c[np.c]*a[np.a], np});
            }
        }
        nm++;
    }
    cout << ans << endl;
}
