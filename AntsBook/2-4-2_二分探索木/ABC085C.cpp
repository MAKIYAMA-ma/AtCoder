#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n;
    cin >> n;
    set<int> dl;
    rep(i, n) {
        int d;
        cin >> d;
        dl.insert(d);
    }

    cout << dl.size() << endl;
}
