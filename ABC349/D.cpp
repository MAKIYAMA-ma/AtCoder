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

/**
 * @brief 累乗
 *
 * @param x
 * @param n
 *
 * @return 
 */
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

void check(ll l, ll r, set<ll> &div) {
    ll tmp = r-l;
    ll mx{0};
    ll le, re;

    if(l==r) return;

    // [l, r) の幅は2^mx以上2^(mx+1)未満
    // -> [l, r)の範囲、に、2^mxの定数倍が1つor2つ入っているはず
    while(tmp/2) {
        mx++;
        tmp /= 2;
    }

    ll bdr = Pow(2, mx);
    if(r/bdr - (l+bdr-1)/bdr == 1) {
        // [l, r)の範囲、に、2^mxの定数倍が2つ入っている
        // -> その範囲はまとめて1ブロックにする
        le = bdr * ((l+bdr-1)/bdr);
        re = le + bdr;
        div.insert(le);
        div.insert(re);
    } else {
        // [l, r)の範囲、に、2^mxの定数倍が1つしかない
        // 2^(mx-1)の定数倍刻みで、ブロックをとれるだけとる
        bdr /= 2;

        le = bdr * ((l+bdr-1)/bdr);
        tmp = le;
        while(tmp < (bdr*(r/bdr))) {
            div.insert(tmp);
            re = tmp;
            tmp += bdr;
        }
    }
    // 左右の余ったブロックについて、再帰的に処理
    check(l, le, div);
    check(re, r, div);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(l);
    Def(r);

    // l - rの範囲で2^i*jが2個以上含まれる最大のiを見つける
    // 見つけた区切りの前と後について同様の事を繰り返す
    // 見つけた区切り位置をsetで管理、再帰
    // 2^i <= abs(r-l) < 2^(i+1)であれば、候補はiまたはi-1なはず
    set<ll> div;
    check(l, r, div);

    cout << div.size()-1 << endl;
    ll st = *(div.begin());
    div.erase(div.begin());
    for(auto d : div) {
        cout << st << " " << d << endl;
        st = d;
    }
}
