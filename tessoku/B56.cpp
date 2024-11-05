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

/**
 * @brief 文字列のB進法ハッシュを計算・取得する為のクラス
 */
class BHash {
    public:
        vl htable;
        vl htabler;
        vl btable;
        ll mod;

        void init(string s, ll base, ll m) {
            int n = s.length();
            htable.resize(n, 0);
            htabler.resize(n, 0);

            mod = m;
            btable.resize(n, 1);
            srep(i, 1, n) {
                btable[i] = btable[i-1]*base % mod;
            }

            rep(i, n) {
                htable[i] = (s[i] - 'a' + 1) + ((i > 0) ? (htable[i-1] * btable[1]) : 0);
                htable[i] %= mod;
            }
            rrep(i, n) {
                htabler[i] = (s[i] - 'a' + 1) + ((i < n-1) ? (htabler[i+1] * btable[1]) : 0);
                htabler[i] %= mod;
            }
        }

        /**
         * @brief sの[l, r]の範囲のハッシュの取得
         *
         * @param l
         * @param r
         *
         * @return 
         */
        ll hash(int l, int r) {
            if(r < l) return 0;

            ll rh = htable[r];

            ll lrh{0};
            if(l > 0) {
                ll lh = htable[l-1];
                lrh = rh - ((lh * btable[r-l+1]) % mod);
            } else {
                lrh = rh;
            }
            lrh = (lrh + mod) % mod;

            return lrh;
        }

        ll hashr(int l, int r) {
            if(r < l) return 0;

            ll lh = htabler[l];

            ll lrh{0};
            if(r < htabler.size()-1) {
                ll rh = htabler[r+1];
                lrh = lh - ((rh * btable[r-l+1]) % mod);
            } else {
                lrh = lh;
            }
            lrh = (lrh + mod) % mod;

            return lrh;
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // N <= 10^5
    // N*Nの配列でDPをするのはMLEになるだろうから無理
    // 収まるならメモ化再帰でDPとかワンチャンありそうな気もするのだが
    Def(n);
    Def(q);
    string s;
    cin >> s;

    BHash bh;
    bh.init(s, 100000, 998244353);

    /* cout << "-------" << endl; */
    /* rep(i, s.length()) { */
    /*     srep(j, i, s.length()) { */
    /*         cout << bh.hash(i, j) << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "-------" << endl; */
    /* rep(i, s.length()) { */
    /*     srep(j, i, s.length()) { */
    /*         cout << bh.hashr(i, j) << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "-------" << endl; */

    rep(i, q) {
        Def(l);
        Def(r);
        Yes(bh.hash(l-1, r-1) == bh.hashr(l-1, r-1));
    }
}
