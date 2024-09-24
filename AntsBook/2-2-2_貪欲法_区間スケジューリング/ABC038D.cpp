#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

void func0(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> wh(n);
    rep(i, n) {
        cin >> wh.at(i).first >> wh.at(i).second;
    }
    sort(all(wh));

    /* hが同じ物事にwを昇順に並べたデータ構造に変換する */
    vector<vector<int>> whl;
    int ti = 0;
    int i = 0;
    while(i < n) {
        vector<int> tmp;
        ti = wh.at(i).first;
        while(ti == wh.at(i).first) {
            ti = wh.at(i).first;
            tmp.push_back(wh.at(i++).second);
            if(i >= n) {
                break;
            }
        }
        whl.push_back(tmp);
    }
    /* cout << "-------" << endl; */
    /* rep(i, whl.size()) { */
    /*     rep(j, whl.at(i).size()) { */
    /*         cout << whl.at(i).at(j) << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "-------" << endl; */

    /* 最長増加部分列(LIS)の長さ確認アルゴリズムを実行する */
    /* Lに昇順に並べていき、小さい値vが登場したら、Lの中でv以上の最小値をvにすり替える。 */
    /* これを繰り返した結果のLの長さがLISの長さとなる */
    int ans = 0;
    vector<int> l(n, pow(10, 5)+1);
    rep(i, whl.size()) {
        vector<int> tmp(whl.at(i).size(), 0);
        /* ただし、Hが等しいものを同時に採用はできないため、同一のHの各箱について、Lのどの位置に入るかを判定 */
        /* そのうえで、同じ位置にくる場合はよりWが小さいものを採用する。 */
        rep(j, whl.at(i).size()) {
            int tgt = whl.at(i).at(j);
            tmp.at(j) = lower_bound(all(l), tgt) - l.begin();
        }
        for(int j = tmp.size()-1; j >= 0; j--) {
            l.at(tmp.at(j)) = whl.at(i).at(j);
            ans = max(ans, tmp.at(j));
            /* cout << "L:"; */
            /* rep(j, n) { */
            /*     cout << l.at(j) << " "; */
            /* } */
            /* cout << endl; */
        }
    }

    cout << ans + 1 << endl;
}

/* 同一wごとのvectorとか用意しなくてもこれで十分 */
void func1(void) {
    int n;
    cin >> n;

    vector<pair<int, int>> wh(n);
    rep(i, n) {
        int w, h;
        cin >> w >> h;
        wh.at(i).first = w;
        wh.at(i).second = -h;
    }
    sort(all(wh));

    /* 最長増加部分列(LIS)の長さ確認アルゴリズムを実行する */
    /* Lに昇順に並べていき、小さい値vが登場したら、Lの中でv以上の最小値をvにすり替える。 */
    /* これを繰り返した結果のLの長さがLISの長さとなる */
    int ans = 0;
    vector<int> l(n, pow(10, 5)+1);
    rep(i, n) {
        int tgt = -wh.at(i).second;
        auto next = lower_bound(all(l), tgt);
        if(next != l.end()) {
            *next = tgt;
            ans = max(ans, (int)(next - l.begin()));
        }
    }

    cout << ans + 1 << endl;
}

int main() {
    func1();
}
