#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif

using ll = long long;
using ull = unsigned long long;

using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
using vd = vector<double>;
using vm = vector<mint>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
const int MAXI = 1e9;
const int MINI = -1e9;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vi a(t);
    rep(i, t) {
        int tmp;
        cin >> tmp;
        tmp--;
        a[i] = tmp;
    }
#if 1
    vi tate(n, n), yoko(n, n), naname(2, n);
    rep(i, t) {
        int x = a[i]/n;
        int y = a[i] % n;

        /* cout << "DB:" << x << " " << y << endl; */

        tate[x]--;
        yoko[y]--;
        if(x == y) {
            naname[0]--;
        }
        if(x == n-y-1) {
            naname[1]--;
        }
        if(tate[x] == 0 || yoko[y] == 0 || naname[0] == 0 || naname[1] == 0) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
#else
    vector<set<int>> tate(n+1), yoko(n+1), naname(2);
    rep(i, n) {
        naname[0].insert(i+1);
        naname[1].insert(i+1);
        rep(j, n) {
            tate[i+1].insert(j+1);
            yoko[i+1].insert(j+1);
        }
    }
    rep(i, t) {
        int x = a[i]/n + 1;
        int y = a[i] % n;

        if(y == 0) {
            y = n;
            x--;
        }

        tate[x].erase(y);
        yoko[y].erase(x);
        if(x == y) {
            naname[0].erase(x);
        } else if(x == n-y+1) {
            naname[1].erase(x);
        }

        if(tate[x].size() == 0 || yoko[y].size() == 0 || naname[0].size() == 0 || naname[1].size() == 0) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
#endif
}
