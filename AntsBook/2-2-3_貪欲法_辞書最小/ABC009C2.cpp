#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

typedef struct {
    char c; // 文字
    int op; // 初期位置
    int cp; // 現在位置
} ST_DATA;

int main() {
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    vector<ST_DATA> sc(n);
    rep(i, n) {
        sc.at(i).c = s[i];
        sc.at(i).op = i;
        sc.at(i).cp = i;
    }
    sort(all(sc), [](const ST_DATA& a, const ST_DATA& b) {
            if(a.c == b.c) { return a.op < b.op; }
            else { return a.c < b.c; }
            });

    vector<int> used;
    int changed = 0;
    string ans;

    rep(i, n) {
        /* cout << "*************" << endl; */
        /* rep(j, used.size()) { */
        /*     cout << used.at(j) << " "; */
        /* } */
        /* cout << endl; */
        /* cout << "-------------" << endl; */
        if(sc.size() <= 0) {
            // 一周で二要素削除はないからここは来ないはず
            break;
        }
        auto top = sc.begin();
        /* cout << "TOP:" << top->c << " " << top->op << " " << top->cp << endl; */
        if(s[i] == top->c) {
            // 変更不要
            // 使用済み文字のソート位置に対象文字を積み、残り文字ストックから削除
            auto lp = lower_bound(all(used), top->op);
            used.insert(lp, top->op);
            sc.erase(sc.begin());
        } else {
            // 使用済み文字から、残り文字で必要な最小変更回数を確認。
            // 使用済み及び今使おうとしている文字のうち、元位置indexがiより後の文字の数だけ、
            // 残り文字で文字列を作る際に強制的に変更が発生する。
            int need = used.end() - upper_bound(all(used), i);
            if(top->op > i) {
                need++;
            }
            /* cout << "PRM:(" << i << ") N:" << need << " C:" << changed << endl; */
            /* 残り文字での最低変更数、変更済み回数、今から変更するi番めの文字の分の合計が、 */
            /* i番目の文字を設定する際に必要となる最低変更回数 */
            /* それがK以下ならこの設定が可能 */
            if((need + changed + 1) <= k) {
                char tmp = s[i];
                s[i] = top->c;
                s[top->cp] = tmp;
                /* cout << "CHG:" << i << " " << top->cp << endl; */
                auto lp = lower_bound(all(used), top->op);
                used.insert(lp, top->op);
                auto sp = lower_bound(all(sc), tmp, [](const ST_DATA& a, char c) {
                        return (a.c < c);
                        });
                while((sp->c == tmp) && (sp->cp != i)) sp++;
                /* cout << "SP:" << top->c << " " << top->op << " " << top->cp << endl; */
                sp->cp = top->cp;
                sc.erase(sc.begin());
                changed++;
            } else if((need + changed) <= k) {
                // 変更が一つ増えるのはOK
                // -> opがi以前の文字から、辞書最小の文字をiに入れる。
#if 0
                rep(j, sc.size()) {
                    if(sc.at(j).op <= i) {
                        s[i] = sc.at(j).c;
                        auto lp = lower_bound(all(used), sc.at(j).op);
                        used.insert(lp, sc.at(j).op);
                        sc.erase(sc.begin() + j);
                        changed++;
                        break;
                    }
                }
#else
                // TODO こうするとREになる
                // changed++されないケースがまずいらしいがなぜ？？
                rep(j, sc.size()) {
                    if(sc.at(j).op <= i) {
                        if(s[i] != sc.at(j).c) {
                            changed++;
                            s[i] = sc.at(j).c;
                        }
                        auto lp = lower_bound(all(used), sc.at(j).op);
                        used.insert(lp, sc.at(j).op);
                        sc.erase(sc.begin() + j);
                        break;
                    }
                }
#endif
            } else {
                /* これ以上の入替は無理 */
                // 1) opがi以降のモノはopの位置に入れる(何もしなくてもそうなっている）
                // 2) 残った文字を、空いた場所に辞書順に詰める
                vector<int> ri;
                vector<char> ci;
                for(auto se : sc) {
                    if(se.op < i) {
                        ri.push_back(se.cp);
                        ci.push_back(se.c);
                    }
                }
                sort(all(ri));
                sort(all(ci));
                rep(j, ri.size()) {
                    s[ri.at(j)] = ci.at(j);
                }
                break;
            }
        }
        /* cout << "DB:" << s << endl; */
    }
    cout << s << endl;
}
