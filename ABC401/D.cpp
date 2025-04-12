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

bool check(string &s, ll idx, char c, ll cnt, ll k, vl rc) {
    if(c=='o') cnt++;
    if(idx == (s.length()-1)) {
        return (cnt == k);
    }
    if(cnt + ((idx+1 < s.length())?rc[idx+1]:0) > k) {
        return false;
    }
    if(c == 'o' && s[idx+1] == 'o') {
        return false;
    }
    if(s[idx+1] != '?') {
        return(check(s, idx+1, s[idx+1], cnt, k, rc));
    } else if(s[idx] == 'o') {
        s[idx+1] = '.';
        return(check(s, idx+1, '.', cnt, k, rc));
    } else {
        string s1 = s, s2 = s;
        s1[idx+1] = 'o';
        bool r1 = check(s1, idx+1, 'o', cnt, k, rc);
        s2[idx+1] = '.';
        bool r2 = check(s2, idx+1, '.', cnt, k, rc);
        if(r1 && r2) {
            srep(i, idx+1, s.length()) {
                if(s1[i] == s2[i]) {
                    s[i] = s1[i];
                } else {
                    s[i] = '?';
                }
            }
        } else if(r1) {
            s = s1;
        } else if(r2) {
            s = s2;
        } else {
            return false;
        }
        return true;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def2(n, k);
    string s;
    cin >> s;

    rep(i, n) {
        if(s[i] == '?') {
            if(i-1 >= 0 && s[i-1] == 'o') s[i] = '.';
            if(i+1 < n && s[i+1] == 'o') s[i] = '.';
        }
    }

    // oの次の？は.となるのが前提
    // 文字数的に全て確定してしまう可能性もある
    s = '.' + s;

    n++;
    vl rc(n, 0);
    if(s[n-1] == 'o') rc[n-1] = 1;
    rrep(i, n-1) {
        if(s[i] == 'o') {
            rc[i] = rc[i+1]+1;
        } else {
            rc[i] = rc[i+1];
        }
    }
    check(s, 0, '.', 0, k, rc);
    cout << s.substr(1, n) << endl;
}
