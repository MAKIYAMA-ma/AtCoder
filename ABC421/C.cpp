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
#define Def3A(a, b, c, n) vl a(n); vl b(n); vl c(n); rep(i, n) cin >> a[i] >> b[i] >> c[i];
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
    string s;
    cin >> s;

    // n <= 5*10^5
    sl al, bl;
    rep(i, s.length()) {
        if(s[i] == 'A') {
            al.insert(i);
        } else {
            bl.insert(i);
        }
    }

    ll aa{0};
    ll t{0};
    if(al.size() < bl.size()) {
        aa = MAXLL;
    }else{
        while(!al.empty() && !bl.empty()) {
            auto ta = *al.begin();
            auto tb = *bl.begin();
            /* cout << "DB1:" << t << ":" << aa << ":" << ta << ", " << tb << endl; */
            if(t%2 == 0) {
                if(ta == t) {
                    al.erase(ta);
                } else {
                    aa += (ta-t);
                    bl.insert(ta);
                    al.erase(ta);
                    bl.erase(tb);
                }
            } else {
                if(tb == t) {
                    bl.erase(tb);
                } else {
                    aa += (tb-t);
                    al.insert(tb);
                    bl.erase(tb);
                    al.erase(ta);
                }
            }
            t++;
        }
    }

    sl al2, bl2;
    rep(i, s.length()) {
        if(s[i] == 'A') {
            al2.insert(i);
        } else {
            bl2.insert(i);
        }
    }

    ll ab{0};
    t = 0;
    if(al.size() > bl.size()) {
        ab = MAXLL;
    }else{
        while(!al2.empty() && !bl2.empty()) {
            auto ta = *al2.begin();
            auto tb = *bl2.begin();
            /* cout << "DB2:" << t << ":" << ab << ":" << ta << ", " << tb << endl; */
            if(t%2 == 0) {
                if(tb == t) {
                    bl2.erase(tb);
                } else {
                    ab += (tb-t);
                    al2.insert(tb);
                    bl2.erase(tb);
                    al2.erase(ta);
                }
            } else {
                if(ta == t) {
                    al2.erase(ta);
                } else {
                    ab += (ta-t);
                    bl2.insert(ta);
                    al2.erase(ta);
                    bl2.erase(tb);
                }
            }
            t++;
        }
    }
    cout << min(aa, ab) << endl;
}
