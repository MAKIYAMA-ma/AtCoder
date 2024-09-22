#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;
    n = 1000-n;

    vector<int> coin = {500, 100, 50, 10, 5, 1};
    int num = 0;

    rep(i, 6) {
        while(n >= coin.at(i)) {
            /* cout << coin.at(i) << endl; */
            num++;
            n -= coin.at(i);
        }
    }

    cout << num << endl;
}
