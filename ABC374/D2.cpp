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

    vector<vector<double>> dist(n*2, vector<double>(n*2, -1));
    vector<double> start(n*2);

    rep(i, n) {
        for(int j = i+1; j < n; j++) {
            if(dist.at(i).at(j) < 0) {
                dist.at(i).at(j) = sqrt(pow(a.at(i) - a.at(j), 2) + pow((b.at(i) - b.at(j)), 2));
                dist.at(j).at(i) = dist.at(i).at(j);
            }
            if(dist.at(i).at(n+j) < 0) {
                dist.at(i).at(n+j) = sqrt(pow(a.at(i) - c.at(j), 2) + pow((b.at(i) - d.at(j)), 2));
                dist.at(n+j).at(i) = dist.at(i).at(n+j);
            }
            if(dist.at(n+i).at(j) < 0) {
                dist.at(n+i).at(j) = sqrt(pow(c.at(i) - a.at(j), 2) + pow((d.at(i) - b.at(j)), 2));
                dist.at(j).at(n+i) = dist.at(n+i).at(j);
            }
            if(dist.at(n+i).at(n+j) < 0) {
                dist.at(n+i).at(n+j) = sqrt(pow(c.at(i) - c.at(j), 2) + pow((d.at(i) - d.at(j)), 2));
                dist.at(n+j).at(n+i) = dist.at(n+i).at(n+j);
            }
        }
        start.at(i) = sqrt(pow(a.at(i), 2) + pow(b.at(i), 2));
        start.at(n+i) = sqrt(pow(c.at(i), 2) + pow(d.at(i), 2));
    }

    vector<int> od(n);
    double times = 1e18;
    rep(i, n) {
        od.at(i) = i;
    }
    do {
        /* cout << "------------" << endl; */
        /* rep(i, n) { */
        /*     cout << od.at(i) << " "; */
        /* } */
        /* cout << endl; */
        /* cout << "------------" << endl; */
        rep(mk, (1 << n)) {
            int sm = (mk & 0x01);
            int se = od.at(0);
            double tmpt = start.at(n*sm + se);
            /* cout << "start --> " << n*sm + se; */
            rep(i, n-1) {
                int m = (mk & (1 << i)) ? 0 : 1;
                int e = od.at(i);
                int nm = (mk & (1 << (i+1))) ? 1 : 0;
                int ne = od.at(i+1);
                tmpt += dist.at(n*m + e).at(n*nm + ne);
                /* cout << "(" << n*m + e << " -->" << n*nm + ne << ")"; */
            }
            /* cout << tmpt << endl; */
            times = min(times, tmpt);
        }
        /* cout << "------------" << endl; */
    } while (next_permutation(all(od)));

    double timet = 0;
    rep(i, n) {
        timet += sqrt(pow(a.at(i) - c.at(i), 2) + pow((b.at(i) - d.at(i)), 2));
    }

    cout << fixed << setprecision(10) << times/s + timet/t << endl;
}
