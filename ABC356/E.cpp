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

    // 各i < j の組(i,j)について、AiとAjの大きいほうを小さいほうで割った値（整数）の合計が計算したい
    // 2 ≤ N ≤ 2×10^5
    // 1 ≤ Ai ≤ 10^6
    //
#if 1
    vl c(1000001, 0);
    ll ma{0};
    rep(i, n) {
        Def(a);
        c[a]++;
        ma = max(ma, a);
    }

    vl ca(c.size(), 0);
    ca[0] = c[0];
    srep(i, 1, c.size()) {
        ca[i] = ca[i-1] + c[i];
    }

    ll ans{0};
    srep(i, 1, c.size()) {
        if(c[i] > 0) {
            // 1になるケースは、自分自身を除く
            ans += c[i] * (ca[min(i*2, (ll)ca.size())-1] - ca[i]);
            ans += (c[i]*(c[i]-1)/2);
            srep(j, 2, ma/i + 1) {
                ans += c[i] * (ca[min(i*(j+1), (ll)ca.size())-1] - ca[min(i*j, (ll)ca.size())-1]) * j;
            }
        }
    }
    cout << ans << endl;
#else
    DefA(a, n);
    // 結局のところ、全ての(i,j)で大きいほうを小さいほうで割った値の総和、ということになる
    // しかし、端数切捨てが発生するから、単純に自分より大きいモノの総和をAiで割る、とかでは誤差が発生する
    // Aiの範囲に従いmodを管理するとかも無理がある（それだけでTLEする）
    // (1) aをソートして(O(logN))、大きいほうから累積を出す(O(N))
    // (2) 各aiについて、自分より大きいものの合計を取得(O(logN))し、aiで割る
    // (3) TODO 切り捨てのはずの値を算出したいどうやる？
    //      各Aiについて、自分より大きいAについての、mod Aiの合計値が知りたいが、まじめにやるとO(N^2)でTLE
#endif
}
