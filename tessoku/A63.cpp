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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;
#define Def(n) ll n; cin >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];

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


bool search(vl2 &edge, int pos, int goal, vb &visited, vi &path) {
    if(pos == goal) {
        path.push_back(pos);
        return true;
    }
    if(visited[pos]) return false;
    visited[pos] = true;
    for(auto e : edge[pos]) {
        if(search(edge, e, goal, visited, path)) {
            path.push_back(pos);
            return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    vl2 edge(n, vl());
    rep(i, m) {
        Def(a);
        Def(b);
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    queue<int> q;
    vi cost(n, MAXI);
    cost[0] = 0;
    q.push(0);
    while(!q.empty()) {
        auto nxt = q.front();
        q.pop();
        for(auto e : edge[nxt]) {
            if(cost[e] > cost[nxt]+1) {
                cost[e] = cost[nxt]+1;
                q.push(e);
            }
        }
    }
    rep(i, n) {
        cout << ((cost[i] >= MAXI) ? -1 : cost[i]) << endl;
    }
}
