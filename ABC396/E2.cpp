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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    Def(n);
    Def(m);
    vpl2 cn(n, vpl());
    rep(i, m) {
        Def(x);
        Def(y);
        Def(z);
        x--; y--;
        cn[x].push_back({y, z});
        cn[y].push_back({x, z});
    }
    vl a(n, -1);

    rep(i, n) {
        if(a[i] != -1) continue;
#if 1
        set<ll> grp;
        ll cst{0}, st{i};
        a[i] = 0;
        queue<ll> q;
        q.push(i);
        while(!q.empty()) {
            auto tp = q.front();
            q.pop();
            for(auto [nxt, z] : cn[tp]) {
                ll val = z^a[tp];
                if(a[nxt] == -1) {
                    a[nxt] = val;
                    grp.insert(nxt);
                    cst += val;
                    q.push(nxt);
                } else if(a[nxt] != val) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }

        for(auto v : grp) {
            ll tmp{0};
            a[v] = 0;
            q.push(v);
            while(!q.empty()) {
                auto tp = q.front();
                q.pop();
                for(auto [nxt, z] : cn[tp]) {
                    ll val = z^a[tp];
                    if(a[nxt] != val) {
                        a[nxt] = val;
                        tmp += val;
                        q.push(nxt);
                    }
                }
            }
            if(tmp < cst) {
                cst = tmp;
                st = v;
            }
        }

        a[st] = 0;
        q.push(st);
        while(!q.empty()) {
            auto tp = q.front();
            q.pop();
            for(auto [nxt, z] : cn[tp]) {
                ll val = z^a[tp];
                if(a[nxt] != val) {
                    a[nxt] = val;
                    grp.insert(nxt);
                    cst += val;
                    q.push(nxt);
                }
            }
        }
#else
        a[i] = 0;
        queue<ll> q;
        q.push(i);
        while(!q.empty()) {
            auto tp = q.front();
            q.pop();
            for(auto [nxt, z] : cn[tp]) {
                ll val = z^a[tp];
                if(a[nxt] == -1) {
                    a[nxt] = val;
                    q.push(nxt);
                } else if(a[nxt] != val) {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
#endif
    }

    rep(i, n) {
        cout << a[i] << " ";
    }
    cout << endl;
}
