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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }

    vector<ll> ac(n*2, 0);

#if 1
    rep(i, n-1) {
        ac.at(i+1) = (ac.at(i) + a.at(i)) % m;
    }
    ac.at(n) = (ac.at(n-1) + a.at(n-1)) % m;
    for(int i = n+1; i < 2*n; i++) {
        ac.at(i) = (ac.at(i-n) + ac.at(n)) % m;
    }

    // mod mの値ごとに、該当するindexを記録する事でMLEを回避
    vector<vector<ll>> mi(m);
    rep(i, n*2) {
        mi.at(ac.at(i)).push_back(i);
    }
    // 当然ソートされているからこれは不要
    /* rep(i, m) { */
    /*     sort(all(mi.at(i))); */
    /* } */

    // n未満のlから、l+nまでの範囲の個数を尺取り法でカウント
    ll ans = 0;
    rep(i, m) {
        int r = 1;
        for(int l = 0; l < mi.at(i).size() && mi.at(i).at(l) < n; l++) {
            while(r < mi.at(i).size() && mi.at(i).at(r) < ((mi.at(i).at(l)+n))) {
                r++;
            }
            ans += (r-l-1);
        }
    }
    cout << ans << endl;
#elif 0
    // modで累積個数をカウント
    // -> MLE
    rep(i, n-1) {
        ac.at(i+1) = (ac.at(i) + a.at(i)) % m;
    }
    ac.at(n) = (ac.at(n-1) + a.at(n-1)) % m;
    for(int i = n+1; i < 2*n; i++) {
        ac.at(i) = (ac.at(i-n) + ac.at(n)) % m;
    }
    /* rep(i, ac.size()) { */
    /*     cout << ac.at(i) << " "; */
    /* } */
    /* cout << endl; */
    vector<vector<ll>> ml(n*2, vector<ll>(m, 0));
    ml.at(0).at(0) = 1;
    rep(i, n*2-1) {
        rep(j, m) {
            ml.at(i+1).at(j) = ml.at(i).at(j);
        }
        ml.at(i+1).at(ac.at(i+1))++;
    }
    ll ans = 0;
    rep(i, n) {
        int md = ac.at(i);
        ans += ml.at(i+n).at(md) - ml.at(i).at(md);
    }
    cout << ans << endl;
#else
    // TODO O(N2) TLE
    rep(i, n-1) {
        ac.at(i+1) = (ac.at(i) + a.at(i));
    }
    ac.at(n) = (ac.at(n-1) + a.at(n-1));
    for(int i = n+1; i < 2*n; i++) {
        ac.at(i) = (ac.at(i-n) + ac.at(n));
    }
    /* rep(i, ac.size()) { */
    /*     cout << ac.at(i) << " "; */
    /* } */
    /* cout << endl; */
    ll ans = 0;
    rep(i, n) {
        for(int j = i+1; j < i+n; j++) {
            if((ac.at(j) - ac.at(i)) % m == 0) {
                /* cout << "DB:" << i << " " << j << endl; */
                ans++;
            }
        }
    }
    cout << ans << endl;
#endif
}
