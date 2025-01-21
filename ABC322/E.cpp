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

ll Pow(ll x, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n % 2) {
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(k);
    Def(p);
    vl c(n, 0);
    vl2 a(n, vl(k, 0));
    rep(i, n) {
        cin >> c[i];
        rep(j, k) cin >> a[i][j];
    }

    // n <= 100
    // p <= 5
    // k <= 5
    // 100bit全探索は当然無理
    //
    // 二分探索は？　-> x円以下でクリア可能かどうか簡単に判定できるか？
    // 最小コスト流？
    // DP
    // 100*(5^5) = 312500 普通に間に合うのでは
    ll st{0};
    rep(i, k) {
        st *= (p+1);
        st += p;
    }

    vl cost(st+1, MAXLL);
    vl costp(st+1, MAXLL);
    cost[0] = 0;
    rep(i, n) {
        rep(j, st) {
            costp[j] = cost[j];
        }
        rep(j, st) {
            if(costp[j] >= MAXLL) continue;

            ll nxt{0}, bs{1};
            ll tmp = j;
            rep(l, k) {
                ll pt = min(tmp%(p+1) + a[i][l], p);
                /* cout << pt << " "; */
                nxt += pt*bs;
                bs *= (p+1);
                tmp /= (p+1);
            }
            cost[nxt] = min(costp[j]+c[i], cost[nxt]);
            /* cout << endl << "DB:" << j << " " << nxt << " " << cost[nxt] << endl; */
        }
    }
    /* rep(i, st+1) cout << i << " " << cost[i] << endl; */
    if(cost[st] == MAXLL) cost[st] = -1;
    cout << cost[st] << endl;
}
