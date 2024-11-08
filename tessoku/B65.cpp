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
#define Def(n) ll n; cin >> n;
#define DefA(a, n) vl a(n); rep(i, n) cin >> a[i];

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


ll check(vl2 &tree, int tgt, vl &lvl) {
    if(lvl[tgt] >= 0) {
        return lvl[tgt];
    }
    lvl[tgt] = 0;
    for(auto c : tree[tgt]) {
        lvl[tgt] = max(lvl[tgt], check(tree, c, lvl)+1);
    }
    return lvl[tgt];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(t);
    t--;

    // tと関係がある社員は全てtの部下
    // すると、その各部下の関係者はt以外が全て部下。。。という感じで決まる。
    vi2 rel(n, vi());
    rep(i, n-1) {
        Def(a);
        Def(b);
        a--;
        b--;

        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    vl2 tree(n, vl());
    vb fin(n, false);
    stack<int> st;
    st.push(t);
    while(!st.empty()) {
        auto nxt = st.top();
        st.pop();
        fin[nxt] = true;
        for(auto c : rel[nxt]) {
            if(!fin[c]) {
                tree[nxt].push_back(c);
                st.push(c);
            }
        }
    }

    vl lvl(n, -1);
    check(tree, t, lvl);
    rep(i, n) {
        cout << lvl[i] << " ";
    }
    cout << endl;
}
