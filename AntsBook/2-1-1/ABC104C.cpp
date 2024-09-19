#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> p;
vector<int> c;

bool judge(int n, int tgt, int &minv) {
    /* cout << "CHK:" << n << " " << tgt << endl; */
    if(tgt <= 0) {
        minv = 0;
        /* cout << "DBG1" << endl; */
        return true;
    }
    if(n >= p.size()) {
        /* cout << "DBG2" << endl; */
        return false;
    }

    int m = -1;
    for(int i = 0; i <= p.at(n); i++) {
        int rest = tgt - (i*(n+1)*100);
        int ms;
        if (i == p.at(n)) {
            rest -= c.at(n);
        }
        if(judge(n+1, rest, ms)) {
            if((m == -1) || (m > (i+ms))) {
                m = i+ms;
            }
        }
    }
    minv = m;
    if(m >= 0) {
        /* cout << "DBG3" << endl; */
        return true;
    } else {
        /* cout << "DBG4" << endl; */
        return false;
    }
}

int main() {
    int d, g;
    cin >> d >> g;

    for(int i = 0; i < d; i++) {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
        cin >> tmp;
        c.push_back(tmp);
    }

    int ans = 0;
    if(!judge(0, g, ans)) {
        /* cout << "FAIL" << endl; */
    }
    cout << ans << endl;
}
