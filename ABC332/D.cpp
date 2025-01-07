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

    Def(h);
    Def(w);

    vl2 a(h, vl(w, 0)), b(h, vl(w, 0));
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, h) rep(j, w) cin >> b[i][j];

    // 縦横それぞれ、含まれる要素は常に一定
    // 順序のずれ方も常に一定
    // というところで、可否を判定
    //
    // 可能となったら、0行と0列それぞれの転倒数で回数が判断できる

    vl2 ta(h, vl(w, 0)), tb(h, vl(w, 0));
    rep(i, h) {
        rep(j, w) {
            ta[i][j] = a[i][j];
            tb[i][j] = b[i][j];
        }
        sort(all(ta[i]));
        sort(all(tb[i]));
    }
    sort(all(ta));
    sort(all(tb));
    rep(i, h) {
        rep(j, w) {
            if(ta[i][j] != tb[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    vl2 ta2(w, vl(h, 0)), tb2(w, vl(h, 0));
    rep(i, w) {
        rep(j, h) {
            ta2[i][j] = a[j][i];
            tb2[i][j] = b[j][i];
        }
        sort(all(ta2[i]));
        sort(all(tb2[i]));
    }
    sort(all(ta2));
    sort(all(tb2));
    rep(i, w) {
        rep(j, h) {
            if(ta2[i][j] != tb2[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    // ここに来たなら可能
    // 縦横それぞれの転倒数をカウントする
    rep(i, h) {
        rep(j, w) {
            ta[i][j] = a[i][j];
            tb[i][j] = b[i][j];
        }
        sort(all(ta[i]));
        sort(all(tb[i]));
    }

    ll th{0};
    vl2 l(w, vl(h, 0));
    rep(i, w) {
        map<ll, ll> cnt;
        rep(j, h) {
            ll ind{0};
            ll c{0};
            while(ta[j][i] != tb[ind][i] || c < cnt[ta[j][i]]) {
                ind++;
                if(ta[j][i] == tb[ind][i]) c++;
            }
            l[i][j] = ind;
            cnt[ta[j][i]]++;
        }
    }
    rep(i, h) {
        srep(j, i+1, h) {
            rep(k, w) {
                // 同じ値の行も考慮し、一か所でも転倒していればカウント
                if(l[k][i] > l[k][j]) {
                    th++;
                    break;
                }
            }
        }
    }

    rep(i, w) {
        rep(j, h) {
            ta2[i][j] = a[j][i];
            tb2[i][j] = b[j][i];
        }
        sort(all(ta2[i]));
        sort(all(tb2[i]));
    }
    vl2 l2(h, vl(w, 0));
    rep(i, h) {
        map<ll, ll> cnt;
        rep(j, w) {
            ll ind{0};
            ll c{0};
            while(ta2[j][i] != tb2[ind][i] || c < cnt[ta2[j][i]]) {
                ind++;
                if(ta2[j][i] == tb2[ind][i]) c++;
            }
            l2[i][j] = ind;
            cnt[ta2[j][i]]++;
        }
    }
    rep(i, w) {
        srep(j, i+1, w) {
            rep(k, h) {
                if(l2[k][i] > l2[k][j]) {
                    th++;
                    break;
                }
            }
        }
    }
    cout << th << endl;
}
