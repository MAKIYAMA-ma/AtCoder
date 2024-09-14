#include <bits/stdc++.h>
using namespace std;

void pr_lst(vector<tuple<string, int, int>> &l)
{
    cout << "------------------" << endl;
    for(auto t : l) {
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
    }
    cout << "------------------" << endl;
}

int main() {
    int n;
    cin >> n;

    vector<tuple<string, int, int>> lst(n);
    for(int i = 0; i < n; i++) {
        cin >> get<0>(lst.at(i)) >> get<1>(lst.at(i));
        get<2>(lst.at(i)) = i+1;
    }
    /* pr_lst(lst); */
    sort(lst.begin(), lst.end(), [](const std::tuple<std::string, int, int>& a, const std::tuple<std::string, int, int>& b) {
        if (std::get<0>(a) == std::get<0>(b)) {
            return std::get<1>(a) > std::get<1>(b);
        }
        return std::get<0>(a) < std::get<0>(b);
    });
    /* pr_lst(lst); */
    for(auto t : lst) {
        cout << get<2>(t) << endl;
    }
}
