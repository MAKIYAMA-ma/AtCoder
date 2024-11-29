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
#define Def2A(a, b, n) vl a(n); rep(i, n) cin >> a[i] >> b[i];
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

// モジュラ逆元を求める関数（拡張ユークリッド法）
ll modular_inverse(ll a, ll k) {
    ll b = k, u = 1, v = 0;
    while (b > 0) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    return (u % k + k) % k;
}

ll rev_mod(ll a, ll base, ll md) {
    return (md * modular_inverse(a, base)) % base;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 積 mod BASE = p
    // である組み合わせ数を求める
    //
    // とりあえず元の数はmod BASE部分だけで良い
    // しかし、
    // N <= 100000
    // なので真面目にN^2パターンの積を確認するわけにはいかない
    // 各Aについて、条件を満たす相方の条件を設定して、それを二分探索とかで探せないか？

    ll BASE = 1000000007;
    Def(n);
    Def(p);
    map<ll, ll> al;
    rep(i, n) {
        Def(tmp);
        al[tmp%BASE]++;
    }

    ll ans{0};
    vb fin(BASE, false);
    for(auto &[a, cnt] : al) {
        if(fin[a]) continue;

        ll b = rev_mod(a, BASE, p);
        if(a == b) {
            ans += ((cnt)*(cnt-1)/2);
        } else {
            ans += cnt*al[b];
        }
        fin[a] = true;
        fin[b] = true;
    }
    cout << ans << endl;
}
