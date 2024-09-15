#include <bits/stdc++.h>
using namespace std;

#define USE_ACC false

int main() {
    int n;

    cin >> n;

    // 個別のpはintで収まるが、pの累積を計算するならintではあふれる
    vector<pair<int, long long>> d(n+1);
    d.at(0).first = -(pow(10, 9)+1);
    d.at(0).second = 0;
    for(int i = 0; i < n; i++) {
        cin >> d.at(i+1).first;
    }
    for(int i = 0; i < n; i++) {
        cin >> d.at(i+1).second;
#if USE_ACC
#else
        d.at(i+1).second += d.at(i).second;
#endif
    }
    /* cout << "sum:"; */
    /* for(int i = 0; i <= n; i++) { */
    /*     cout << d.at(i).second << " "; */
    /* } */
    /* cout << endl; */

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
#if USE_ACC
        // l以上の最小値
        pair<int, int> tgt = {l, 0};
        auto lp = lower_bound(d.begin(), d.end(), tgt, [](const pair<int, long long>& a, const pair<int, long long>& b) {
                return a.first < b.first;
                });
        // rより大きい最小値
        tgt.first = r;
        auto rp = upper_bound(d.begin(), d.end(), tgt, [](const pair<int, long long>& a, const pair<int, long long>& b) {
                return a.first < b.first;
                });

        /* cout << "range:" << lp->first << " " << rp->first << endl; */
        int total_sum = accumulate(lp, rp, 0, [](int sum, const pair<int, long long>& p) {
                return sum + p.second;
                });
        /* cout << "ans:" << total_sum << endl; */
        cout << total_sum << endl;
#else
        // l未満の最大値
        // (l以上の最小値のひとつ前）
        pair<int, int> tgt = {l, 0};
        auto lp = lower_bound(d.begin(), d.end(), tgt, [](const pair<int, long long>& a, const pair<int, long long>& b) {
                return a.first < b.first;
                });
        if (lp != d.begin()) {
            --lp;
        }
        // r以下の最大値
        // (rより大きい最小値のひとつ前）
        tgt.first = r;
        auto rp = upper_bound(d.begin(), d.end(), tgt, [](const pair<int, long long>& a, const pair<int, long long>& b) {
                return a.first < b.first;
                });
        if (rp != d.begin()) {
            --rp;
        }

        /* cout << "range:" << lp->first << " " << rp->first << endl; */
        /* int total_sum = accumulate(lp, rp, 0, [](int sum, const pair<int, int>& p) { */
        /*         return sum + p.second; */
        /*         }); */
        /* cout << "ans:" << total_sum << endl; */
        /* cout << total_sum << endl; */
        cout << rp->second - lp->second << endl;
        /* cout << "ans:" << en - st << endl; */
#endif
    }
}
