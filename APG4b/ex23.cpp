#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> al;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(al.count(a)) {
            al[a]++;
        } else {
            al[a] = 1;
        }
    }

    auto ma = max_element(al.begin(), al.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) -> bool {
            return a.second < b.second;
        });

    cout << ma->first << " " << ma->second << endl;
}
