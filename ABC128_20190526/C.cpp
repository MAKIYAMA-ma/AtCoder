#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    unsigned p = 0;

    cin >> n >> m;
    vector<unsigned> s(m);

    for(int i = 0; i < m; i++) {
        int k;
        unsigned sl = 0;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int sp;
            cin >> sp;
            sl |= (1 << (sp-1));
        }
        s.at(i) = sl;
    }
    p = 0;
    for(int i = 0; i < m; i++) {
        int pp;
        cin >> pp;
        if(pp) {
            p |= (1 << i);
        }
    }

    // cout << "p:" << bitset<16>(p) << endl;

    int count = 0;
    for(unsigned sw = 0; sw < (1<<n); sw++) {
        bool ok = true;
        // cout << "sw:" << bitset<16>(sw) << endl;
        for(int i = 0; i < m; i++) {
            int pc = __builtin_popcount(s.at(i) & sw);
            // cout << "p" << i << ":" << pc << ":" << ((p>>i)&0x1) << endl;
            if(pc%2 != ((p>>i)&0x1)) {
                ok = false;
                break;
            }
        }
        if(ok) {
            count++;
        }
    }

    cout << count << endl;
}
