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

mint Pow(ll x, ll n) {
    mint ans = 1;
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
    vl a(n, 0);
    rep(i, n) {
        cin >> a[i];
        a[i] += ((i > 0) ? a[i-1] : 0);
    }

    // 各部分列の総和がKにならない分割方法の個数をカウントする
    // とりあえず累積和やSegmentTree？
    // 値の変更は不要だから累積和でOKなはず
    // O(N)で累積した後、O(1)で各部分列の総和は元まる。
    // あとはどう探索するか？
    // 総数は計算できるのだから、Kとなる部分列があるパターンを計算するのが良いだろう。
    // 尺取り的な感じで和がKとなる部分列を見つける(O(N))
    // そのうえで、他の部分は何でも良しでパターン数は計算できる。
    //
    // ただ、複数個所がKになるパターンが重複してしまう。
    // 先に出てきたエリアはKにならないように計算する、とか可能か？
#if 1
    vector<mint> dp(n+1, 0);
    dp[0] = 1;

#if 1
    map<ll, mint> dpsm;
    dpsm[0] = dp[0];
    mint all = dp[0];
    srep(i, 1, n+1) {
        dp[i] = all - dpsm[a[i-1] - k];
        dpsm[a[i-1]] += dp[i];
        all += dp[i];
    }
#else
    // TODO このままだとO(N2)となる。高速化できないとTLE。
    rep(i, n+1) {
        rep(j, i) {
            ll val = ((i > 0) ? a[i-1] : 0) - ((j > 0) ? a[j-1] : 0);
            if(val != k) {
                dp[i] += dp[j];
            }
        }
    }
#endif
    /* cout << "------" << endl; */
    /* rep(i, n+1) { */
    /*     cout << dp[i].val() << endl; */
    /* } */
    /* cout << "------" << endl; */
    cout << dp[n].val() << endl;
#else
    ll l{-1}, r{0};
    vpl ex;
    ll exsum{0};
    mint ans{0};
    while(r < n) {
        while(a[r] - ((l >= 0 ) ? a[l] : 0) < k) {
            r++;
        }

        cout << "DB:" << l << " " << r << ":" << a[r] - ((l >= 0) ? a[l] : 0) << endl;
        if(a[r] - ((l >= 0) ? a[l] : 0) == k) {
            int ptn = (r-l+1);
            if(l == -1) ptn--;
            if(r == n-1) ptn--;
            mint num = Pow(2, n - 1 - ptn - exsum + ((ex.size() > 0 && ex[ex.size()-1].second == l) ? 1 : 0));
            /* cout << "    " << n - 1 - ptn - exsum + ((ex[ex.size()-1].second == l) ? 1 : 0) << endl; */
            rep(i, ex.size()) {
                num *= (Pow(2, ex[i].second - ex[i].first + ((ex[i].second != l) ? 1 : 0)) - 1);
            }
            ans += num;
            cout << "    " << num.val() << endl;
            ex.push_back(make_pair(l, r));
            exsum += (ptn);
        }

        l++;
    }
    ans = Pow(2, n-1) - ans;
    cout << ans.val() << endl;
#endif
}
