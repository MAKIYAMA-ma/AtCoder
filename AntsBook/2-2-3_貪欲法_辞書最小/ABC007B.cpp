#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

int main() {
    string a;
    cin >> a;

    if(a.length() > 1) {
        /* 2文字以上あるなら末尾を消す */
        cout << a.erase(a.length()-1) << endl;
        return 0;
    } else {
        /* 1文字なら、aでないならaを返す */
        if(a[0] != 'a') {
            cout << 'a' << endl;
            return 0;
        }
    }
    /* 'a'が来たので答えがない */
    cout << -1 << endl;
}
