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
    vs a(h);
    rep(i, h) cin >> a[i];

    Def(n);

    vl2 e(h, vl(w, false));
    rep(i, n) {
        Def(r);
        Def(c);
        Def(p);
        r--; c--;
        e[r][c] = p;
    }

    // ゴールからたどる
    // 各マスからゴールにたどりつくために必要なエナジーを調べていく
    // 必要エナジー以上の薬があるならそのマスからの必要エナジーは0になる
    // これを繰り返して、Sのマスがの必要エナジーが0ならゴール可能
    pl st, gl;
    rep(i, h) {
        rep(j, w) {
            if(a[i][j] == 'S') {
                st.first = i;
                st.second = j;
            } else if(a[i][j] == 'T') {
                gl.first = i;
                gl.second = j;
            }
        }
    }

    vl2 nd(h, vl(w, MAXLL));
    nd[gl.first][gl.second] = 0;
    priority_queue<pair<ll, pl>, vector<pair<ll, pl>>, greater<pair<ll, pl>>> q;
    q.push(make_pair(0, gl));

    vl dx = {1, -1, 0, 0};
    vl dy = {0, 0, 1, -1};
    while(!q.empty()) {
        auto tgt = q.top();
        q.pop();
        rep(i, 4) {
            auto tx = tgt.second.first;
            auto ty = tgt.second.second;
            auto nx = tx + dx[i];
            auto ny = ty + dy[i];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && a[nx][ny] != '#') {
                auto np = nd[tx][ty] + 1;
                if(np <= e[nx][ny]) {
                    np = 0;
                }
                if(np < nd[nx][ny]) {
                    nd[nx][ny] = np;
                    q.push(make_pair(np, make_pair(nx, ny)));
                }
            }
        }
    }
    /* cout << "--------" << endl; */
    /* rep(i, h) { */
    /*     rep(j, w) { */
    /*         if(nd[i][j] == MAXLL) { */
    /*             cout << "M "; */
    /*         } else { */
    /*             cout << nd[i][j] << " "; */
    /*         } */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "--------" << endl; */
    Yes(nd[st.first][st.second] <= 0)
}
