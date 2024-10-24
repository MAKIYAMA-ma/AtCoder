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
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vl a(n, 0), h(n, 0);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> a[i];

    // kまでで条件を満たすaの最大値から、k+1までの最大値を果たして作れるか否か？
    // (1) 普通にk+1を足してOK
    // (2) K+1は諦める
    // (3) K+1より高いのを後から削っていってK+1を足す
    // 他のパターンはあるか？
    // -> kまでのパターンでは除外したけど、K+1より高いのを削るならやっぱ戻せる、というのは？
    // -> 新たに抜かれる奴よりk+1が低いんだからそれはありえない
    //    でも、どこまで新たにさかのぼって抜くのか分からないといけない
    //
    // うまくやったらLISのアルゴリズムで行けたりしないのかな。。。
    //
    // 最大の高さがk本目までで、最大の高さl以下の値を管理すれば？
    // h <= N <= 2 10^5
    // N*max(h) の状態数やサイクル数は管理しきれない。TLEやMLEになる。
    // 実際に使うhの数を考慮すればTLEは大丈夫かも？
    // でも、配列のデータ数は10^8個くらいのオーダーが限度
    // -> 一個前と最新のデータだけあればOK
    int maxh = *max_element(all(h));
    vl dpp(maxh+1, 0), dpc(maxh+1, 0);
    srep(i, h[0], maxh+1) {
        dpc[i] = a[0];
    }
    // これだとO(N2) N <= 2*10^5なので、TLE
    // h <= Nでかつhは互いに異なるので、絶対にhはn通りあり、データを間引くことはできない
    srep(i, 1, n) {
        swap(dpc, dpp);
        rep(j, maxh+1) {
            dpc[j] = max(dpp[j], (h[i] <= j) ? dpp[h[i] - 1] + a[i] : 0);
        }
    }
    /* cout << "-----------" << endl; */
    /* rep(k, maxh+1) { */
    /*     cout << dpc[k] << " "; */
    /* } */
    /* cout << endl; */
    /* cout << "-----------" << endl; */
    cout << dpc[maxh] << endl;
}
