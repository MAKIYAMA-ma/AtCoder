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
#define Def2A(a, b, n) vl a(n); rep(i, n) cin >> a[i] >> b[i];
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

void dijkstra(vpl2 &graph, ll start, vl &cost) {
    priority_queue<pl, vpl, greater<pl>> q;   // {cost, index}
    cost.at(start) = 0;
    q.push(make_pair(0, start));

    while(!q.empty()) {
        auto from = q.top().second;
        auto cst = q.top().first;
        q.pop();

        if(cost.at(from) < cst) {
            // 取得した情報が古い（最短でない）
            continue;
        }
        rep(i, graph.at(from).size()) {
            int to = graph.at(from).at(i).first;
            ll nc = graph.at(from).at(i).second + cst;

            if(nc < cost.at(to)) {
                cost.at(to) = nc;
                q.push(make_pair(nc, to));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    ll FIN = 86400;
    Def(n);
    Def(k);
    vpl lr(n), rl(n);
    vpl ori(n);
    rep(i, n) {
        cin >> lr[i].second >> lr[i].first;
        rl[i].first = FIN - lr[i].second;
        rl[i].second = FIN - lr[i].first;
        ori[i].first = lr[i].first;
        ori[i].second = lr[i].second;
    }
    sort(all(lr));
    sort(all(rl));
    vl pre(FIN+1, 0);
    vl pro(FIN+1, 0);
    ll cur{0};
    ll ind{0};
    ll cnt{0};

    rep(i, FIN+1) {
        if(ind < n && i >= lr[ind].first) {
            if(lr[ind].second >= cur) {
                cnt++;
                cur = lr[ind].first + k;
            }
            ind++;
        }
        pre[i] = cnt;
    }

    cur = ind = cnt = 0;
    rep(i, FIN+1) {
        if(ind < n && i >= rl[ind].first) {
            if(rl[ind].second >= cur) {
                cnt++;
                cur = rl[ind].first + k;
            }
            ind++;
        }
        pro[FIN - i] = cnt;
    }

    rep(i, n) {
        ll b = pre[max((ll)0, ori[i].second - k)];
        ll a = pro[min(ori[i].first + k, FIN)];
        cout << a + b + 1 << endl;
    }

    // i番目を必須として、最大何個の会議に出られるか
    // 会議間はk開ける
    // ---> 会議はr+kに終わると考えれば良いだけか。
    // 各iごとに、0 ~ Li, Ri+k ~ で夫々区間スケジューリングで良いか。
    // しかし都度ゼロから貪欲するとO(N^2)になる
    //
    // 一度計算した結果を元に、iに応じて微調整で答えが出せるか否か？
    // 1 ≤ N ≤ 100000
    // 0 ≤ K ≤ 86400
    // 0 ≤ Li < Ri ≤ 86400
    //
    // ----
    //  -
    //    ----
    //      ----
    //        -
}
