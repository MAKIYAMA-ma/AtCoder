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
    Def(q);
    DefA(a, n);
    // n, q <= 2*10^5
    //
    // mexの管理方法は？
    // (1) 新旧共にmexより大きい値 -> mexに影響しない
    // (2) 新旧共にmexより小さい値 ->
    //      - 旧がmex候補（他にAに含まれなければ）
    //      - 旧がmexにならないなら変化ない
    // (3) 新がmexと一致、旧がmexより大きい -> mexが大きくなる。探す必要がある。
    // (4) 新がmexと一致、旧がmexより小さい ->
    //      - 旧がmex候補（他にAに含まれなければ）
    //      - それがダメならmexが大きくなる。探す必要がある。
    //
    // 候補なしでmexを探索するのを高速にできるか？
    // 含まれていない方を管理できるか？
    //
    // -> ややこしい場合分けせずに、含まれていない数値の管理でいく。
    // ai <= 10^9だが、n <= 2*10^5.
    // mexは絶対にn以下だから、ここまでの範囲だけ管理できていればOK
    // - 各indexの現在の値
    // - 各値が幾つ残っているか
    // - Aに含まれない値
    // を管理すればいけるのでは
    map<ll, ll> mp;
    set<ll> me;
    rep(i, n+1) me.insert(i);
    rep(i, n) {
        mp[a[i]]++;
        me.erase(a[i]);
    }

    rep(i, q) {
        Def(id);
        Def(x);
        id--;
        mp[a[id]]--;
        mp[x]++;

        me.erase(x);
        if(mp[a[id]] == 0) {
            if(a[id] <= n) me.insert(a[id]);
            mp.erase(a[id]);
        }
        a[id] = x;

        cout << *me.begin() << endl;
    }
}
