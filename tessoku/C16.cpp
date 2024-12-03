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
#define Def2A(a, b, n) vl a(n); rep(i, n) cin >> a[i] >> b[i];
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
    Def(k);

#if 1
    vpl sp(m), dp(m);
    vpl2 air(n, vpl());
    vpl order(2*m);
    rep(i, m) {
        Def(a);
        Def(s);
        Def(b);
        Def(t);
        a--; b--;
        sp[i].first = s;
        sp[i].second = a;
        dp[i].first = t + k;
        dp[i].second = b;
        // 同時刻なら到着が先に処理されるように、~mが到着、~2mが出発として番号を割り振る
        air[a].push_back(make_pair(s, i+m));
        air[b].push_back(make_pair(t+k, i));

        order.push_back(make_pair(s, i+m));
        order.push_back(make_pair(t+k, i));
    }
    rep(i, n) {
        sort(all(air[i]));
    }
    sort(all(order));

    vpl2 line(2*m + 2, vpl());
    // 飛行機に乗る経路
    rep(i, m) {
        line[i+m].push_back(make_pair(i, 1));
    }
    // 空港で待機する経路
    for(auto a : air) {
        rep(i, a.size()-1) {
            line[a[i].second].push_back(make_pair(a[i+1].second, 0));
        }
    }
    vl ans(2*m);
    for(auto &[tm, ind] : order) {
        for(pl l : line[ind]) {
            ans[l.first] = max(ans[l.first], ans[ind] + l.second);
        }
    }
    cout << *max_element(all(ans)) << endl;
#else
    // なるべく多く選択したい区間スケジューリングではあるが、
    // 選ぶものごとに次に選べるものが異なる
    // 区間スケジューリングの延長でいける気はしない。。。
    // DPかな。
    // でも、時間をキーとして持つとTもMもあふれる
    //
    // i本目のフライトまででj空港にいる場合の、
    // 最大フライト数と、到着時間
    // でも、もっと早くつく、回数が少ない経路でも、その後の乗り継ぎでいっぱい乗れる可能性があるのでは
    vpl2 dp(m+1, vpl(n, {0, 0}));
    rep(i, n) {
        dp[0][i] = make_pair(0, -k);
    }
    rep(i, m) {
        auto s = flt[i].first.second;
        auto t = flt[i].first.first;
        auto sa = flt[i].second.first;
        auto ta = flt[i].second.second;

        dp[i+1][t] = 
    }
#endif
}
