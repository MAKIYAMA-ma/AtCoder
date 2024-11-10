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
    string s;
    cin >> s;

    // TODO 文字列として処理できるようにしないと無理
#if 1
    vl nums(n, 0);
    vl ans(10*n, 0);
    // 0からn-iまでの区間に同じ値を加えたいので、後で累積を計算する形でO(N)で計算できる
    rep(i, n) {
        int v = (s[i]-'0')*(i+1);
        nums[0] += v;
        if(i > 0) {
            nums[n-i] -= v;
        }
    }
    srep(i, 1, n) {
        nums[i] += nums[i-1];
    }

    ll up{0};
    rep(i, n) {
        ans[i] = (nums[i] + up) % 10;
        up = (nums[i] + up) / 10;
    }
    int pos = n;
    while(up > 0) {
        int nv = (ans[pos] + up);
        /* cout << "DB2:" << nv << endl; */
        ans[pos] = nv % 10;
        up = nv / 10;
        pos++;
    }
    for(int i = pos-1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
#elif 1
    vl nums(n, 0);
    vl ans(10*n, 0);
    // TODO これだとO(N2)になってしまう
    rep(i, n) {
        int v = (s[i]-'0')*(i+1);
        rep(j, n-i) {
            nums[j] += v;
        }
    }

    int up{0};
    rep(i, n) {
        ans[i] = (nums[i] + up) % 10;
        up = (nums[i] + up) / 10;
    }
    int pos = n;
    while(up > 0) {
        int nv = (ans[pos] + up);
        /* cout << "DB2:" << nv << endl; */
        ans[pos] = nv % 10;
        up = nv / 10;
        pos++;
    }
    for(int i = pos-1; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
#else
    vl ans(10*n, 0);
    int maxpos = n-1;
    rep(i, n) {
        int v = s[i]-'0';
        int up{0};

        rep(j, n-i) {
            int nv = (ans[j] + up + v*(i+1));
            /* cout << "DB2:" << nv << endl; */
            ans[j] = nv % 10;
            up = nv / 10;
        }
        int pos = n-i;
        while(up > 0) {
            int nv = (ans[pos] + up);
            /* cout << "DB2:" << nv << endl; */
            ans[pos] = nv % 10;
            up = nv / 10;
            maxpos = max(maxpos, pos);
            pos++;
        }

        /* cout << "DB:"; */
        /* for(int i = maxpos; i >= 0; i--) { */
        /*     cout << ans[i]; */
        /* } */
        /* cout << endl; */
    }
    for(int i = maxpos; i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
#endif
}
