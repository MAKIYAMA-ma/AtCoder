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

typedef struct {
    int x, y, count;
    set<int> path;
} ST_PT;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(h);
    Def(w);
    Def(k);

    vs s(h);
    rep(i, h) {
        cin >> s[i];
    }

    ll ans{0};
    vi dx = {1, -1, 0, 0};
    vi dy = {0, 0, 1, -1};
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '.') {
                stack<ST_PT> st;
                st.push({i, j, 0, {}});
                while(!st.empty()) {
                    auto tp = st.top();
                    st.pop();
                    rep(i, 4) {
                        int nx = tp.x + dx[i];
                        int ny = tp.y + dy[i];
                        if((nx >= 0) && (nx < h) && (ny >= 0) && (ny < w) && s[nx][ny] == '.') {
                            if(tp.path.find(nx*w + ny) == tp.path.end()) {
                                auto nxt = tp;
                                nxt.path.insert((tp.x)*w + tp.y);
                                nxt.x = nx;
                                nxt.y = ny;
                                nxt.count++;
                                if(nxt.count == k) {
                                    ans++;
                                } else {
                                    st.push(nxt);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
}