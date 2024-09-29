#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;

#if 0
    // これだとTLE
    vector<ll> a(3*n, 0);
    rep(i, 3*n) cin >> a.at(i);

    ll ans = (ll)-1 * n * 1000000000;
    for(int i = n; i <= 2*n; i++) {
        ll tmp = 0;
        priority_queue<ll> pq;
        priority_queue<ll, vector<ll>, greater<ll>> bq;
        int j;
        for(j = 0; j < i; j++) {
            pq.push(a.at(j));
        }
        for(; j < a.size(); j++) {
            bq.push(a.at(j));
        }
        rep(k, n) {
            tmp += pq.top();
            tmp -= bq.top();
            pq.pop();
            bq.pop();
        }
        ans = max(ans, tmp);
        /* cout << "DB:" << i << ":" << ans << endl; */
    }
    cout << ans << endl;
#elif 1
    // DP的な感じで計算
    vector<ll> a(3*n, 0);
    rep(i, 3*n) cin >> a.at(i);

    // nで区切る場合の計算
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    priority_queue<ll> bq;
    vector<ll> ph(n+1, 0);
    vector<ll> bh(n+1, 0);

    rep(i, n) {
        pq.push(a.at(i));
        ph.at(0) += a.at(i);

        bq.push(a.at(a.size() - i - 1));
        bh.at(0) += a.at(a.size() - i - 1);
    }
    rep(i, n) {
        ph.at(i+1) = ph.at(i);
        ph.at(i+1) += a.at(n+i);
        pq.push(a.at(n+i));
        auto pt = pq.top();
        ph.at(i+1) -= pt;
        pq.pop();
        /* cout << "DB1:" << a.at(n+i) << " " << pt << endl; */

        bh.at(i+1) = bh.at(i);
        bh.at(i+1) += a.at(2*n-i-1);
        bq.push(a.at(2*n-i-1));
        auto bt = bq.top();
        bh.at(i+1) -= bt;
        bq.pop();
        /* cout << "DB2:" << a.at(2*n-i-1) << " " << bt << endl; */
    }

    ll ans = (ll)-1 * n * 1000000000;
    rep(i, n+1) {
        /* cout << "DB:" << ph.at(i) << " " << bh.at(n-i) << endl; */
        ll tmp = ph.at(i) - bh.at(n-i);
        ans = max(ans, tmp);
    }

    cout << ans << endl;
#else
    vector<pair<ll, int>> a(3*n, pair<ll, int>(0, 0));
    rep(i, 3*n) {
        cin >> a.at(i).first;
        a.at(i).second = i;
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    priority_queue<pair<ll, int>> bq;
    int pi = 0;
    int bi = 3*n-1;
    for(pi = 0; pi < n; pi++) {
        pq.push(a.at(pi));
    }
    for(bi = 3*n-1; bi >= 2*n; bi--) {
        bq.push(a.at(bi));
    }
    while(pi <= bi) {
        auto pt = pq.top();
        auto bt = bq.top();
        int pv = (pt.first - a.at(pi).first);
        int bv = (a.at(bi).first - bt.first);

        if(abs(pv) > abs(bv)) {
            if(pv) {
                pq.pop();
                pq.push(a.at(pi++));
            } else {
                pi++;
            }
        } else {
            if(bv) {
                bq.pop();
                bq.push(a.at(bi--));
            } else {
                bi--;
            }
        }
    }
    ll ans = 0;
    while(!pq.empty()) {
        ans += pq.top().first;
        pq.pop();
    }
    while(!bq.empty()) {
        ans -= bq.top().first;
        bq.pop();
    }
    cout << ans << endl;
#endif
}
