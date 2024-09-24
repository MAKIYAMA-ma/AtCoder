// LUOGU_RID: 175553932
#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using P = pair<int, int>;

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

/* 参考1 */
/* sectree(atcoder)を使い、漸進的にカウントしている？？ */
/* int func0 (void){ */
/*     int n; */
/*     cin >> n; */

/*     vector<P> ps; */
/*     rep(i, n) { */
/*         int w, h; */
/*         cin >> w >> h; */
/*         ps.emplace_back(w, h); */
/*     } */
/*     ranges::sort(ps, [](P a, P b) { */
/*             if (a.first == b.first) return a.second > b.second; */
/*             return a.first < b.first; */
/*             }); */

/*     const int MX = 100005; */
/*     segtree<int, op, e> t(MX); */
/*     rep(i, n) { */
/*         int h = ps[i].second; */
/*         int lis = t.prod(0, h)+1; */
/*         t.set(h, lis); */
/*     } */

/*     int lis = t.all_prod(); */
/*     cout << lis << endl; */

/*     return 0; */
/* } */

/* 参考2 */
/* h昇順,w降順ソートで処理 */
void func1 (void){
    int N;
    cin >> N;
    vector<pair<int, int>> X(N);
    rep(i, N) {
        int w, h;
        cin >> w >> h;
        X[i].first = w;
        X[i].second = h;
    }

    sort(X.begin(), X.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return (a.first < b.first) || (a.first == b.first && a.second > b.second);
            });
    vector<int> dp(N, 1000000);
    rep(i, N) {
        *lower_bound(dp.begin(), dp.end(), X[i].second) = X[i].second;
        cout << "L:";
        rep(j, N) {
            cout << dp.at(j) << " ";
        }
        cout << endl;
    }
    cout << lower_bound(dp.begin(), dp.end(), 1000000) - dp.begin() << endl;
}

int main() {
    func1();
}
