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
    string s, t;
    cin >> s >> t;

    // なんか両脇から削っていく感じで再帰的にできない？
    // m <= 5とかなり短いから、頭が欠けるケースもそのまま探索可能では。
    // tは同じ文字を含みうる点は要警戒

    queue<ll> q;
    rep(i, n-m+1) q.push(i);
#if 1
    while(!q.empty()) {
        ll nxt = q.front();
        q.pop();

        bool p{true};
        rep(i, m) {
            if((nxt+i >= n) || ((s[nxt+i] != t[i]) && (s[nxt+i] != '#'))) {
                p = false;
                break;
            }
        }
        if(p) {
            rep(i, m) s[nxt+i] = '#';
            srep(i, max(0LL, nxt-m), min(n-m, nxt+m)) {
                bool ok{true};
                bool ns{false};
                rep(j, m) {
                    if((s[i+j] != t[j]) && (s[i+j] != '#')) {
                        ok = false;
                        break;
                    } else if (s[i+j] != '#') {
                        ns = true;
                    }
                }
                if(ok && ns) q.push(i);
            }
        }
    }
#else
    ll pre{-1};
    bool done{false};

    while(!q.empty()) {
        ll nxt = q.front();
        q.pop();

        if(pre >= nxt) {
            // 一周
            /* cout << "DB:" << s << endl; */
            if(!done) {
                break;
            } else {
                done = false;
            }
        }
        pre = nxt;

        bool p{true};
        rep(i, m) {
            if((nxt+i >= n) || ((s[nxt+i] != t[i]) && (s[nxt+i] != '#'))) {
                p = false;
                break;
            }
        }
        if(p) {
            rep(i, m) s[nxt+i] = '#';
            done = true;
        } else {
            q.push(nxt);
        }
    }
#endif

    rep(i, n) {
        if(s[i] != '#') {
            Yes(0);
            return 0;
        }
    }
    Yes(1);
}
