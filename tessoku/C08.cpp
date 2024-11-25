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

    Def(n);
    vs s(n);
    vi t(n);
    rep(i, n) cin >> s[i] >> t[i];

    // t = 1があれば即終了
    // t = 2なら一字違いのものが候補
    // t = 3なら一字違いでないものが候補
    set<int> cand;
    rep(i, 10000) {
        cand.insert(i);
    }
    rep(i, n) {
        if(t[i] == 1) {
            cout << s[i] << endl;
            return 0;
        } else if(t[i] == 2) {
            // TODO 二文字以上異なるものは候補外
            // でもこの時点で候補は36個になるはず。
            // 候補を管理するか、候補じゃないのを管理するか？？
            set<int> temp1;
            set<int> temp2;
            rep(j, 4) {
                string tmp = s[i];
                rep(k, 10) {
                    if(tmp[j] != (k+'0')) {
                        tmp[j] = k+'0';
                        temp1.insert(atoi(tmp.c_str()));
                    }
                }
            }
            set_intersection(all(cand), all(temp1), inserter(temp2, temp2.begin()));
            cand = move(temp2);
        } else if(t[i] == 3) {
            rep(j, 4) {
                string tmp = s[i];
                rep(k, 10) {
                    tmp[j] = k+'0';
                    cand.erase(atoi(tmp.c_str()));
                }
            }
        }
    }
    if(cand.size() != 1) {
        cout << "Can't Solve" << endl;
    } else {
        cout << setfill('0') << setw(4) << *cand.begin() << endl;
    }
}
