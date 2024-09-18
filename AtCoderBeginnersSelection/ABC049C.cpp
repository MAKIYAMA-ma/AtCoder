#include <bits/stdc++.h>
using namespace std;

vector<string> dict = {"dream", "dreamer", "erase", "eraser"};

bool judge(string_view str) {
    vector<bool> ans;

    if(str == "") {
        return true;
    }

    for(auto d : dict) {
        if(str.compare(0, d.size(), d) == 0) {
            string_view sv(str.data()+d.size(), str.size()-d.size());
            ans.push_back(judge(sv));
        }
    }

    for(auto a : ans) {
        if(a) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    string_view v(s.data(), s.size());

    if(judge(v)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
