#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

class UnionFind {
    public:
        vector<int> data;

        void init(int n) {
            data.resize(n, -1);
        }

        int root(int idx) {
            if(data.at(idx) == -1) {
                return idx;
            } else {
                // 深さ圧縮
                return (data.at(idx) = root(data.at(idx)));
            }
        }

        void merge(int a, int b) {
            int ar, br;

            if(a == b) {
                return;
            }

            ar = root(a);
            br = root(b);
            if(ar != br) {
                data.at(br) = ar;
            }
        }

        bool same(int a, int b) {
            int ar, br;

            if(a == b) {
                return true;
            }

            ar = root(a);
            br = root(b);

            return (ar == br);
        }
};

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> xe(n, pair<int, int>());
    vector<pair<int, int>> ye(n, pair<int, int>());
    rep(i, n) {
        cin >> xe.at(i).first >> ye.at(i).first;
        xe.at(i).second = i;
        ye.at(i).second = i;
    }
    sort(all(xe));
    sort(all(ye));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>> eq;
    rep(i, n-1) {
        eq.emplace(make_pair(xe.at(i+1).first - xe.at(i).first,
                    make_pair(xe.at(i).second, xe.at(i+1).second)));
        eq.emplace(make_pair(ye.at(i+1).first - ye.at(i).first,
                    make_pair(ye.at(i).second, ye.at(i+1).second)));
    }
    UnionFind con;
    ll ans = 0;
    int fin = 0;
    con.init(n);

    while(fin < n-1) {
        auto edge = eq.top();
        auto pt1 = edge.second.first;
        auto pt2 = edge.second.second;
        auto cost = edge.first;
        eq.pop();

        if(con.same(pt1, pt2)) {
            continue;
        } else {
            /* cout << "DB:" << pt1 << " " << pt2 << " " << cost << endl; */
            con.merge(pt1, pt2);
            ans += cost;
            fin++;
        }
    }
    cout << ans << endl;
}
