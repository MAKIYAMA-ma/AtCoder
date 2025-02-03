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
    DefA(a, n);
    // n <= 3+10^5
    // ai <= n
    // ai == ak かつ ai != aj である i < j < kの組合せ数
    // 当然O(n^3)で全探索はありえない

#if 1
    map<ll, vl> mp;
    rep(i, n) {
        mp[a[i]].push_back(i);
    }

    ll ans{0};
    for(auto [v, lst] : mp) {
        ll sm = lst[0];
        ll av{0};
        srep(i, 1, lst.size()) {
            /* cout << "DB:" << v << ":" << lst[i]*i - sm - 1 -av << endl; */
            /* cout << "   " << lst[i]*i << " " << sm << " " << av << endl; */
            av += i;
            ans += lst[i]*i - sm - av;
            sm += lst[i];
        }
    }
    cout << ans << endl;
#else
    // 後からi番目までにjが幾つあるかをカウントする
    // -> n^2の領域が必要だからMLEになる
    // mapを使えば収まるのでは。
    vector<map<ll, ll>> mp(n);
    set<ll> tgt;
    mp[n-1][a[n-1]]++;
    tgt.insert(a[n-1]);
    rrep(i, n-1) {
        mp[i] = mp[i+1];
        /* for(auto v : tgt) { */
        /*     mp[i][v] = mp[i+1][v]; */
        /* } */
        tgt.insert(a[i]);
        mp[i][a[i]]++;
    }

    ll ans{0};
#if 0
    // あれ？これだと結局O(n^2)だ。。。
    rep(i, n-2) {
        srep(j, i+1, n-1) {
            if(a[i] != a[j]) ans += mp[j+1][a[i]];
        }
    }
    cout << ans << endl;
#else
    // これでもワーストケースではO(n^2)な感じになるよな。。。
    vector<map<ll, ll>> ac(n);
    rrep(i, n-1) {
        for(auto [v, c] : mp[i+1]) {
            ac[i][v] = ac[i+1][v] + ((a[i] != v)?c:0);
        }
    }
    rep(i, n-2) {
        ans += ac[i+1][a[i]];
    }
    cout << ans << endl;
#endif
#endif
}
