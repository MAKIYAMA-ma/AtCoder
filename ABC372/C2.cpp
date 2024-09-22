#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    ll n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<ll> parts;
    rep(i, n-2) {
        if(s.substr(i, 3) == "ABC") {
            parts.push_back(i);
        }
    }
    /* cout << "DB" << parts.size() << endl; */

    rep(i, q) {
        ll x;
        char c;

        cin >> x >> c;

        ll tp = x-1;
        bool cgd = (s[tp] != c);
        s[tp] = c;

        if(cgd) {
            if(parts.size()) {
                auto near = upper_bound(all(parts), tp);
                if(near != parts.begin()) {
                    near--;
                }
                /* cout << "NEAR:" << tp << " " << *near << endl; */
                if(tp >= *near) {
                    if(tp <= (*near+2)) {
                        // 既存のABCにかぶっている
                        // 破壊されたので削除
                        near = parts.erase(near);
                    } else {
                        // 新規ABCとして追加する場合の追加位置は、nearの次の位置
                        near++;
                    }
                }
#if 1
                for(int j = tp-2; j <= tp; j++) {
                    if(j >= 0) {
                        if(s.substr(j, 3) == "ABC") {
                            parts.insert(near, j);
                            break;
                        }
                    }
                }
#else
                ll tmp = -1;
                switch(c) {
                    case 'A': tmp = tp; break;
                    case 'B': tmp = tp-1; break;
                    case 'C': tmp = tp-2; break;
                }
                if(tmp >= 0) {
                    if(s.substr(tmp, 3) == "ABC") {
                        parts.insert(near, tmp);
                    }
                }
#endif
            } else {
#if 1
                for(int j = tp-2; j <= tp; j++) {
                    if(j >= 0) {
                        if(s.substr(j, 3) == "ABC") {
                            parts.push_back(j);
                            break;
                        }
                    }
                }
#else
                ll tmp = -1;
                switch(c) {
                    case 'A': tmp = tp; break;
                    case 'B': tmp = tp-1; break;
                    case 'C': tmp = tp-2; break;
                }
                if(tmp >= 0) {
                    if(s.substr(tmp, 3) == "ABC") {
                        parts.push_back(tmp);
                    }
                }
#endif
            }
        }
        /* cout << "DB:" << s << endl; */
        /* rep(k, parts.size()) cout << parts.at(k) << " "; cout << endl; */
        cout << parts.size() << endl;
    }
}
