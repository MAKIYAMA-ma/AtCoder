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


void makeptn(vl &elm, set<ll> &ans, vl2 &ptn, ll index) {
    for(auto &st : ptn) {
        ll sum = reduce(all(st));
        /* cout << sum << "("; */
        /* for(auto s: st) { */
        /*     cout << s << ","; */
        /* } */
        /* cout << ") "; */
    }
    /* cout << "::" << index << endl; */
    if (index == elm.size()) {
        ll a{0};
        for(auto &st : ptn) {
            ll sum = reduce(all(st));
            a ^= sum;
            /* cout << sum << "("; */
            /* for(auto s: st) { */
            /*     cout << s << ","; */
            /* } */
            /* cout << ") "; */
        }
        /* cout << "--->" << a << endl; */
        ans.insert(a);
        return;
    }

    rep(i, ptn.size()) {
        ptn[i].push_back(elm[index]);
        makeptn(elm, ans, ptn, index + 1);
        ptn[i].pop_back();
    }

    ptn.push_back({elm[index]});
    makeptn(elm, ans, ptn, index + 1);
    ptn.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    DefA(a, n);
    // n <= 12
    // 足し算だと繰り上がる
    // 繰り上がり方が何種類あるか
    //
    // 12個なら組みわけの方法は4*10^6ちょい
    // 全網羅は可能
    //
    set<ll> ans;
    vl2 ptn;
    makeptn(a, ans, ptn, 0);
    cout << ans.size() << endl;
}
