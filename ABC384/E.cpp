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

    Def(h);
    Def(w);
    Def(x);
    Def(p);
    Def(q);
    p--; q--;
    vl2 s(h, vl(w, 0));

    rep(i, h) rep(j, w) cin >> s[i][j];
    priority_queue<pair<ll, pl>, vector<pair<ll, pl>>, greater<pair<ll, pl>>> pq;
    vb2 st(h, vb(w, true));
    st[p][q] = false;
    ll cur = s[p][q];
    vl dx = {1, -1, 0, 0};
    vl dy = {0, 0, 1, -1};
    rep(i, 4) {
        auto nx = p+dx[i];
        auto ny = q+dy[i];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w) {
            pq.push(make_pair(s[nx][ny], make_pair(nx, ny)));
        }
    }
    while(!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        /* cout << "DB:" << cur << " " << tp.first << " " << tp.second.first << " " << tp.second.second << endl; */
        if(tp.first < (cur+x-1)/x) {
            auto tx = tp.second.first;
            auto ty = tp.second.second;
            if(st[tx][ty]) {
                cur += tp.first;
                st[tx][ty] = false;
                rep(i, 4) {
                    auto nx = tx+dx[i];
                    auto ny = ty+dy[i];
                    if(nx >= 0 && nx < h && ny >= 0 && ny < w && st[nx][ny]) {
                        pq.push(make_pair(s[nx][ny], make_pair(nx, ny)));
                    }
                }
            }
        }
    }
    cout << cur << endl;
}
