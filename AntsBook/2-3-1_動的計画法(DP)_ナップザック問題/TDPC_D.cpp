#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

double prob (int n, int d) {
    double ans = 0;
    if (n == 1) {
        switch(d) {
            case 1:
                {
                    ans = 1.0;
                }
                break;
            case 2:
                {
                    ans = 1.0/2;
                }
                break;
            case 3:
                {
                    ans = 1.0/3;
                }
                break;
            case 4:
            case 5:
            case 6:
                {
                    ans = 1.0/6;
                }
                break;
        }
    } else {
        ans += prob(n-1, d)/6;  // 1の場合
        if(d % 2) {
            ans += prob(n-1, d)/6;
        } else {
            ans += prob(n-1, d/2)/6;
        }
        if(d % 3) {
            ans += prob(n-1, d)/6;
        } else {
            ans += prob(n-1, d/3)/6;
        }
        if((d % 4) == 0) {
            ans += prob(n-1, d/4)/6;
        } else if((d % 2) == 0) {
            ans += prob(n-1, d/2)/6;
        } else {
            ans += prob(n-1, d)/6;
        }
        if(d % 5) {
            ans += prob(n-1, d)/6;
        } else {
            ans += prob(n-1, d/5)/6;
        }
        if((d % 6) == 0) {
            ans += prob(n-1, d/6)/6;
        } else if((d % 3) == 0) {
            ans += prob(n-1, d/3)/6;
        } else if((d % 2) == 0) {
            ans += prob(n-1, d/2)/6;
        } else {
            ans += prob(n-1, d)/6;
        }
    }
    return ans;
}

int main() {
    int n;
    ll d;
    cin >> n >> d;

    cout << prob(n, d) << endl;
}
