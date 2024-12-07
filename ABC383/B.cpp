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
    Def(d);
    vs s(h);
    rep(i, h) cin >> s[i];

    vector<set<pl>> cand;
    rep(i, h) {
        rep(j, w) {
            if(s[i][j] == '.') {
                /* cout << "DB:" << i << " " << j << endl; */
                set<pl> tmp;
                srep(k, max((ll)0, i-d), min(h,i+d+1)) {
                    srep(l, max((ll)0, j-(d-abs(i-k))), min(w, j+(d-abs(i-k))+1)) {
                        if(s[k][l] == '.') {
                            /* cout << "    " << k << " " << l << endl; */
                            tmp.insert(make_pair(k, l));
                        }
                    }
                }
                cand.push_back(tmp);
            }
        }
    }

    ll ans{0};
    rep(i, cand.size()-1) {
        srep(j, i+1, cand.size()) {
            set<pl> tmp;
            for(auto c : cand[i]) {
                tmp.insert(c);
            }
            for(auto c : cand[j]) {
                tmp.insert(c);
            }
            ans = max(ans, (ll)tmp.size());
        }
    }
    cout << ans << endl;
}
