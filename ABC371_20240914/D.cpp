#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<pair<int, int>> d(n);
    vector<int> x(n);
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> x.at(i);
    }
    for(int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    for(int i = 0; i < n; i++) {
        d.at(i).first = x.at(i);
        d.at(i).second = p.at(i);
    }
    sort(d.begin(), d.end());

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        auto lp = lower_bound(d.begin(), d.end(), l,
                [](const pair<int, int>& a, int value) {
                return a.first < value;
                });
        auto rp = lower_bound(d.begin(), d.end(), r,
                [](const pair<int, int>& a, int value) {
                return a.first < value;
                });
        if (lp == d.end()) {
            cout << 0 << endl;
        } else {
            if((lp-1)->first == l) lp--;
            int total_sum = accumulate(lp, rp, 0, [](int sum, const pair<int, int>& p) {
                    return sum + p.second;
                    });
            cout << "ans:" << total_sum << endl;
        }
    }
}
