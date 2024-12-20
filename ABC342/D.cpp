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
 * @brief 素数判定
 *
 * @param n
 *
 * @return 
 */
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    map<ll, ll> vals;
    rep(i, n) {
        Def(a);
        vals[a]++;
    }

    // (1) 各要素を素因数分解
    // (2) 同一素数の個数の和が全て偶数になるペアを探す
    // ということになるはずだが、
    // N <= 2*10^5
    // なので、個別にチェックは当然NG
    map<ll, ll> cnt;
    for(auto [vv, vc] : vals) {
        if(vv == 0) {
            cnt[0] += vc;
        } else {
            map<ll, ll> prm;
            PrimeFact(vv, prm);
            ll val{1};
            for(auto p : prm) {
                if(p.second % 2) val *= p.first;
            }
            cnt[val] += vc;
        }
    }

    ll ans{0};
    for(auto c : cnt) {
        if(c.first == 0) {
            ans += c.second*(n-c.second);
        }
        ans += (c.second*(c.second-1))/2;
    }
    cout << ans << endl;
}
