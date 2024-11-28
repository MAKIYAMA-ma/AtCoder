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
    vs s(h);
    rep(i, h) cin >> s[i];

    // 磁石のマス及び上下左右は通過不能
    // ただし、到達点としては利用可能
    // 停止マスで囲まれた領域について、停止マスをふくむ最大面積が知りたい
    vl2 mp(h, vl(w, 0));
    vl dh = {1, -1, 0, 0};
    vl dw = {0, 0, 1, -1};
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '#') {
                mp[i][j] = 2;
                rep(k, 4) {
                    auto nh = i + dh[k];
                    auto nw = j + dw[k];
                    if(nh >= 0 && nh < h && nw >= 0 && nw < w) {
                        if(mp[nh][nw] == 0) mp[nh][nw] = 1;
                    }
                }
            }
        }
    }
    /* rep(i, h) { */
    /*     rep(j, w) { */
    /*         cout << mp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    vb2 visited(h, vb(w, false));
    vb2 v2(h, vb(w, false));
    ll ans{1};
    rep(i, h) {
        rep(j, w) {
            if(mp[i][j] == 0 && !visited[i][j]) {
                /* cout << "DB:" << i << " " << j << endl; */
                stack<pi> st;
                ll cnt{0};
                st.push(make_pair(i, j));
                for(auto &r : v2) {
                    fill(all(r), false);
                }
                while(!st.empty()) {
                    auto tp = st.top();
                    st.pop();
                    if(v2[tp.first][tp.second]) continue;
                    v2[tp.first][tp.second] = true;
                    if(mp[tp.first][tp.second] == 0) {
                        /* cout << "DB2:" << tp.first<< " " << tp.second<< endl; */
                        cnt++;
                        visited[tp.first][tp.second] = true;
                        rep(k, 4) {
                            auto nh = tp.first + dh[k];
                            auto nw = tp.second + dw[k];
                            if(nh >= 0 && nh < h && nw >= 0 && nw < w) {
                                st.push(make_pair(nh, nw));
                            }
                        }
                    } else if(mp[tp.first][tp.second] == 1) {
                        /* cout << "DB3:" << tp.first<< " " << tp.second<< endl; */
                        cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans << endl;
}
