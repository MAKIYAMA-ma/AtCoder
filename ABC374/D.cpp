#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()


int main() {
    int n, s, t;
    cin >> n >> s >> t;

    vector<int> a(n), b(n), c(n), d(n);
    rep(i, n) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    }

    /* 端点間の距離が最小になるようにしたい */
    /* 各点を一度のみ使って一本に結ぶ。木でもだめ。 */
    /* 00の扱い */
    /* 00はどこかに接続必須 */
    /* 最短のところを順に繋ぐと後に大きいのが残る可能性 */
    /* かといって00は別枠とも行かない */
    /* 実は探索だったのか？？？ */
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>,
        greater<pair<double, pair<int, int>>>> dist;

    rep(i, n) {
        rep(j, n) {
            if(i == j) {
                continue;
            }
            double tmp = sqrt(pow(a.at(i) - a.at(j), 2) + pow((b.at(i) - b.at(j)), 2));
            dist.push(make_pair(tmp, make_pair(i, j)));
            tmp = sqrt(pow(a.at(i) - c.at(j), 2) + pow((b.at(i) - d.at(j)), 2));
            dist.push(make_pair(tmp, make_pair(i, n+j)));
            tmp = sqrt(pow(c.at(i) - a.at(j), 2) + pow((d.at(i) - b.at(j)), 2));
            dist.push(make_pair(tmp, make_pair(n+i, j)));
            tmp = sqrt(pow(c.at(i) - c.at(j), 2) + pow((d.at(i) - d.at(j)), 2));
            dist.push(make_pair(tmp, make_pair(n+i, n+j)));
        }
        /* double tmp = sqrt(pow(a.at(i), 2) + pow(b.at(i), 2)); */
        /* dist.push(make_pair(tmp, make_pair(n*2, i))); */
        /* tmp = sqrt(pow(c.at(i), 2) + pow(d.at(i), 2)); */
        /* dist.push(make_pair(tmp, make_pair(n*2, n+i))); */
    }

    double timet = 0;
    rep(i, n) {
        timet += sqrt(pow(a.at(i) - c.at(i), 2) + pow((b.at(i) - d.at(i)), 2));
    }

    double time = 0;
    vector<bool> used(n*2+1, false);
    int cnt = 0;
    while(!dist.empty()) {
        auto tm = dist.top().first;
        auto pt1 = dist.top().second.first;
        auto pt2 = dist.top().second.second;
        dist.pop();

        if(used.at(pt1) || used.at(pt2)) {
            continue;
        }
        /* cout << "DB1:" << tm << endl; */
        /* cout << "DB2:" << pt1 << " " << pt2 << endl; */
        time += tm;
        used.at(pt1) = true;
        used.at(pt2) = true;
        cnt += 2;
        if(cnt >= (n*2-2)) {
            break;
        }
        /* if(cnt >= (n*2-1)) { */
        /*     break; */
        /* } else if(cnt >= (n*2-2) && !used.at(n*2)) { */
        /*     break; */
        /* } */
    }
    double st = -1;
    rep(i, n*2) {
        if(!used.at(i)) {
            double tmp;
            if(i < n) {
                tmp = sqrt(pow(a.at(i), 2) + pow(b.at(i), 2));
            } else {
                tmp = sqrt(pow(c.at(i-n), 2) + pow(d.at(i-n), 2));
            }
            if(st < 0) {
                st = tmp;
            } else {
                st = min(st, tmp);
            }
        }
    }
    time += st;
    /* if(!used.at(n*2)) { */
    /*     while(!dist.empty()) { */
    /*         auto tm = dist.top().first; */
    /*         auto pt1 = dist.top().second.first; */
    /*         auto pt2 = dist.top().second.second; */
    /*         dist.pop(); */
    /*         if(pt1 == n*2) { */
    /*             time += tm; */
    /*             break; */
    /*         } */
    /*     } */
    /* } */
    /* cout << "t:" << timet << endl; */
    /* cout << "s:" << time << endl; */
    cout << fixed << setprecision(10) << time/s + timet/t << endl;
}
