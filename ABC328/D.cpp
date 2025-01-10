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

typedef struct st_node{
    struct st_node* b;
    struct st_node* n;
    char d;
} NODE;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;
    string t = "ABC";

    // ABCを消す順番は考慮不要。
    // 一度できたABCが、他のABCを消す際に崩れることはない
    // s.length() <= 2*10^5
#if 1
    vector<NODE> lst(s.length(), {NULL, NULL, '.'});
    rep(i, s.length()) {
        lst[i].b = ((i > 0) ? &lst[i-1] : NULL);
        lst[i].n = ((i < s.length()-1) ? &lst[i+1] : NULL);
        lst[i].d = s[i];
    }
    NODE *nd = &lst[0];
    NODE *top = nd;
    while(nd != NULL) {
        NODE *sch = nd;
        bool clr{true};
        rep(i, t.length()) {
            if(sch == NULL || sch->d != t[i]) {
                clr = false;
                break;
            }
            sch = sch->n;
        }
        if(clr) {
            if(nd->b == NULL) {
                if(sch != NULL) sch->b = NULL;
                top = sch;
                nd = sch;
            } else {
                nd->b->n = sch;
                if(sch != NULL) sch->b = nd->b;
                rep(i, t.length()-1) {
                    if(nd->b != NULL) nd = nd->b;
                }
            }
        } else {
            nd = nd->n;
        }
    }
    nd = top;
    while(nd != NULL) {
        cout << nd->d;
        nd = nd->n;
    }
    cout << endl;
#else
    ll i{0};
    while(i < s.length()) {
        bool tg{true};
        ll j{0}
        while((j < t.length()) && (i+j < s.length())) {
            if(s[i+j] == '#')
            if(s[i+j] != t[j]) {
                tg = false;
                break;
            }
        }
        if(tg) {
            rep(j, t.length()) s[i+j] = '#';
            i = min(0LL, i-t.length());
        } else {
            i++;
        }
        cout << "DB:" << s << endl;
    }
    rep(i, s.length()) {
        if(s[i] != '#') cout << s[i];
    }
    cout << endl;
#endif
}
