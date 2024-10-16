#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    int n;
    cin >> n;

    vector<ll> l(n, 0);
    vector<ll> r(n, 0);
    rep(i, n) {
        cin >> l[i] >> r[i];
    }

    // 正解の数列も必要
    // 全てli <= xi <= riであり、総和が0である数列
    // 数列の総和の範囲は、Σli からΣriの範囲なので、この範囲に0が入れば構成可能。
    // 実際の構成は？そこまでの総和が±どっちかとかでいける？
    ll ls = 0;
    ll rs = 0;
    rep(i, n) {
        ls += l[i];
        rs += r[i];
    }
    Yes(ls <= 0 && rs >= 0);
    /// 実際の構成
    if(ls <= 0 && rs >= 0) {
#if 1
        // 解説を基に実装。AC
        // 限界までマイナスにふり、0になるまで＋していくということ。
        // そりゃそうだ。。。
        ll sum = 0;
        vector<ll> ans(n, 0);
        rep(i, n) {
            ans[i] = l[i];
            sum += l[i];
        }
        rep(i, n) {
            ll d = min(r[i] - l[i], -sum);
            ans[i] += d;
            sum += d;
        }
        rep(i, n) {
            cout << ans[i] << " ";
        }
        cout << endl;
#else
        vector<pair<ll, int>> dist(n);
        rep(i, n) {
            dist[i].second = i;
            if(l[i] <= 0 && r[i] >= 0) {
                dist[i].first = 0;
            } else if (l[i] >= 0) {
                dist[i].first = l[i];
            } else {
                dist[i].first = -r[i];
            }
        }
        sort(rall(dist));

        // 0から離れた範囲の位置から順に、なるべく総和が0に近づくように貪欲する
        // TODO これでは正確に構成できない
        // 例えば、残り二つの段階でsum=3で、
        // -5~-2, 1~3が残っている場合、
        // 下記の流れだと-3, 1を選んでsum=1で終わってしまう。
        // -5, 2などとすればsum=0にできる。
        ll sum = 0;
        vector<ll> ans(n, 0);
        rep(i, n) {
            int ind = dist[i].second;
            /* cout << "DB:" << ind << ":" << sum << endl; */
            if(((-sum) >= l[ind]) && ((-sum) <= r[ind])) {
                ans[ind] = -sum;
            } else if(abs(sum + l[ind]) < abs(sum + r[ind])) {
                ans[ind] = l[ind];
            } else {
                ans[ind] = r[ind];
            }
            sum += ans[ind];
        }
        rep(i, n) {
            cout << ans[i] << " ";
        }
        cout << endl;
#endif
    }
}
