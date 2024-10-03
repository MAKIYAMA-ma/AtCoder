#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

/* 39 ms	4540 KB */
void func1() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n, pair<int, int>());
    vector<pair<int, int>> b(n, pair<int, int>());
    rep(i, n) {
        cin >> a.at(i).first;
        a.at(i).second = i;
    }
    sort(all(a));
    b.at(0).first = 1;
    b.at(0).second = a.at(0).second;
    rep(i, n-1) {
        b.at(i+1).second = a.at(i+1).second;
        if(a.at(i).first < a.at(i+1).first) {
            b.at(i+1).first = b.at(i).first+1;
        } else {
            b.at(i+1).first = b.at(i).first;
        }
    }
    sort(all(b), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
            });
    rep(i, n) {
        cout << b.at(i).first << " ";
    }
    cout << endl;
}

/* 39 ms	3940 KB */
void func2() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    vector<int> b(n, 0);
    rep(i, n) {
        cin >> a.at(i);
        b.at(i) = a.at(i);
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());

    rep(i, n) {
        int ind = lower_bound(all(a), b.at(i)) - a.begin();
        b.at(i) = ind+1;
    }
    rep(i, n) {
        cout << b.at(i) << " ";
    }
    cout << endl;
}

int main() {
    func2();
}
