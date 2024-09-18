#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    vector<vector<int>> w(n);

    for(int i = 0; i < n; i++) {
        cin >> a.at(i);
    }
    for(int i = 0; i < n; i++) {
        int wt;
        cin >> wt;
        w.at(a.at(i)-1).push_back(wt);
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        if(w.at(i).size() > 1) {
            int max = *max_element(begin(w.at(i)), end(w.at(i)));
            long long sum = accumulate(w.at(i).begin(), w.at(i).end(), 0);
            ans += (sum - max);
        }
    }

    cout << ans << endl;
}
