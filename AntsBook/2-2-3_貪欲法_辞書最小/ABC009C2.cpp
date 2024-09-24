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
        auto top = sc.at(0);
        /* cout << "TOP:" << top.c << " " << top.op << " " << top.cp << endl; */
        if(s[i] == top.c) {
            // 変更不要
            auto lp = lower_bound(all(used), top.op);
            used.insert(lp, top.op);
            sc.erase(sc.begin());
        } else {
            int need = used.end() - lower_bound(all(used), i);
            /* cout << "PRM:(" << i << ") N:" << need << " C:" << changed << endl; */
            if((need + changed + 1) <= k) {
                // TODO 一度入れ替えた要素は、secondにあるindexと位置が変わっている
                // しかし、最初の位置も覚えておかないと変更回数が算出できない
                char tmp = s[i];
                s[i] = top.c;
                s[top.cp] = tmp;
                /* cout << "CHG:" << i << " " << top.cp << endl; */
                auto lp = lower_bound(all(used), top.op);
                used.insert(lp, top.op);
                auto sp = lower_bound(all(sc), tmp, [](const ST_DATA& a, char c) {
                        return (a.c < c);
                        /* if(a.c == b.c) { return a.op < b.op; } */
                        /* else { return a.c < b.c; } */
                        });
                while((sp->c == tmp) && (sp->cp != i)) sp++;
                /* cout << "SP:" << top.c << " " << top.op << " " << top.cp << endl; */
                sp->cp = top.cp;
                sc.erase(sc.begin());
                changed++;
            } else {
                break;
            }
        }
        /* cout << "DB:" << s << endl; */
    }
    cout << s << endl;
}
