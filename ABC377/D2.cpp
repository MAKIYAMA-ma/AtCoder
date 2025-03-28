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

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;

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

    int n, m;
    cin >> n >> m;
    vpi lro(n);
    rep(i, n) {
        int tl, tr;
        cin >> tl >> tr;
        tl--;
        tr--;
        lro[i].first = tl;
        lro[i].second = tr;
    }
    sort(all(lro), [](const pi &a, const pi &b) {
            if(a.second == b.second) {
            return a.first > b.first;
            } else {
            return a.second < b.second;
            }
            });
    vi l, r;
    int bl{-1}, br{-1};
    rep(i, n) {
        if(lro[i].second > br && lro[i].first > bl) {
            l.push_back(lro[i].first);
            r.push_back(lro[i].second);
            bl = lro[i].first;
            br = lro[i].second;
        }
    }
    /* cout << "----------" << endl; */
    /* rep(i, n) { */
    /*     cout << lro[i].first << "," << lro[i].second << endl; */
    /* } */
    /* cout << "----------" << endl; */
    /* cout << "----------" << endl; */
    /* rep(i, l.size()) { */
    /*     cout << l[i] << "," << r[i] << endl; */
    /* } */
    /* cout << "----------" << endl; */
    int lv{0};
    ll ans = 0;
    rep(i, m) {
        auto ind = lower_bound(all(r), i) - r.begin();
        if(ind < l.size() && r[ind] == i && lv <= l[ind]) {
            lv = l[ind]+1;
        }
        ans += (i-lv+1);
        /* cout << "DB:" << lv << " " << i << " " << ans << endl; */
    }
    cout << ans << endl;
}
