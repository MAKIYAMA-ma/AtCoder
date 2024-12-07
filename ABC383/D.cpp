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

/**
 * @brief nを素因数分解し、prmに結果を入れる関数
 *
 * @param n     素因数分解の対象
 * @param prm   分解結果。各素因数をkeyとし、その個数をvalueとして格納する。
 */
void PrimeFact(ll n, map<ll, ll> &prm) {
    ll tmp = n;
    for(ll i = 2; i <= tmp; i++) {
        // iが素数かどうかの判定は不要
        // iが素数でないなら、iの約数による割り算がもっと前に完了している
        while(tmp % i == 0) {
            prm[i]++;
            tmp /= i;
        }
    }
    /* cout << "------------" << endl; */
    /* for(auto p : prm) { */
    /*     cout << p.first << ":" << p.second << endl; */
    /* } */
    /* cout << "------------" << endl; */
}

bool isPrime(ll n) {
    ll fin = sqrt(n);
    vector<ll> wheel_fact = {4, 2, 4, 2, 4, 6, 2, 6};
    int wfi = 0;

    if(n == 1) {
        return false;
    }
    if((n == 2) || (n == 3) || (n == 5)) {
        return true;
    }
    if((n % 2 == 0) || (n % 3 == 0) || (n % 5 == 0)) {
        return false;
    }
    for(ll i = 7; i <= fin; i += wheel_fact.at(wfi++ % wheel_fact.size())) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);

    // 約数が9個
    // 1 2 3 4 6 9 12 18 36
    // 1 2 4 5 10 ...
    // (1) x^2であること
    // (2) x未満の約数が4個であること
    // -> xの約数が二つであること？(1, 小、大、小^2)
    // --> チェック範囲は2*10^6まで
    //
    // 素数の積の二乗がn以下となる組み合わせ数が知りたい
    ll ans{0};
#if 1
    vl prm;
    ll sq = (ll)sqrt(n);
    srep(i, 2, sq+1) {
        if(isPrime(i)) prm.push_back(i);
    }
    rep(i, prm.size()) {
        auto s = prm[i];
        auto tmp = upper_bound(prm.begin()+i+1, prm.end(), sq/s) - (prm.begin()+i+1);
        if(tmp > 0) {
            /* cout << "DB:" << s << " " << tmp << endl; */
            ans += tmp;
        } else {
            break;
        }
    }
#else
    rep(i, n) {
        ll tgt = i*i;
        if(tgt > n) break;

        map<ll, ll> prm;
        PrimeFact(i, prm);
        bool res = true;
        if(prm.size() == 2) {
            for(auto m : prm) {
                if(m.second != 1) {
                    res = false;
                    break;
                }
            }
        } else {
            res = false;
        }
        if(res) ans++;
    }
#endif
    cout << ans << endl;
}
