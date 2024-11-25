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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(q);
    string s;
    cin >> s;
    // 1 ≤ N ≤ 10^5
    // 1 ≤ Q ≤ 10^5
    //

    // sのl ~ rの範囲で、連続とは限らない部分文字列としてとれる11/22文字列の最大長を求める。
    // 制約も考慮すると、O(NlogN)とかで前処理をしたら、後はO(1)とかO(logN)とかで回答できる、という感じだと思うのだが。
    // DPな気はするが、LRの組合せについてN^2通り持つのはTLEだしMLEだろう。
    // LもRも文字列長も <= Nの範囲だから、キーをいじってもN^2の二次元配列になってしまうような
    //
    // 範囲内にある'/'の左側に1が何個あり、右側に2が何個あるかという話
    // 左から1の個数の累積、右から2の個数の累積を計算する。
    // /の位置を記録しておく。
    // 範囲内の各/とL,Rをもとに、計算する
    //
    // '/'がめっちゃたくさんある場合に、O(QN)になっちゃう気がする
    // 例えば、全部/で、L＝0、R=Nのクエリを繰り返したら、
    // 各/についてチェックするなら毎回N個チェックしないといけなくなる
    //
    // 連続する/を圧縮しようとすると？
    // それでも数字と/を連続させられたら、N/2このチェックが発生する。。。
    // 二分探索的に/を探しに行くことは可能か？
    //
    // LとRがなるべくつりあう位置の/が良い。
    // 範囲内で/をずらせば、1と2の個数は単調に変化する。
    // -> 1と2のどっちが多いかとかで二分探索して/を探せば良いのでは

    vl one(n, 0), two(n, 0);
    vl slash;
    // 左からの1の累積個数
    one[0] = ((s[0] == '1') ? 1 : 0);
    // 左端が/でも無意味なので無視でいいや
    srep(i, 1, n) {
        one[i] = one[i-1];
        if(s[i] == '1') {
            one[i]++;
        } else if(s[i] == '/') {
            // /の位置は記録しておく
            slash.push_back(i);
        }
    }
    // 右からの2の累積個数
    two[n-1] = ((s[n-1] == '2') ? 1 : 0);
    rrep(i, n-1) {
        two[i] = two[i+1];
        if(s[i] == '2') {
            two[i]++;
        }
    }

    rep(i, q) {
        Def(L);
        Def(R);
        L--; R--;

        auto l = lower_bound(all(slash), L) - slash.begin();
        auto r = upper_bound(all(slash), R) - slash.begin();
        /* cout << "DB:" << L << " " << R << endl; */
        /* cout << "DB2:" << l << " " << r << endl; */
        if(l >= slash.size() || slash[l] > R) {
            cout << 0 << endl;
        } else {
            while((r - l) > 1) {
                auto m = (l+r)/2;
                auto oc = one[slash[m]] - ((L > 0) ? one[L-1] : 0);
                auto tc = two[slash[m]] - ((R < n-1) ? two[R+1] : 0);
                if(oc < tc) {
                    l = m;
                } else {
                    r = m;
                }
            }
            cout << min(one[slash[l]] - ((L > 0) ? one[L-1] : 0), two[slash[l]] - ((R < n-1) ? two[R+1] : 0))*2 + 1 << endl;
        }
    }
}
