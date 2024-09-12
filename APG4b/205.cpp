#include <bits/stdc++.h>
using namespace std;

int count (vector<int> &p, int num)
{
    if(p.at(num) == 0) {
        return 1;
    } else {
        return 1 + count(p, p.at(num));
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n, 0);
    vector<int> c(n, 0);

    for(int i = 1; i < n; i++) {
        cin >> p.at(i);
    }
    for(int i = 1; i < n; i++) {
        c.at(i) = count(p, i);
    }
    int max = *max_element(c.begin(), c.end());
    cout << max << endl;
}
