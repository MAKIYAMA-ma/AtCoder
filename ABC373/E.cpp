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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    Def(k);
    vl a(n), oa(n);
    rep(i, n) {
        cin >> a[i];
        oa[i] = a[i];
    }
#if 1
    sort(all(oa));
    ll saa = reduce(all(a));
    vl suma(m+1, 0);
    rep(i, m+1) {
        suma[i] = ((i > 0) ? suma[i-1] : 0) + oa[n-1-(m-i)];
    }

    // iをxにし、他に上位M個をx+1にする
    // その際に必要な増加量の合計が、k-saa以下なら実現可能（落選しうる）
    //  -> lをあげる
    // k-saaより大きいなら実現不可能（当選確実）
    //  -> rを下げる

    rep(i, n) {
        if(m >= n) {
            cout << 0 << endl;
            continue;
        }
        ll l = a[i]-1;
        ll r = k+2;
        while((r-l) > 1) {
            ll mid = (l+r)/2;
            /* auto lp = lower_bound(all(oa), mid+1) - oa.begin() - (n-m); */
            // mid+1に到達するまで追加の票が必要な議員数
            auto lp = m - (oa.end() - lower_bound(all(oa), mid+1));
            // 議員iがmid票に到達するのに必要な追加の票数
            ll sm = (mid >= a[i]) ? (mid - a[i]) : 0;
            if(lp > 0) {
                // 議員i以外にM人をmid+1票に到達させるのに必要な票数
                sm += (mid+1)*(lp);
                sm -= (suma[lp] - max(a[i], oa[n-1-m]));
            }
            // 追加が必要な票数の合計がk-saaより多いなら、実現不可（議員iはmid票に到達したら当選確実）
            if(sm > (k-saa)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ll nd = r-a[i];
        if(nd <= k-saa) {
            cout << nd;
        } else {
            // 追加が必要な最低限の票が残りの票で足りないなら当選確実にはならない
            cout << -1;
        }
        cout << " ";
    }
    cout << endl;
#else
    sort(rall(oa));

    // K票あり、現在の得票がA。
    // 上位M人当選として、各候補者が当選確実となるまでの不足票は何票か？
    // 1 ≤ M ≤ N≤2×10^5
    // 1 ≤ K ≤ 10^12
    // 0 ≤ Ai ≤ 10^12
    // ∑Ai ≤ K
    //
    // 答えがX票とする。
    // 自分以外の現在上位M人に、(K-X-ΣA)票が全て入ったとして、M番目の候補が自分を超えないのであればOK
    // -> (対象のM人の得票+(K-X-ΣA))/M < Ai + X
    // であれば当選確実
    // (1) 現在の上位M人、及びM+1人、及び全員の合計得票を計算する。
    // (2) Xは答えの二分探索で良いか？？？
    ll saa = reduce(all(a));
    ll sma = reduce(a.begin(), a.begin() + m);
    ll sm1a = sma + a[m];
    rep(i, n) {
        ll ma;
        if(a[i] < oa[m-1]) {
            ma = sma;
        } else {
            ma = sm1a - a[i];
        }

        ll l{0};
        ll r = k - saa + 1;
        while((r-l) > 1) {
            ll mid = (r+l)/2;
            ll bdr = (ma + k - mid - saa)/m;

            ll oc{0};
            for(ll j = 0; j < n && oa[j] > bdr; j++){
                oc++;
            }
            bdr += (oc*bdr)/(m-oc);
            if(bdr < a[i] + mid) {
                r = mid;
            } else {
                l = mid;
            }
        }

        if(r <= 0) {
            cout << 0 << " ";
        } else if(r <= (k-saa)) {
            cout << r << " ";
        } else {
            cout << -1 << " ";
        }
    }
    cout << endl;
#endif
}
