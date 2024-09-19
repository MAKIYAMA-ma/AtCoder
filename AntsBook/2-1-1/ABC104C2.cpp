#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int d, g;
    cin >> d >> g;

    vector<int> p(d);
    vector<int> c(d);

    for(int i = 0; i < d; i++) {
        cin >> p.at(i) >> c.at(i);
    }

    int ans = -1;
    // どの点数の問題を完答するか、ビット全探索
    for(int cp = 0; cp < (1 << d); cp++) {
        int score = 0;
        int cnt = 0;

        // 完答した問題の点数合算
        for(int i = 0; i < d; i++) {
            if(cp & (1 << i)) {
                score += (p.at(i)*100*(i+1) + c.at(i));
                cnt += p.at(i);
            }
        }
        // ここまででGを超えていないなら、高得点問題から順に追加
        // ただし、完答はしない範囲（完答するのは別途探索される）
        if(score < g) {
            for(int i = d-1; i >= 0; i--) {
                if(score >= g) {
                    break;
                }
                if(cp & (1 << i)) {
                    continue;
                } else {
                    int nd = (g-score)/(100*(i+1));
                    // 端数があるならもう一問必要
                    if((g-score)%(100*(i+1))) {
                        nd++;
                    }
                    int tmp = min(p.at(i)-1, nd);
                    score += tmp * 100 * (i+1);
                    cnt += tmp;
                }
            }
        }
        if(score >= g) {
            if(ans < 0) {
                ans = cnt;
            } else {
                ans = min(ans, cnt);
            }
        }
    }

    cout << ans << endl;
}
