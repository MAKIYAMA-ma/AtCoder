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

    Def(n1);
    Def(n2);
    Def(m);
    vl2 e(n1+n2, vl());
    rep(i, m) {
        Def(a);
        Def(b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    vl d1(n1, MAXLL);
    vl d2(n2, MAXLL);
    d1[0] = 0;
    d2[n2-1] = 0;

    // 始点からの距離をBFS
    queue<ll> q1;
    q1.push(0);
    while(!q1.empty()) {
        auto tp = q1.front();
        q1.pop();
        for(auto nxt : e[tp]) {
            if(d1[nxt] > d1[tp]+1) {
                d1[nxt] = d1[tp]+1;
                q1.push(nxt);
            }
        }
    }
    // 終点からの距離をBFS
    queue<ll> q2;
    q2.push(n1+n2-1);
    while(!q2.empty()) {
        auto tp = q2.front();
        q2.pop();
        for(auto nxt : e[tp]) {
            if(d2[nxt-n1] > d2[tp-n1]+1) {
                d2[nxt-n1] = d2[tp-n1]+1;
                q2.push(nxt);
            }
        }
    }
    /* rep(i, d1.size()) cout << d1[i] << " "; */
    /* cout << endl; */
    /* rep(i, d2.size()) cout << d2[i] << " "; */
    /* cout << endl; */
    // 始点と終点の最遠点を結べばよい
    cout << *max_element(all(d1))+*max_element(all(d2))+1 << endl;
}
