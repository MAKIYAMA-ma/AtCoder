#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> wl(n);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        pair<int, int> p = {v-1, w};
        pair<int, int> pv = {u-1, -w};
        wl.at(u-1).push_back(p);
        wl.at(v-1).push_back(pv);
    }

    vector<ll> ans(n, 0);
    ll maxv = 0;
    ll minv = 0;

    int tmp = 0;
    vector<bool> fin(n, false);
    while(true) {
        bool finish = true;
        stack<int> srch;
        rep(i, n) {
            if(!fin.at(i)) {
                finish = false;
                srch.push(i);
                fin.at(i) = true;
                break;
            }
        }
        if(finish)  {
            break;
        }
        while(!srch.empty()) {
            auto nxt = srch.top();
            srch.pop();

            rep(j, wl.at(nxt).size()) {
                /* maxv = max(maxv, ans.at(wl.at(nxt).at(j).first)); */
                /* minv = min(minv, ans.at(wl.at(nxt).at(j).first)); */
                /* if(maxv >= (ll)pow(10, 18)) { */
                /*     ll offset = (ll)pow(10, 18) - maxv; */
                /*     rep(k, n) { */
                /*         ans.at(k) += offset; */
                /*     } */
                /* } else if(minv <= -(ll)pow(10, 18)) { */
                /*     ll offset = -(ll)pow(10, 18) - minv; */
                /*     rep(k, n) { */
                /*         ans.at(k) += offset; */
                /*     } */
                /* } */
                if(!fin.at(wl.at(nxt).at(j).first)) {
                    ans.at(wl.at(nxt).at(j).first) = ans.at(nxt) + wl.at(nxt).at(j).second;
                    srch.push(wl.at(nxt).at(j).first);
                    fin.at(wl.at(nxt).at(j).first) = true;
                }
            }
        }
    }

    ll offset = (ll)pow(10, 18) - *max_element(all(ans));
    rep(i, n) {
        cout << ans.at(i) + offset << " ";
    }
    /* rep(i, n) { */
    /*     cout << ans.at(i) << " "; */
    /* } */
    cout << endl;
}
