#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
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


int main() {
    int n;
    cin >> n;

    cout << (isPrime(n) ? "YES" : "NO") << endl;
}
