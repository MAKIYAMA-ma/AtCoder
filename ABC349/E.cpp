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

int check(int ply, ll bd, map<ll, int> &win, vl2 &a) {
    if(win.find(bd) != win.end()) return win[bd];
    ll tmp = bd;
    bool we = false;

    vl2 st(3, vl(3, 0));
    rep(i, 3) {
        rep(j, 3) {
            st[i][j] = (tmp%10);
            if(!st[i][j]) we = true;
            tmp /= 10;
        }
    }

    rep(i, 3) {
        if(st[i][0] != 0 && (st[i][0] == st[i][1] && st[i][1] == st[i][2])) {
            win[bd] = st[i][0]-1;
            return win[bd];
        }
        if(st[0][i] != 0 && (st[0][i] == st[1][i] && st[1][i] == st[2][i])) {
            win[bd] = st[0][i]-1;
            return win[bd];
        }
    }
    if(st[0][0] != 0 && (st[0][0] == st[1][1] && st[1][1] == st[2][2])) {
        win[bd] = st[0][0]-1;
        return win[bd];
    }
    if(st[0][2] != 0 && (st[0][2] == st[1][1] && st[1][1] == st[2][0])) {
        win[bd] = st[0][2]-1;
        return win[bd];
    }
    if(!we) {
        vl pt(2, 0);
        rep(i, 3) {
            rep(j, 3) {
                pt[st[i][j]-1] += a[i][j];
            }
        }
        win[bd] = max_element(all(pt)) - pt.begin();
        return win[bd];
    }

    tmp = bd;
    int clr = ply+1;
    win[bd] = -1;
    rep(i, 9) {
        if(tmp % 10 == 0) {
            if(check((ply+1)%2, bd + clr, win, a) == ply) {
                win[bd] = ply;
            }
        }
        clr *= 10;
        tmp /= 10;
    }
    if(win[bd] < 0) win[bd] = (ply+1)%2;

    return win[bd];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    vl2 a(3, vl(3, 0));
    rep(i, 3) rep(j, 3) cin >> a[i][j];

    // 最適行動とは何か？
    // 1手で連続を取れるなら当然それが最善
    // 盤面のパターンは3^9 = 19683通り（ありえない盤面もある）
    // 全探索的な方向性？？
    //
    // 点数で勝敗が決まる場合、選んでいるマスは5x4
    // 4! = 3024通りしかないから、最終形は網羅可能
    //
    // 最適行動の前提の場合に白を残して勝負がつくことはありうるのか？
    // 各局面で、先手を一手戻した状態は詰み
    // そこから一手戻して、詰みに持ち込めない局面が存在すれば、それは先手必勝ではない
    //
    // 基本これ系はDP
    //
    // (1) 全局面についてDPする
    // (2) 最初に、ありえてかつ先手処理の局面か判定。YesならDP開始
    // (3) 先手必勝が一つでも見つかれば先手勝ち、一個もなければ後手勝ち
    map<ll, int> win;
    if(check(0, 0, win, a)) {
        // 後攻勝ち
        cout << "Aoki" << endl;
    } else {
        cout << "Takahashi" << endl;
    }
}
