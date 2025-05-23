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

// pkまでの最長パスをメモ化再帰でDP
ll check(vsl &edge, ll pk, vl &ans) {
    if(ans[pk] >= 0) return ans[pk];

    ll ret = -1;
    for(auto t : edge[pk]) {
        ret = max(ret, check(edge, t, ans));
    }
    ans[pk] = ret + 1;
    return ans[pk];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def3(h, w, n);
    Def3A(r, c, l, n);

    set<pair<ll, pl>> st, fn;
    // O(n*2logn)
    rep(i, n) {
        st.insert({c[i], {r[i], i}});
        fn.insert({c[i]+l[i], {r[i], i}});
    }

    vsl cld(n, sl());
    set<pl, greater<pl>> odr;
    vb bs(n, true);
    // O(2*n*3logn+nlogn)
    while(st.size() || fn.size()) {
        set<pl> add;
        ll nxt = min((st.size()?(st.begin()->first):MAXLL), (fn.size()?(fn.begin()->first):MAXLL));
        while(st.size() && st.begin()->first == nxt) {
            odr.insert({st.begin()->second.first, st.begin()->second.second});
            add.insert({st.begin()->second.first, st.begin()->second.second});
            st.erase(st.begin());
        }
        while(fn.size() && fn.begin()->first == nxt) {
            odr.erase({fn.begin()->second.first, fn.begin()->second.second});
            fn.erase(fn.begin());
        }
        for(auto a : add) {
            auto it = odr.find(a);
            if(it != odr.begin()) {
                it--;
                auto prt = it;
                it++;
                // 今回は各ブロックまでの最長パスを求めたいので、
                // 上にあるブロックから下にあるブロックに向けて辺を記録する
                cld[it->second].insert(prt->second);
                bs[prt->second] = false;
            }
            auto prt = it;
            it++;
            if(it != odr.end()) {
                cld[it->second].insert(prt->second);
                bs[prt->second] = false;
            }
        }
    }

    vl ans(n, -1);
    rep(i, n) {
        check(cld, i, ans);
    }
    rep(i, n) cout << h-ans[i] << endl;
}
