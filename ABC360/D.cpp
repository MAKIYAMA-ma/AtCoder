#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    string s;

    cin >> n >> t;
    cin >> s;

    vector<pair<int, int>> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x.at(i).first;
        x.at(i).second = (s[i] - '0');
    }
    sort(x.begin(), x.end());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(x.at(i).second) {
            for(int j = i+1; j < n; j++) {
                if(!x.at(j).second) {
                    int dis = (x.at(j).first - x.at(i).first);
                    if(dis <= t*2) {
                        ans++;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
