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

class UnionFind {
    public:
        vector<int> data;

        void init(int n) {
            data.resize(n, -1);
        }

        int root(int idx) {
            if(data.at(idx) == -1) {
                return idx;
            } else {
                // 深さ圧縮
                // ただし、同じグループの全要素の値が同じになるとは限らないので注意
                // (idxより根に近い要素の値は書き換わるが、idxより下の要素の値は書き換わらない。
                // その結果、2段にはなりうる。
                return (data.at(idx) = root(data.at(idx)));
            }
        }

        void merge(int a, int b) {
            int ar, br;

            if(a == b) {
                return;
            }

            ar = root(a);
            br = root(b);
            if(ar != br) {
                data.at(br) = ar;
            }
        }

        bool same(int a, int b) {
            int ar, br;

            if(a == b) {
                return true;
            }

            ar = root(a);
            br = root(b);

            return (ar == br);
        }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vpl tsk(n+1);
    ll mxt{0};
    rep(i, n) {
        cin >> tsk[i+1].second >> tsk[i+1].first;
        mxt = max(mxt, tsk[i+1].first);
    }
    sort(all(tsk));

    // iを回答するにはt[i]かかる。
    // iはD[i]までに解答しないと解答できなくなる
    // 最大何問解答可能か？
    // 1≤N≤100
    // 1≤Ti≤1,440
    // 1≤Di≤1,440
    // 制約が小さめ
    //
    // 開始終了も決まっていて最大選択するなら貪欲で区間スケジューリングだが
    // これは期間と最遅終了時間だけ決まっている
    //
    // 基本的には、早く期限を迎えてかつ短いものを先に消化したいはずだが。。。
    // しかし、やたらと時間をとる奴は期限が早くてもそもそも捨てたい
    // DPだと？
    // i番目までの宿題を、jまでにこなす場合の最大個数のDP
    vl dpc(mxt+1, 0), dpp(mxt+1, 0);
    srep(i, 1, n+1) {
        swap(dpc, dpp);
        rep(j, mxt+1) {
            dpc[j] = max(dpp[j], (j >= tsk[i].second && j <= tsk[i].first) ? (dpp[j - tsk[i].second] + 1) : 0);
        }
    }
    cout << *max_element(all(dpc)) << endl;
}
