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

ll check(vector<set<ll>> &grp, ll ind, ll n, ll t, vl2 &en) {
    if (grp.size() > t) return 0;
    if(ind == n) {
        if(grp.size() != t) {
            return 0;
        } else {
            for(auto &g : grp) {
                for(auto p : g) {
                    for(auto e : en[p]) {
                        if(g.find(e) != g.end()) {
                            return 0;
                        }
                    }
                }
            }
            /* cout << "--------" << endl; */
            /* for(auto g : grp) { */
            /*     cout << "("; */
            /*     for(auto p : g) { */
            /*         cout << p << ","; */
            /*     } */
            /*     cout << ")"; */
            /* } */
            /* cout << endl; */
            /* cout << "--------" << endl; */
            return 1;
        }
    }

    ll ans{0};

    // 既存のチームに追加
    rep(i, grp.size()) {
        grp[i].insert(ind);
        ans += check(grp, ind+1, n, t, en);
        grp[i].erase(ind);
    }

    // 新チーム作成
    set<ll> ns;
    ns.insert(ind);
    grp.push_back(ns);
    ans += check(grp, ind+1, n, t, en);
    grp.pop_back();

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(t);
    Def(m);
    Def2A(a, b, m);
    vl2 en(n, vl());
    rep(i, m) {
        en[a[i]-1].push_back(b[i]-1);
        en[b[i]-1].push_back(a[i]-1);
    }
    // チームごとの区別とかはない
    // 空チームはNG
    // 1≤T≤N≤10 かなり少ない制約
    // 全探索してOKか否かチェックする感じが可能か？

    vector<set<ll>> grp;
    cout << check(grp, 0, n, t, en) << endl;
}
