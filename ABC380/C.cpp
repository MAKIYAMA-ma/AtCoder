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
    Def(k);
    string s;
    cin >> s;

    vl zero, one;
    vl2 val(2, vl());
    int pre{-1};
    rep(i, n) {
        int num = s[i]-'0';
        if(pre != num) {
            pre = num;
            val[num].push_back(0);
        }
        val[num][val[num].size() - 1]++;
    }
    /* cout << "-------" << endl; */
    /* rep(i, val[0].size()) { */
    /*     cout << val[0][i] << " "; */
    /* } */
    /* cout << endl; */
    /* rep(i, val[1].size()) { */
    /*     cout << val[1][i] << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "-------" << endl; */
    val[1][k-2] += val[1][k-1];
    val[1][k-1] = 0;
    val[0].push_back(0);
    if(s[0] == '0') {
        val[0][k] += val[0][k-1];
        val[0][k-1] = 0;
    } else {
        val[0][k-1] += val[0][k-2];
        val[0][k-2] = 0;
    }
    /* cout << "-------" << endl; */
    /* rep(i, val[0].size()) { */
    /*     cout << val[0][i] << " "; */
    /* } */
    /* cout << endl; */
    /* rep(i, val[1].size()) { */
    /*     cout << val[1][i] << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "-------" << endl; */
    rep(i, max(val[0].size(), val[1].size())) {
        if(s[0] == '0') {
            if(i < (val[0].size())) {
                rep(j, val[0][i]) {
                    cout << 0;
                }
            }
            if(i < (val[1].size())) {
                rep(j, val[1][i]) {
                    cout << 1;
                }
            }
        } else {
            if(i < (val[1].size())) {
                rep(j, val[1][i]) {
                    cout << 1;
                }
            }
            if(i < (val[0].size())) {
                rep(j, val[0][i]) {
                    cout << 0;
                }
            }
        }
    }
    cout << endl;
}
