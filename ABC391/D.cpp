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
    Def(w);
    Def2A(x, y, n);
    Def(q);

    // 全ての列の最下段のセルのうち、一番下が落ちきるまで次は消えない
    // 各列のi段目を夫々まとめて管理
    vector<set<pl>> row(w, set<pl>());
    ll mxy{0};
    rep(i, n) {
        mxy = max(mxy, y[i]);
        row[x[i]-1].insert(make_pair(y[i]-1, i));
    }
    mxy = min(mxy, n);
    vl2 line(mxy, vl(w, -1));
    vl et(mxy, 0);
    rep(i, mxy) {
        bool al{true};
        rep(j, w) {
            if(row[j].size() > 0) {
                auto [tm, nm] = *row[j].begin();
                line[i][j] = nm;
                row[j].erase(row[j].begin());
                et[i] = max(et[i], tm);
            } else {
                al = false;
            }
        }
        if(!al) {
            srep(j, i, mxy) et[j] = MAXLL;
            break;
        }
    }

    vector<pair<pair<ll, ll>, ll>> qst(q);
    rep(i, q) {
        cin >> qst[i].first.first >> qst[i].first.second;
        qst[i].second = i;
    }
    sort(all(qst));

    /* rep(i, mxy) { */
    /*     rep(j, line[i].size()) { */
    /*         cout << line[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    vb rst(n, true);
    vb ans(q);
    ll li{0};
    rep(i, q) {
        ll tm = qst[i].first.first;
        ll nm = qst[i].first.second;
        ll qnm = qst[i].second;
        nm--;
        while(li < et.size() && tm > et[li]) {
            rep(j, w) if(line[li][j] >= 0) rst[line[li][j]] = false;
            li++;
        }
        ans[qnm] = rst[nm];
    }
    rep(i, q) {
        Yes(ans[i]);
    }
}
