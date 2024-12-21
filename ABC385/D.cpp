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
    Def(m);
    Def(sx);
    Def(sy);

    map<ll, set<ll>> xh, yh;
    rep(i, n) {
        Def(x);
        Def(y);
        xh[x].insert(y);
        yh[y].insert(x);
    }

    ll ans{0};
    rep(i, m) {
        ll nx = sx;
        ll ny = sy;
        char d;
        cin >> d;
        Def(c);
        switch(d) {
            case 'U': ny += c; break;
            case 'D': ny -= c; break;
            case 'L': nx -= c; break;
            case 'R': nx += c; break;
        }

        if(d == 'U' || d == 'D') {
            /* cout << "DB1" << endl; */
            if(xh.find(sx) != xh.end()) {
                /* cout << "DB2" << endl; */
                auto sp = xh[sx].lower_bound(min(sy, ny));
                /* cout << "DB3" << endl; */
                auto gp = xh[sx].upper_bound(max(sy, ny));
                /* cout << "DB4" << endl; */
                auto cnt = distance(sp, gp);
                /* cout << "DB5:" << cnt << " " << *sp << " " << *gp << endl; */
                if(cnt > 0) {
                    ans += cnt;
                    for(auto pt = sp; pt != gp; pt++) {
                        /* cout << "DB6" << endl; */
                        yh[*pt].erase(sx);
                        /* cout << "DB7" << endl; */
                    }
                    xh[sx].erase(sp, gp);
                }
                /* cout << "DB8" << endl; */
            }
        } else {
            /* cout << "DB9" << endl; */
            if(yh.find(sy) != yh.end()) {
                /* cout << "DB10" << endl; */
                auto sp = yh[sy].lower_bound(min(sx, nx));
                /* cout << "DB11" << endl; */
                auto gp = yh[sy].upper_bound(max(sx, nx));
                /* cout << "DB12" << endl; */
                auto cnt = distance(sp, gp);
                /* cout << "DB13:" << cnt << " " << *sp << " " << *gp << endl; */
                if(cnt > 0) {
                    ans += cnt;
                    for(auto pt = sp; pt != gp; pt++) {
                        /* cout << "DB14" << endl; */
                        xh[*pt].erase(sy);
                        /* cout << "DB15" << endl; */
                    }
                    yh[sy].erase(sp, gp);
                }
                /* cout << "DB16" << endl; */
            }
        }
        sx = nx;
        sy = ny;
        /* cout << "DB:" <<  sx << " " << sy << " " << ans << endl; */
    }
    cout << sx << " " << sy << " " << ans << endl;
}
