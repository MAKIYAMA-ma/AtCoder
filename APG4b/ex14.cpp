#include <bits/stdc++.h>
using namespace std;

int main() {
    /* vector<int> vec = {2, 5, 1, 4, 3}; */
    /* sort(&vec.at(1), &vec.at(4)); */

    /* for (auto v = vec.begin(); v != vec.end(); v++) { */
    /*     cout << *v << endl; */
    /* } */
    int a, b, c;
    int mn, mx;
    cin >> a >> b >> c;

    mn = min(min(a, b), c);
    mx = max(max(a, b), c);
    cout << mx - mn << endl;
}
