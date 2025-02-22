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
using vs = vector<string>;

using vi2 = vector<vi>;
using vl2 = vector<vl>;
using vpi2 = vector<vpi>;
using vpl2 = vector<vpl>;
using vb2 = vector<vb>;
using vd2 = vector<vd>;
using vm2 = vector<vm>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n)-1; i >= 0; i--)
#define srep(i, s, n) for(ll i = (ll)(s); i < (ll)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()
#define Yes(cond) cout << ((cond) ? "Yes" : "No") << endl;
#define YES(cond) cout << ((cond) ? "YES" : "NO") << endl;
#define PrintD(val) cout << fixed << setprecision(15) << (val) << endl;
#define Def(n) ll n; cin >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];
#define Def2A(a, b, n) vl a(n); vl b(n); rep(i, n) cin >> a[i] >> b[i];
#define DefPA(a, n) vl a(n); rep(i, n) cin >> a[i].first >> a[i].second;

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

void WarshallFloyd(vector<vector<unordered_set<string>>> &lb) {
    rep(k, lb.size()) {
        rep(i, lb.size()) {
            rep(j, lb.size()) {
                if(i == j) continue;
                unordered_set<string> tmp;
                for(auto si : lb[i][k]) {
                    for(auto sj : lb[k][j]) {
                        if((si+sj).length() <= 2*lb.size()) tmp.insert(si+sj);
                    }
                }
                for(auto s : tmp) lb[i][j].insert(s);
            }
        }
    }
}

bool isCycle(string s) {
    ll l{0}, r{s.length()-1};
    bool ans{true};
    while(l < r) {
        if(s[l] != s[r]) {
            ans = false;
            break;
        }
        l++; r--;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    vs c(n);
    rep(i, n) cin >> c[i];

    vector<vector<unordered_set<string>>> lb(n, vector<unordered_set<string>>(n));
    rep(i, n) {
        rep(j, n) {
            if(c[i][j] != '-') lb[i][j].insert(string(1, c[i][j]));
        }
    }
    WarshallFloyd(lb);
    /* rep(i, n) { */
    /*     rep(j, n) { */
    /*         cout << "----" << endl; */
    /*         for(auto s : lb[i][j]) cout << s << endl; */
    /*     } */
    /* } */
    vl2 ans(n, vl(n, MAXLL));
    rep(i, n) {
        rep(j, n) {
            if(i == j) {
                ans[i][j] = 0;
            } else if(c[i][j] != '-'){
                ans[i][j] = 1;
            } else {
                for(auto sij : lb[i][j]) {
                    if(ans[i][j] > sij.length() && isCycle(sij)) {
                        ans[i][j] = (ll)sij.length();
                    }
                }
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            if(ans[i][j] == MAXLL) {
                cout << -1;
            } else {
                cout << ans[i][j];
            }
            cout << " ";
        }
        cout << endl;
    }
}
