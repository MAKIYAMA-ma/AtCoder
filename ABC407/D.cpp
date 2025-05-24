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

  Def2(h, w);
  vl2 a(h, vl(w));
  rep(i, h) rep(j, w) cin >> a[i][j];

  // hw <= 20
  // a < 2^60
  // 60bitについて、なるべく上位のビットを0にできるようにしたい
  // 2^20 = 10^6程度。全パターン試せるか

  ll ans{0};
  ll total = h*w;
  for(ll bit = 0; bit < (1LL << total); bit++) {
    vl2 grid(h, vl(w));
    ll cnt{0};
    rep(i, total) {
      ll r = i/w;
      ll c = i%w;
      grid[r][c] = (bit >> i) & 1;
      cnt += grid[r][c];
    }

    // 可能か？
    if(cnt % 2) continue;
#if 1
    mf_graph<ll> grp(h * w + 2);
    int sp = h*w;
    int gp = h*w+1;
    vi dh = {1, -1, 0, 0};
    vi dw = {0, 0, 1, -1};
    ll score{0};
    rep(i, h) {
      rep(j, w) {
        if(!grid[i][j]) {
          score ^= a[i][j];
          continue;
        }
        if((i+j)%2) {
          grp.add_edge(sp, i*w + j, 1);
          rep(k, 4) {
            auto nh = i+dh[k];
            auto nw = j+dw[k];
            if((nh >= 0) && (nh < h) && (nw >= 0) && (nw < w) && grid[nh][nw] == 1) {
              grp.add_edge(i*w + j, nh*w + nw, 1);
            }
          }
        } else {
          grp.add_edge(i*w + j, gp, 1);
        }
      }
    }
    if(grp.flow(sp, gp) == cnt/2) ans = max(ans, score);
#else
    bool ok{true};
    ll score{0};
    rep(i, h) {
      rep(j, w) {
        if(!grid[i][j]) {
          score ^= a[i][j];
          continue;
        }
        if(grid[i][j] == 2) {
          continue;
        }
        bool ok2{false};
        if(j < w-1 && grid[i][j+1]==1) {
          grid[i][j+1] = 2;
          ok2 = true;
        } else if(i < h-1 && grid[i+1][j]==1) {
          grid[i+1][j] = 2;
          ok2 = true;
        }
        if(!ok2) {
          ok = false;
          break;
        }
      }
      if(!ok) {
        break;
      }
    }
    if(ok) {
      ans = max(ans, score);
      continue;
    }

    ok = true;
    score = 0;
    rep(i, h) {
      rep(j, w) {
        if(grid[i][j]) grid[i][j] = 1;
      }
    }
    rep(i, h) {
      rep(j, w) {
        if(!grid[i][j]) {
          score ^= a[i][j];
          continue;
        }
        if(grid[i][j] == 2) {
          continue;
        }
        bool ok2{false};
        if(i < h-1 && grid[i+1][j]==1) {
          grid[i+1][j] = 2;
          ok2 = true;
        } else if(j < w-1 && grid[i][j+1]==1) {
          grid[i][j+1] = 2;
          ok2 = true;
        }
        if(!ok2) {
          ok = false;
          break;
        }
      }
      if(!ok) {
        break;
      }
    }
    if(ok) {
      ans = max(ans, score);
    }
#endif
  }
  cout << ans << endl;
}
