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

    vector<vs> p(3, vs(4));
    rep(i, 3) rep(j, 4) cin >> p[i][j];

    // 向きが4^3通り、順番が6通り

    vl2 cl(4, vl(4, 0));
    vl od = {0, 1, 2};

    // 各ピースを回転させたデータをあらかじめ準備
    vector<vector<vl2>> pd(3, vector<vl2>(4, vl2(4, vl(4, 0))));
    rep(i, 3) {
        rep(j, 4) {
            rep(k, 4) {
                rep(l, 4) {
                    switch(j) {
                        case 0: pd[i][j][k][l] = ((p[i][k][l] == '#') ? 1 : 0); break;
                        case 1: pd[i][j][k][l] = ((p[i][l][3-k] == '#') ? 1 : 0); break;
                        case 2: pd[i][j][k][l] = ((p[i][3-k][3-l] == '#') ? 1 : 0); break;
                        case 3: pd[i][j][k][l] = ((p[i][3-l][k] == '#') ? 1 : 0); break;
                    }
                }
            }
        }
    }

    /* rep(i, 3) { */
    /*     rep(j, 4) { */
    /*         cout << "------" << endl; */
    /*         rep(k, 4) { */
    /*             rep(l, 4) { */
    /*                 cout << pd[i][j][k][l] << " "; */
    /*             } */
    /*             cout << endl; */
    /*         } */
    /*         cout << "------" << endl; */
    /*     } */
    /* } */

    // ピースのはめる順序と向きを総当たり
    do {
        rep(dir, 4*4*4) {
            bool ng{false};
            ll tmp = dir;
            vl d(3);
            rep(i, 3) {
                d[i] = tmp%4;
                tmp /= 4;
            }

            rep(i, 4) fill(all(cl[i]), 0);
            ll ix{0}, iy{0};
            rep(i, 3) {
                /* cout << "DB:"; */
                /* rep(j, 3) cout << od[j] << " "; */
                /* cout << endl; */
                /* cout << "DB2:"; */
                /* rep(j, 3) cout << d[j] << " "; */
                /* cout << endl; */

                // 左上から順に空きマスを探す
                while(ix < 4 && iy < 4 && cl[iy][ix]) {
                    ix++;
                    if(ix >= 4) {
                        iy++;
                        ix = 0;
                    }
                }

                // 次にはめるピースの左上から順にタイルがある場所を探す
                ll px{0}, py{0};
                while(px < 4 && py < 4 && !pd[od[i]][d[i]][py][px]) {
                    px++;
                    if(px >= 4) {
                        py++;
                        px = 0;
                    }
                }
                ll dx = ix-px;
                ll dy = iy-py;

                // はめ込む
                rep(j, 4) {
                    rep(k, 4) {
                        if(pd[od[i]][d[i]][j][k]) {
                            ll nx = k+dx;
                            ll ny = j+dy;
                            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || cl[ny][nx]) {
                                /* cout << "NG:" << k << " " << j << " " << nx << " " << ny << endl; */
                                /* cout << ix << " " << iy << " " << px << " " << py << " " << endl; */
                                /* cout << dx << " " << dy << endl; */
                                ng = true;
                                break;
                            }
                            cl[ny][nx] = 1;
                        }
                    }
                    if(ng) break;
                }
                if(ng) break;

                /* cout << "------" << endl; */
                /* rep(k, 4) { */
                /*     rep(l, 4) { */
                /*         cout << cl[k][l] << " "; */
                /*     } */
                /*     cout << endl; */
                /* } */
                /* cout << "------" << endl; */
            }

            if(!ng) {
                // 全てのピースがはめられたなら、全てのマスがおおわれているかチェック
                ll ad{0};
                rep(i, 4) ad += reduce(all(cl[i]));
                if(ad == 4*4) {
                    Yes(1);
                    return 0;
                }
            }
        }
    } while (next_permutation(all(od)));

    Yes(0);
}
