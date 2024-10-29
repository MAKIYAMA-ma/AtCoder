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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;

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

    int n, m, k;
    cin >> n >> m >> k;

    vb res(m, false);
    vi tst(m, 0);
    rep(i, m) {
        int c;
        cin >> c;
        rep(j, c) {
            int a;
            cin >> a;
            tst[i] |= (1 << (a-1));
        }

        char r;
        cin >> r;
        if(r == 'o') res[i] = true;
    }

    // OK -> 入れた鍵のうちK本以上が本物
    // NG -> 入れた鍵のうちK本未満が本物
    // N,M <= 15なので、
    // O(M * 2^N)でも491520程度で余裕で回るので全探索
    ll ans = 0;
    rep(i, 1 << n) {
        // テスト結果が×ばかりなら、そもそも本物のカギがK本に足りなくても矛盾しない。
        /* if(__builtin_popcount(i) < k) { */
        /*     continue; */
        /* } */
        bool suc = true;
        rep(j, m) {
            int hit = (i & tst[j]);
            if(res[j]) {
                if(__builtin_popcount(hit) < k) {
                    suc = false;
                    break;
                }
            } else {
                if(__builtin_popcount(hit) >= k) {
                    suc = false;
                    break;
                }
            }
        }
        if(suc) {
            ans++;
        }
    }
    cout << ans << endl;
}
