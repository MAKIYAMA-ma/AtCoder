#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> mcn(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    rep(i, n) {
        cin >> mcn.at(i).first >> mcn.at(i).second;
        q.push(mcn.at(i));
    }

    ll ans = 0;
    rep(i, k) {
        auto nxt = q.top();
        q.pop();
        ans += nxt.first;
        nxt.first += nxt.second;
        q.push(nxt);
    }
    cout << ans << endl;
}
