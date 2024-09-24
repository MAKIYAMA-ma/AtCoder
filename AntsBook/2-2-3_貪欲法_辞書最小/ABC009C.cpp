#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    vector<char> sc(n);
    rep(i, n) {
        sc.at(i) = s[i];
    }
    sort(all(sc));

#if 1
    /* 辞書順で前から一つずつ確定させていき、それに応じて変化点数を増やしていく */
    /* Kになるまでそれを続ける */
    /* しかしそれだと残り部分の文字が不足するので結局をKをオーバーする */
    /* 残り部分で変更点が最小幾つになるかも管理できないか？ */
    /* 前を決めるのに交換が必要 -> 当然後の文字が減る */
    /* 問題は、前から後に追いやられた文字を使うなら、後の文字の不足分は減らないということ */
    /* 前半の辞書順優先部部分と後のK削減部分を分けて管理 */

    /* 前から順に */
    /* (1) 残りの文字から辞書順先頭を取得 */
    /* (2) 元の文字と異なるならchg++ */
    /* (3-1) 持ってきた文字がpoolにないならchg++ */
    /* (3-2) 持ってきた文字がpoolにあるならpoolからその文字を削除 */
    /* (4) 元の文字はpoolに追加 */
    /* (5) 残り文字から持ってきた文字は削除 */
    /* これを残り文字が無くなるかchg>=Kまで続ける */

    /* TOOD この路線ややこしすぎる */
    /* もっといい方法があるはず */
    vector<char> pool;
    vector<char> ans(n);
    int chg = 0;
    int index = 0;
    while(sc.size()) {
        auto c = sc.at(0);
        if(s[index] == c) {
            // 差し替え不要な場合
            ans.at(index++) = c;
            sc.erase(sc.begin());
        } else {
            if(chg >= k) {
                // 終了
                break;
            } else if(chg <= (k-2)) {
                // 2文字以上余裕がある
                ans.at(index++) = c;
                sc.erase(sc.begin());
                if(pool.size()) {
                    auto pc = lower_bound(all(pool), c);
                    if((pc != pool.end()) && (*pc == c)) {
                        pool.erase(pc);
                        chg++;
                    } else {
                        chg += 2;
                    }
                } else {
                    chg += 2;
                }
                if(sc.size()) {
                    auto pc = lower_bound(all(pool), s[index-1]);
                    if((pc != pool.end()) && (*pc == s[index-1])) {
                        pool.push_back(s[index-1]);
                        sort(all(pool));
                    }
                }
            } else if (chg < k) {
                // 1文字だけ余裕がある
                if(pool.size()) {
                    /* sort(all(pool)); */
                    auto c = pool.at(0);
                    pool.erase(pool.begin());
                    auto pc = lower_bound(all(sc), c);
                    ans.at(index++) = c;
                    if(pc != sc.end()) {
                        sc.erase(pc);
                    }
                    chg++;
                    /* pool.push_back(s[index-1]); */
                    /* sort(all(pool)); */
                }
                break;
            }
        }
        cout << "---------" << endl;
        cout << "chg:" << chg << endl;
        cout << "ans:";
        rep(j, index) {
            cout << ans.at(j);
        }
        cout << endl;

        cout << "sct:";
        rep(j, sc.size()) {
            cout << sc.at(j);
        }
        cout << endl;

        cout << "pol:";
        rep(j, pool.size()) {
            cout << pool.at(j);
        }
        cout << endl;
        cout << "---------" << endl;
    }
    for(int i = index; i < n; i++) {
        auto pc = lower_bound(all(sc), s[i]);
        if((pc != sc.end()) && (*pc == s[i])) {
            ans.at(i) = s[i];
            sc.erase(pc);
        } else {
            ans.at(i) = '?';
        }
    }
    int j = 0;
    for(int i = index; i < n; i++) {
        if(ans.at(i) == '?') {
            ans.at(i) = sc.at(j++);
        }
    }
    rep(j, n) {
        cout << ans.at(j);
    }
    cout << endl;
#else
    /* ソート結果の中から条件を満たすものを探す */
    /* これだとTLE */
    do {
        int chg = 0;
        rep(i, n) {
            if(s[i] != sc.at(i)) {
                chg++;
            }
        }
        if(chg <= k) {
            rep(j, n) {
                cout << sc.at(j);
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(all(sc)));
#endif
}
