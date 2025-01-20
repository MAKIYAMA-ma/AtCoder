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
    Def(m);
    DefA(p, n);

#if 1
    // いくらまでの商品を全部買って大丈夫か探索
    ll l{0}, r{m+1};
    while(r-l > 1) {
        ll mid = (l+r)/2;
        ull t{0};
        rep(i, n) {
            ull nm = (mid/p[i]+1)/2;
            /* cout << "D1:" << " " << nm << " " << (nm*nm) << " " << p[i] << endl; */
            if(nm > (sqrt((m-t)/p[i])+1)) {
                t = MAXLL+1;
                break;
            }
            t += (nm*nm*p[i]);
            /* cout << "D2:" << t << endl; */
            if(t > m) {
                t = MAXLL+1;
                break;
            }
        }
        /* cout << "DB2:" << mid << " " << t << endl; */
        if(t <= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    /* cout << "DB1:" << l << endl; */

    ull t{0};
    ull ans{0};
    priority_queue<ull, vector<ull>, greater<ull>> pq;

    // 探索結果の金額まで全購入の場合、各商品幾つになるかカウント
    rep(i, n) {
        ull nm = (l/p[i]+1)/2;
        t += (nm*nm*p[i]);
        ans += nm;
        pq.push((2*nm+1)*p[i]);
        /* cout << nm << " "; */
    }
    /* cout << endl; */
    /* cout << "DB:" << ans << " " << t << endl; */

    // 各商品の次の一個を、安い順に買えるだけ買う
    while(!pq.empty()) {
        auto tp = pq.top();
        pq.pop();
        /* cout << m << " " << t << " " << tp << endl; */
        if(tp <= (m-t)) {
            ans++;
            t += tp;
        } else {
            break;
        }
    }
    cout << ans << endl;
#else
    priority_queue<pair<ll, pl>, vector<pair<ll, pl>>, greater<pair<ll, pl>>> pq;
    rep(i, n) {
        pq.push(make_pair(p[i], make_pair(1, i)));
    }
    ll mn{0};
    ll ans{0};
    map<ll, ll> mp;
    while(mn <= m) {
        auto t = pq.top();
        pq.pop();
        if(mn + t.first > m) break;
        /* cout << "DB:" << t.first << endl; */
        ans++;
        mn += t.first;
        auto c = t.second.first;
        auto n = t.second.second;
        mp[n]++;
        pq.push(make_pair(((c+1)*(c+1)-c*c)*p[n], make_pair(c+1, n)));
    }
    rep(i, n) cout << "(" << mp[i] << "," << (mp[i]*mp[i]*p[i]) << ") ";
    cout << endl;
    cout<< ans << endl;
#endif
}
