#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

vector<vector<int>> proc(vector<vector<int>> &ar, int n, int t) {
    vector<vector<int>> dr(n+1, vector<int>(n+1, 0));

    for(int x = t; x <= n+1-t; x++) {
        for(int y = t; y <= n+1-t; y++) {
            dr.at(y).at(n+1-x) = ar.at(x).at(y);
        }
    }
    /* rep(x, n+1) { */
    /*     rep(y, n+1) { */
    /*         if((x >= t) && (x <= n+1-t) && (y >= t) && (y <= n+1-t)) { */
    /*             dr.at(y).at(n+1-x) = ar.at(x).at(y); */
    /*         } else { */
    /*             dr.at(x).at(y) = ar.at(x).at(y); */
    /*         } */
    /*     } */
    /* } */
    /* cout << t << "------------" << endl; */
    /* for(int i = 1; i <= n; i++) { */
    /*     for(int j = 1; j <= n; j++) { */
    /*         if(ar.at(i).at(j)) { */
    /*             cout << '#'; */
    /*         } else { */
    /*             cout << '.'; */
    /*         } */
    /*     } */
    /*     cout << "   "; */
    /*     for(int j = 1; j <= n; j++) { */
    /*         if(dr.at(i).at(j)) { */
    /*             cout << '#'; */
    /*         } else { */
    /*             cout << '.'; */
    /*         } */
    /*     } */
    /*     cout << endl; */
    /* } */
    /* cout << "------------" << endl; */
    return dr;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, n) {
            if(s[j] == '#') {
                a.at(i+1).at(j+1) = 1;
            } else {
                a.at(i+1).at(j+1) = 0;
            }
        }
    }

    vector<vector<int>> d(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n/2; i++) {
        a = proc(a, n, i);
        for(int y = i; y <= n+1-i; y++) {
            d.at(i).at(y) = a.at(i).at(y);
            d.at(n+1-i).at(y) = a.at(n+1-i).at(y);
        }
        for(int x = i; x <= n+1-i; x++) {
            d.at(x).at(i) = a.at(x).at(i);
            d.at(x).at(n+1-i) = a.at(x).at(n+1-i);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d.at(i).at(j)) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}
