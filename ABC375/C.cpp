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

void proc(vector<vector<int>> &dr, vector<vector<int>> &ar, int n, int t) {
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
}

int main() {
    int n;
    cin >> n;

    vector<vector<vector<int>>> a(4, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, n) {
            if(s[j] == '#') {
                a.at(0).at(i+1).at(j+1) = 1;
            } else {
                a.at(0).at(i+1).at(j+1) = 0;
            }
        }
    }

    for(int i = 1; i < 4; i++) {
        proc(a.at(i), a.at(i-1), n, i);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int lvl = min(min(i, n-i+1), min(j, n-j+1)) % 4;
            if(a.at(lvl).at(i).at(j)) {
                cout << '#';
            } else {
                cout << '.';
            }
        }
        cout << endl;
    }
}
