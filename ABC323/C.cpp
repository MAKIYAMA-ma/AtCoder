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
    DefA(a, m);
    vs s(n);
    rep(i, n) cin >> s[i];

    ll m1{0}, m2{0};
    vl pt(n, 0);
    rep(i, n) {
        ll cnt{0};
        rep(j, m) {
            if(s[i][j] == 'o') {
                cnt += a[j];
            }
        }
        pt[i] = cnt + i + 1;
        if(pt[i] >= m1) {
            m2 = m1;
            m1 = pt[i];
        } else if (pt[i] > m2) {
            m2 = pt[i];
        }
    }

    vpl q(m);
    rep(i, m) {
        q.push_back(make_pair(a[i], i));
    }
    sort(rall(q));

    rep(i, n) {
        if(pt[i] == m1) {
            if(m1 != m2) cout << 0 << endl;
            else cout << 1 << endl;
        } else {
            ll ad{0};
            rep(j, m) {
                if(s[i][q[j].second] != 'o') {
                    pt[i] += q[j].first;
                    ad++;
                }
                if(pt[i] > m1) break;
            }
            cout << ad << endl;
        }
    }
}
