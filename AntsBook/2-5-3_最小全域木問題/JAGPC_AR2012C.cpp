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
    while(true) {
        int n, m;
        cin >> n >> m;

        if(n == 0 && m == 0) {
            continue;
            /* return 0; */
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>> q;
        rep(i, m) {
            int s, t, c;
            cin >> s >> t >> c;
            s--;
            t--;
            q.emplace(make_pair(c, make_pair(s, t)));
        }

        UnionFind con;
        con.init(n);
        int cnt = 0;
        vector<int> cstl;
        while(!q.empty()) {
            auto cst = q.top().first;
            auto p1 = q.top().second.first;
            auto p2 = q.top().second.second;
            q.pop();

            if(con.same(p1, p2)) {
                continue;
            }
            con.merge(p1, p2);
            cstl.push_back(cst);
            cnt++;
            if(cnt >= n-1) {
                break;
            }
        }
        cout << cstl.at(n/2 - 1) << endl;
    }
}
