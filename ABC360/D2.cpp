#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, t;
    string s;

    cin >> n >> t;
    cin >> s;

    vector<long long> xr;
    vector<long long> xl;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if(s[i] == '1') {
            xr.push_back(x);
        } else {
            xl.push_back(x);
        }
    }
    sort(xr.begin(), xr.end());
    sort(xl.begin(), xl.end());

    key 10
    t 5
    20


    long long ans = 0;
    for(int i = 0; i < xr.size(); i++) {
        // 一番近い左向の蟻
        auto l = lower_bound(xl.begin(), xl.end(), xr.at(i));
        if(l == xr.end()) {
            continue;
        }
        long long li = l - xl.begin();

        // すれ違える最後の蟻の次
        auto r = upper_bound(xl.begin(), xl.end(), (t*2) + xr.at(i));
        /* if (r != xl.begin()) { */
        /*     --r; */
        /* } */
        long long ri = r - xl.begin();

        /* cout << "DBG:" << i << " " << li << " " << ri << endl; */
        if(ri >= li) {
            /* ans += (ri - li + 1); */
            ans += (ri - li);
        }
    }

    cout << ans << endl;
}
