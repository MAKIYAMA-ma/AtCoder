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

using sl = set<ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;
using vs = vector<string>;
using vsl = vector<sl>;

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
#define Def2(m, n) ll m, n; cin >> m >> n;
#define Def3(l, m, n) ll l, m, n; cin >> l >> m >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define Def3A(a, b, c, n) vl a(n); vl b(n); vl c(n); rep(i, n) cin >> a[i] >> b[i] >> c[i];
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

    Def(t);
    rep(i, t) {
      Def(n);
      string s;
      cin >> s;
      // t <= 20000
      // n <= 2*10^5
      // nの総和は2*10^5以下
      // sの中で,1の出現する区間を一か所にする必要がある
      // 1111100101111
      // この場合、全部1にするのが最短
      // でも一個ずつチェックすると真ん中の1を消してしまう
      //
      // 1100000000001010101
      // この場合、最大の集合である11を消したほうが速い
      // 最大を残すべきとは限らない
      //
      // 各位置まで、1区間なしとする場合の変換数、
      // 1区間ありとする場合の変換数
      // かつ、直前が1or0
      vl ar;
      ll id{0};
      ll cnt{0};
      while(id < s.length() && s[id] == '0') id++;
      while(id < s.length()) {
        cnt = 0;
        while(id < s.length() && s[id] == '1') {
          cnt++;
          id++;
        }
        if(cnt) ar.push_back(cnt);
        cnt = 0;
        while(id < s.length() && s[id] == '0') {
          cnt++;
          id++;
        }
        if(cnt) ar.push_back(cnt);
      }
      /* cout << "--------" << endl; */
      /* rep(i, ar.size()) cout << ar[i] << " "; */
      /* cout << endl; */
      /* cout << "--------" << endl; */

      vector<vl2> dp(ar.size()+1, vl2(2, vl(2, 0)));
      dp[0][0][0] = 0;
      dp[0][0][1] = MAXLL;
      dp[0][1][0] = MAXLL;
      dp[0][1][1] = MAXLL;
      rep(i, ar.size()) {
        if(i%2 == 0) {
          // 1区間
          dp[i+1][0][0] = dp[i][0][0]+ar[i]; // 直前が0かつ1区間梨
          dp[i+1][0][1] = dp[i][0][1]+ar[i]; // 直前が0かつ1区間あり
          dp[i+1][1][0] = MAXLL; // 直前が1かつ1区間梨
          dp[i+1][1][1] = min(dp[i][1][1], dp[i][0][0]); // 直前が1かつ1区間あり
        } else {
          // 0区間
          dp[i+1][0][0] = dp[i][0][0]; // 直前が0かつ1区間梨
          dp[i+1][0][1] = min(dp[i][0][1], dp[i][1][1]); // 直前が0かつ1区間あり
          dp[i+1][1][0] = MAXLL; // 直前が1かつ1区間梨
          dp[i+1][1][1] = min(dp[i][1][1], dp[i][0][0])+ar[i]; // 直前が1かつ1区間あり
        }
      }
      ll ans{MAXLL};
      rep(i, 2) {
        rep(j, 2) {
          ans = min(ans, dp[ar.size()][i][j]);
        }
      }
      /* cout << "===========" << endl; */
      /* rep(i, dp.size()) { */
      /*   rep(j, 2) rep(k, 2) cout << dp[i][j][k] << " "; */
      /*   cout << endl; */
      /* } */
      /* cout << endl; */
      /* cout << "===========" << endl; */
      cout << ans << endl;
    }
}
