#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> card(n);
    for(int i = 0; i < n; i++) {
        cin >> card.at(i);
    }
    sort(card.begin(), card.end());

    vector<long long> nums;
    do {
        long long num = 0;
        for(int i = 0; i < k; i++) {
            int c = card.at(i);
            if(c >= 10) {
                num *= 100;
            } else {
                num *= 10;
            }
            num += c;
        }
        nums.push_back(num);
    } while (next_permutation(card.begin(), card.end()));

    /* cout << "--------" << endl; */
    /* for(int i = 0; i < nums.size(); i++) { */
    /*     cout << nums.at(i) << endl; */
    /* } */
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    /* cout << "--------" << endl; */
    /* for(int i = 0; i < nums.size(); i++) { */
    /*     cout << nums.at(i) << endl; */
    /* } */
    cout << nums.size() << endl;
}
