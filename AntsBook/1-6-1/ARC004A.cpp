#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i);
    }

    float ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            float tmp = sqrt(pow(x.at(i) - x.at(j), 2) + pow(y.at(i) - y.at(j), 2));
            if(ans < tmp) {
                ans = tmp;
            }
        }
    }

    cout << ans << endl;
}
