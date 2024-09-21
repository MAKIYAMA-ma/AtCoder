#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> parts;
    rep(i, n-2) {
        if(s[i] == 'A') {
            if(s[i+1] == 'B' && s[i+2] == 'C') {
                parts.push_back(i);
            }
        }
    }
    /* cout << "DB" << parts.size() << endl; */

    rep(i, q) {
        int x;
        char c;

        cin >> x >> c;

        /* cout << "DB" << x << " " << s.length() << endl; */

        auto near = upper_bound(all(parts), x-1);
        if(near != parts.begin()) {
            near--;
        }
        if(near != parts.end()) {
            if(((x-1) > ((*near) + 2))) {
                switch(c) {
                    case 'A':
                        if(x<n-1 && s[x]=='B' && s[x+1]=='C') {
                            parts.push_back(x-1);
                            sort(all(parts));
                        }
                        break;
                    case 'B':
                        if(x>=2 && s[x-2]=='A' && s[x]=='C') {
                            parts.push_back(x-2);
                            sort(all(parts));
                        }
                        break;
                    case 'C':
                        if(x>=3 && s[x-3]=='A' && s[x-2]=='B') {
                            parts.push_back(x-3);
                            sort(all(parts));
                        }
                        break;
                }
                cout << parts.size() << endl;
                s[x-1] = c;
            } else {
                /* cout << "DBG" << (x-1) << " " << *near << endl; */
                if(s[x-1] != c) {
                    parts.erase(near);
                    switch(c) {
                        case 'A':
                            if(x<n-1 && s[x]=='B' && s[x+1]=='C') {
                                parts.push_back(x-1);
                                sort(all(parts));
                            }
                            break;
                        case 'B':
                            if(x>=2 && s[x-2]=='A' && s[x]=='C') {
                                parts.push_back(x-2);
                                sort(all(parts));
                            }
                            break;
                        case 'C':
                            if(x>=3 && s[x-3]=='A' && s[x-2]=='B') {
                                parts.push_back(x-3);
                                sort(all(parts));
                            }
                            break;
                    }
                    cout << parts.size() << endl;
                    s[x-1] = c;
                } else {
                    cout << parts.size() << endl;
                }
            }
        } else {
            switch(c) {
                case 'A':
                    if(x<n-1 && s[x]=='B' && s[x+1]=='C') {
                        parts.push_back(x-1);
                        sort(all(parts));
                    }
                    break;
                case 'B':
                    if(x>=2 && s[x-2]=='A' && s[x]=='C') {
                        parts.push_back(x-2);
                        sort(all(parts));
                    }
                    break;
                case 'C':
                    if(x>=3 && s[x-3]=='A' && s[x-2]=='B') {
                        parts.push_back(x-3);
                        sort(all(parts));
                    }
                    break;
            }
            cout << parts.size() << endl;
            s[x-1] = c;
        }
    }
}
