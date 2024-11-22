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

ll check(vl &tgt, vl &ed, int ind) {
    if(tgt[ind] < 0) {
        tgt[ind] = check(tgt, ed, ed[ind]) + 1;
    }
    return tgt[ind];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vl ed(n);
    rep(i, n) {
        cin >> ed[i];
        ed[i]--;
    }

    // 全て次数が1なのだから、閉路にひげが生えた構造になっているはず
    vl tgt(n, -1);
    vl status(n, -1);
    // -1: 未検証
    // 2: 検証中
    // 0: 閉路でない
    // 1: 閉路である
    rep(i, n) {
        int pos = i;
        bool fin = false;
        while(!fin) {
            switch(status[pos]) {
                case -1:
                    {
                        status[pos] = 2;
                        pos = ed[pos];
                    }
                    break;
                case 0:
                case 1:
                    {
                        int tmp = i;
                        // 処理済みのところに連結されたら今回チェックした箇所は全て閉路でない
                        while(status[tmp] == 2) {
                            status[tmp] = 0;
                            tmp = ed[tmp];
                        }
                        fin = true;
                    }
                    break;
                case 2:
                    {
                        int tmp = pos;
                        int cnt{0};
                        // 探索中の箇所に連結されたらその部分は閉路
                        // 閉路の構成要素から到達可能な頂点数は、閉路の構成頂点数と等しいので、
                        // それを数えながらstatusを更新する
                        while(status[tmp] == 2) {
                            status[tmp] = 1;
                            tmp = ed[tmp];
                            cnt++;
                        }
                        // 閉路の構成要素から到達可能な頂点数を、カウントした値に更新する
                        tmp = pos;
                        while(tgt[tmp] < 0) {
                            tgt[tmp] = cnt;
                            tmp = ed[tmp];
                        }
                        // サイクルに繋がるまでの探索部分は閉路でない
                        tmp = i;
                        while(status[tmp] == 2) {
                            status[tmp] = 0;
                            tmp = ed[tmp];
                        }
                        fin = true;
                    }
                    break;
            }
        }
    }
    ll ans{0};
    rep(i, n) {
        ans += check(tgt, ed, i);
    }
    cout << ans << endl;
}
