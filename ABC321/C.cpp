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

ll Pow(ll x, ll n) {
    ll ans = 1;
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

    Def(k);

    // 1桁:1,2,,,9 :9個
    // 2桁:10,20,21,30,31,32,,,98 : 1+2+3+4+5+6+7+8+9 = 45個
    // 3桁:210,310,320,321,420,421,431,432,,,,987 = 1+(1+2)+(1+2+3)+++(1+++8)
    // 9876543210 が最大
#if 1
    vl cand;
    srep(i, 2, 1<<10) {
        ll nm{0};
        ll tmp = i;
        ll base{1};
        rep(j, 10) {
            if(!tmp) break;
            if(tmp & 0x01) {
                nm += (j*base);
                base *= 10;
            }
            tmp >>= 1;
        }
        cand.push_back(nm);
    }
    sort(all(cand));
    /* rep(i, cand.size()) cout << cand[i] << endl; */
    cout << cand[k-1] << endl;
#else
    vl nm(10*10, 0);
    rep(i, 10) {
        nm[i] = 1;
        nm[10+i] = i;
    }
    srep(i, 2, 10) {
        ll cnt{0};
        srep(j, 1, 10) {
            cnt += nm[10*(i-1)+j-1];
            if(j > 0) {
                nm[10*i+j] = cnt;
            }
        }
    }
    /* rep(i, 10) { */
    /*     rep(j, 10) { */
    /*         cout << nm[10*i+j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    vl an(10*10, 0);
    srep(i, 1, an.size()) {
        an[i] = an[i-1]+nm[i];
    }
    rep(i, 10) {
        rep(j, 10) {
            cout << an[10*i+j] << " ";
        }
        cout << endl;
    }

    ll ans{0};
    if(k) {
        auto lp = lower_bound(all(an), k-1) - an.begin();
        ans += ((lp%10) * Pow(10, lp/10));

        cout << "DB:" << k << " " << lp << " " << an[lp] << ans << endl;
        if(lp != 0) lp--;
        k -= an[lp];
    }
    while(k) {
        auto lp = lower_bound(all(an), k) - an.begin();
        ans += ((lp%10) * Pow(10, lp/10));

        cout << "DB:" << k << " " << lp << " " << an[lp] << " " << ans << endl;
        if(lp != 0) lp--;
        k -= an[lp];
    }
    cout << ans << endl;
#endif
}
