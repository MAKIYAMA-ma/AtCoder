#include <bits/stdc++.h>
using namespace std;

// 二分探索
// 74 ms	5740 KB
void func1() {
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
        long long ri = r - xl.begin();

        /* cout << "DBG:" << i << " " << li << " " << ri << endl; */
        if(ri >= li) {
            /* ans += (ri - li + 1); */
            ans += (ri - li);
        }
    }

    cout << ans << endl;
}

// 二分探索で、尺取り法のように詰めていく
// 71 ms	5796 KB
void func2() {
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

    long long ans = 0;
    auto l = xl.begin();
    auto r = xl.begin();
    for(int i = 0; i < xr.size(); i++) {
        // 一番近い左向の蟻
        l = lower_bound(l, xl.end(), xr.at(i));
        if(l == xr.end()) {
            continue;
        }
        long long li = l - xl.begin();

        // すれ違える最後の蟻の次
        r = upper_bound(r, xl.end(), (t*2) + xr.at(i));
        long long ri = r - xl.begin();

        /* cout << "DBG:" << i << " " << li << " " << ri << endl; */
        if(ri >= li) {
            /* ans += (ri - li + 1); */
            ans += (ri - li);
        }
    }

    cout << ans << endl;
}

// 尺取り法
// 70 ms	5872 KB
void func3() {
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

    long long ans = 0;
    int l = 0;
    int r = 0;
    for(int i = 0; i < xr.size(); i++) {
        while((l < xl.size()) && (xl.at(l) <= xr.at(i))) l++;
        while((r < xl.size()) && (xl.at(r) <= (xr.at(i) + (t*2)))) r++;
        if(r >= l) {
            ans += (r - l);
        }
    }

    cout << ans << endl;
}

int main() {
    func3();
}
