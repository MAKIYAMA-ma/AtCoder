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
#define Def(n) ll n; cin >> n;

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

    vpl ca(n);
    vector<pair<pl, int>> ma(n);
    set<int> use;
    rep(i, n) {
        cin >> ca[i].second >> ca[i].first;
        ma[i].first.first = ca[i].first;
        ma[i].first.second = ca[i].second;
        ma[i].second = i;
    }

    // 一旦コスト順にソートし、各コストまでの最大のAを算出する
    sort(all(ma));
    rep(i, n-1) {
        ma[i+1].first.second = max(ma[i].first.second, ma[i+1].first.second);
    }
    // その後改めてIndex順に並べなおす
    sort(all(ma), [](const pair<pl, int> &a, const pair<pl, int> &b) {
            return a.second < b.second;
            });
    // 各カードについて、そのカードのAがそのコストまでの最大のAであれば採用される
    rep(i, n) {
        /* cout << i << ":" << ca[i].first << ", " << ca[i].second << "  --->  " << ma[i].first.first << ", " << ma[i].first.second << endl; */
        if(ca[i].second == ma[i].first.second) {
            use.insert(i+1);
        }
    }
    cout << use.size() << endl;
    for(auto u : use) {
        cout << u << " ";
    }
    cout << endl;
}
