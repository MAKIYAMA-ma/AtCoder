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


typedef struct {
    ll num;         // 路線番号
    ll src, dst;    // 出発/到着地
    ll st, tt;      // 出発/到着時間
    ll x;           // Delay
} ST_LINE;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    Def(x1);
    vector<ST_LINE> line(m);
    rep(i, m) {
        Def(a);
        Def(b);
        a--; b--;
        line[i].num = i;
        line[i].src = a;
        line[i].dst = b;
        cin >> line[i].st >> line[i].tt;
        line[i].x = 0;
    }
    line[0].x = x1;

    // 到着が早い順に処理か。
    //   ある路線に影響するのは、遅延ナシならその路線より早く到着しているはずの路線
    // (1) 到着が早い順に路線をソート
    // (2) それ以前に到着しているはずの路線のうち、実際の到着が一番遅い時間を取得する
    //   そもそも乗り継ぎ不可なら影響しないので、単純に処理済みの路線で最遅到着時間があれば良いとはいかないのでは？
    //   駅ごとに、処理済みの路線の通常到着時間と実到着時間を管理。
    //   実到着時間が遅いモノから順に、通常到着時間が出発より早いモノを探す。
#if 1
    vector<ll> arv(n, 0);
    vector<pair<ll, pair<bool, ll>>> tbl(2*m);
    rep(i, m) {
        tbl[i].first = line[i].st;
        tbl[i].second.first = true;
        tbl[i].second.second = i;

        tbl[m+i].first = line[i].tt;
        tbl[m+i].second.first = false;
        tbl[m+i].second.second = i;
    }
    sort(all(tbl));

    for(auto t : tbl) {
        auto idx = t.second.second;
        auto &l = line[idx];
        if(t.second.first) {
            // 出発時刻
            /* cout << "DB1:" << l.num << endl; */
            /* cout << "   :" << l.st << " " << l.tt << endl; */
            /* cout << "   :" << arv[l.src] << endl; */
            /* cout << "   :" << l.x << " -> "; */
            l.x = max(arv[l.src] - l.st, l.x);
            /* cout << l.x << endl; */
        } else {
            // 到着時刻
            /* cout << "DB2:" << l.num << endl; */
            /* cout << "   :" << l.st << " " << l.tt << endl; */
            /* cout << "   :" << arv[l.dst] << " -> "; */
            arv[l.dst] = max(arv[l.dst], l.tt + l.x);
            /* cout << arv[l.dst] << endl; */
        }
    }

    srep(i, 1, m) {
        cout << line[i].x << " ";
    }
    cout << endl;
#else
    sort(all(line), [](const ST_LINE &a, const ST_LINE &b){
            if(a.tt == b.tt) {
                return a.st < b.st;
            } else {
                return a.tt < b.tt;
            }
        });
    vector<set<pl, greater<pl>>> arv(n, set<pl, greater<pl>>());
    // TODO これだとTLE
    // やっぱり処理済み時間全部管理しているのが厳しい気も？
    for(auto &l : line) {
        ll latest{0};
        for(auto &a : arv[l.src]) {
            /* cout << "DB2:" << a.first << " " << a.second << endl; */
            if(a.second <= l.st) {
                latest = a.first;
                break;
            }
        }
        /* cout << "DB:" << l.num << endl; */
        /* cout << "  :" << l.st << " " << l.tt << endl; */
        /* cout << "  :" << latest << endl; */
        /* cout << "  :" << l.x << " -> "; */
        l.x = max(latest - l.st, l.x);
        /* cout << l.x << endl; */
        arv[l.dst].insert(make_pair(l.tt + l.x, l.tt));
    }

    sort(all(line), [](const ST_LINE &a, const ST_LINE &b){
            return a.num < b.num;
        });
    srep(i, 1, m) {
        cout << line[i].x << " ";
    }
    cout << endl;
#endif
}
