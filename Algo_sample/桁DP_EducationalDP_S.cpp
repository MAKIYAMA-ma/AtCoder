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

    string k;
    int d;
    cin >> k >> d;

    int keta = k.length();
    // Kの桁数個、0-9の数字を並べて、総和がDの倍数になる組合せ数
    // その結果について、K以下となる並べ替えのパターン
    // 並べ替えのパターンがK以下になるかどうか判定するのが面倒くさそうだが、何か軽そうな方法はあるか。。。
    // 1までの数字をi個使って各ModDになる個数、1までの。。。とかやるのは出来そうな気も。
    // 10000*101なので
    // でもその結果からは組合せは分かるけど順列の個数は分からない
    //
    // 桁DPというテンプレパターンらしい
    // (1) 上からi桁目まで固定した場合
    // (2) 1:K以下で確定
    // (3) modD
    vector<vm2> dp(keta+1, vm2(2, vm(d, 0)));
    // 一桁も選択していない、という状況は1パターンしかない。
    // この場合、K以下は未確定であり、mod D = 0
    dp[0][0][0] = 1;
    srep(i, 1, keta+1) {
        int kn = k[i - 1] - '0';
        rep(j, 9+1) {
            rep(l, d) {
                /* cout << j << ":" << kn << endl; */
                if(j == kn) {
                    // ここまでの桁で未確定なら引き続き未確定（Kとここまで一致）
                    // ここまでで既にK以下確定ならあとは何を入れても確定
                    dp[i][0][(l + j) % d] += dp[i-1][0][l];
                    dp[i][1][(l + j) % d] += dp[i-1][1][l];
                    /* cout << "DB1:" << i << ":0:" << (l + j) % d << ":" << dp[i][0][(l + j) % d].val() << endl; */
                    /* cout << "DB2:" << i << ":1:" << (l + j) % d << ":" << dp[i][1][(l + j) % d].val() << endl; */
                } else if(j > kn) {
                    // ここまででK以下確定の場合しか、kの該当桁より大きい数字は選択できない
                    // なので、確定->確定の遷移のみ
                    dp[i][1][(l + j) % d] += dp[i-1][1][l];
                    /* cout << "DB3:" << i << ":1:" << (l + j) % d << ":" << dp[i][1][(l + j) % d].val() << endl; */
                } else {
                    // ここまでが確定でも未確定でも、この桁でK以下が確定する
                    dp[i][1][(l + j) % d] += dp[i-1][0][l];
                    dp[i][1][(l + j) % d] += dp[i-1][1][l];
                    /* cout << "DB4:" << i << ":1:" << (l + j) % d << ":" << dp[i][1][(l + j) % d].val() << endl; */
                }
            }
        }
    }
    /* cout << "------------" << endl; */
    /* rep(i, keta+1) { */
    /*     cout << "keta: " << i << endl; */
    /*     rep(j, d) { */
    /*         cout << "    " << j << ":0: " << dp[i][0][j].val() << endl; */
    /*         cout << "    " << j << ":1: " << dp[i][1][j].val() << endl; */
    /*     } */
    /* } */
    /* cout << "------------" << endl; */
    // 最後の桁まで行ったので確定フラグは0でもいい。
    // 0になっているのは、該当の数字が = k であるということ。
    cout << (dp[keta][0][0] + dp[keta][1][0] - 1).val() << endl;
}
