#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 0
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
    DefA(a, n);

    // aの長さkの部分列で、等差数列であるものの個数を求める
    // 1 <= k <= nについてそれぞれ求める
    // 1 ≤ N ≤ 80
    // 1 ≤ Ai ≤ 10^9
    // nは少なめ。
    // とはいえ80個ではビット全探索は話にならない
    //
    // 当然k == 1の時はnだし、
    // k == 2の時はn*(n-1)なわけだが
    //
    // 末尾と差を覚えておいて、一個ずつ増やしていくDP的なことできる？
    // 末尾の位置はキーになりうる
    // 等差の値をキーにするのは無理
    // -> とりうる範囲が広いだけで実際のパターン数はn(n-1)/2なんだから、mapで持てばOK
    vector<map<ll, mint>> dpc(n, map<ll, mint>()), dpp(n, map<ll, mint>());
    rep(i, n) {
        mint ans = 0;
        if(i == 0) {
            cout << n << " ";
        } else if(i == 1) {
            rep(j, n-1) {
                srep(k, j+1, n) {
                    dpc[k][a[k] - a[j]]++;
                    ans++;
                }
            }
            cout << ans.val() << " ";
        } else {
            swap(dpc, dpp);
            for(auto& mp : dpc) {
                mp.clear();
            }
            rep(j, n-1) {
                for(auto &m : dpp[j]) {
                    auto dif = m.first;
                    auto cnt = m.second;
                    srep(k, j+1, n) {
                        if(a[k] == (a[j] + dif)) {
                            dpc[k][dif] += cnt;
                            ans += cnt;
                        }
                    }
                }
            }
            cout << ans.val() << " ";
        }
    }
    cout << endl;
}
