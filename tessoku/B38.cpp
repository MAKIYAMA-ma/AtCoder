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

ll count(ll n) {
    ll ans = 0;
    ll keta = 0;
    ll tmp = n;
    ll maxn = 0;

    while(tmp > 0) {
        keta++;
        if(tmp < 10) maxn = tmp;
        tmp /= 10;
    }

    ll odr = 1;
    rep(i, keta-2) odr *= 10;

    cout << (keta-1) << endl;
    cout << (maxn) << endl;
    cout << (odr) << endl;
    rep(i, maxn-1) {
        ans += (i + 45*(keta-1)) * odr;
    }
    ans += maxn*(n%odr + 1);
    return ans;
}

int main() {
    int n;
    string s;
    cin >> n >> s;

#if 1
    vi ha(n, 1), hb(n, 1);
    // Aのみを考慮した最低の高さ
    rep(i, n-1) {
        if(s[i] == 'A') {
            ha[i+1] = ha[i]+1;
        }
    }
    // Bのみを考慮した最低の高さ
    rrep(i, n-1) {
        if(s[i] == 'B') {
            hb[i] = hb[i+1]+1;
        }
    }
    ll ans{0};
    rep(i, n) {
        // A基準とB基準で高いほうの「最低の高さ」が実際の最低の高さ
        ans += max(ha[i], hb[i]);
    }
    cout << ans << endl;
#else
    vi h(n, 1);

    // B->Aの境目が1になるように割り当てる
    int start = 0;
    rep(i, n-1) {
        if(s[i] == 'A') {
            if(i > 0 && s[i-1] == 'B') {
                int diff = (1-h[i]);
                // 境界部分は、Aをたどって上ってきた値と、Bを遡ってきた値の大きいほうが最低ライン
                h[start] = max(h[start], h[start]+diff);
                srep(j, start+1, i+1) {
                    /* cout << j << ":" << h[j] << "->"; */
                    h[j] += diff;
                    /* cout << h[j] << endl; */
                }
            }
            h[i+1] = h[i]+1;
        } else {
            h[i+1] = h[i]-1;
            if(i > 0 && s[i-1] == 'A') {
                start = i;
            }
            if(i == n-2) {
                int diff = (1-h[i+1]);
                h[start] = max(h[start], h[start]+diff);
                srep(j, start+1, i+2) {
                    h[j] += diff;
                }
            }
        }
        /* rep(i, n) { */
        /*     cout << h[i] << " "; */
        /* } */
        /* cout << endl; */
    }

    cout << reduce(all(h)) << endl;
#endif
}
