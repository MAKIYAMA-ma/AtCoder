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

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
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
    vl a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    // 各チームの強さはBの総和
    // 3チームの強さを等しくできるか？
    // -> Bを均等に3分割できるか？
    // できるなら、現状のチーム分けから最短の方法は？
    // Bの総和は1500以下
    //
    // 目指す強さは自明
    // Bの累積を3チーム分用意して、「全部等しい」が作れるかはDPで判定可能?
    // 単純にやると
    // 1500^3をllで2状態持ったら51500MByte。MLE。
    // ΣBの1/3までで十分で超えた分は捨てるとしたら
    // 2*500^3 = 1907MByte
    // llでは無理だが、intならMLEにならない。
    //
    // そこから最短手数を求めるには？？？
    //
    // DPの値として、たどり着けるかどうかだけではなく、そこまでに幾つ変更したかを格納する。
    ll totalb = reduce(all(b));
    if(totalb % 3) {
        // 絶対無理
        cout << -1 << endl;
        return 0;
    }
    ll tgtb = totalb/3;
#if 1
    // AとBの得点からCの得点は求まる
    vi2 dpc(tgtb+1, vi(tgtb+1, MAXI));
    vi2 dpp(tgtb+1, vi(tgtb+1, MAXI));
    dpc[0][0] = 0;

    rep(i, n) {
        swap(dpc, dpp);

        rep(j, tgtb+1) {
            rep(k, tgtb+1) {
                /* cout << "DB:" << j << "," << k << "," << l << endl; */
                dpc[j][k] = min({
                        (j >= b[i]) ? (dpp[j-b[i]][k] + ((a[i] == 1) ? 0 : 1)) : MAXI,
                        (k >= b[i]) ? (dpp[j][k-b[i]] + ((a[i] == 2) ? 0 : 1)) : MAXI,
                        (dpp[j][k] + ((a[i] == 3) ? 0 : 1))});
            }
        }
    }
    if(dpc[tgtb][tgtb] >= MAXI) {
        dpc[tgtb][tgtb] = -1;
    }
    cout << dpc[tgtb][tgtb] << endl;
#else
    // TLE
    // 500^3 = 1.25 * 10^8
    // 中の処理が足し算ひとつとかなら間に合うのだろうが。
    vector<vi2> dpc(tgtb+1, vi2(tgtb+1, vi(tgtb+1, MAXI)));
    vector<vi2> dpp(tgtb+1, vi2(tgtb+1, vi(tgtb+1, MAXI)));
    dpc[0][0][0] = 0;

    rep(i, n) {
        swap(dpc, dpp);

        rep(j, tgtb+1) {
            rep(k, tgtb+1) {
                rep(l, tgtb+1) {
                    /* cout << "DB:" << j << "," << k << "," << l << endl; */
                    dpc[j][k][l] = min({
                            (j >= b[i]) ? (dpp[j-b[i]][k][l] + ((a[i] == 1) ? 0 : 1)) : MAXI,
                            (k >= b[i]) ? (dpp[j][k-b[i]][l] + ((a[i] == 2) ? 0 : 1)) : MAXI,
                            (l >= b[i]) ? (dpp[j][k][l-b[i]] + ((a[i] == 3) ? 0 : 1)) : MAXI});
                }
            }
        }
    }
    if(dpc[tgtb][tgtb][tgtb] >= MAXI) {
        dpc[tgtb][tgtb][tgtb] = -1;
    }
    cout << dpc[tgtb][tgtb][tgtb] << endl;
#endif
}
