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

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
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
void PrimeFact(ll n, map<int, int> &prm) {
    int tmp = n;
    for(int i = 2; i <= tmp; i++) {
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
    int q;
    int MXV = 100000;
    cin >> q;

    vector<int> vals(MXV+1, 0);
    for(int i = 3; i < MXV+1; i = i+2) {
        // 偶数のデータは無視
        vals.at(i) = vals.at(i-2);
        if(isPrime(i) && isPrime((i+1)/2)) {
            vals.at(i)++;
        }
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << vals.at(r) - ((l == 1) ? 0 : vals.at(l - 2)) << endl;
    }
}
