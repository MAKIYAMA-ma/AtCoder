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

    Def(h);
    Def(w);
    vs c(h);
    rep(i, h) cin >> c[i];

    // h,w <= 2000
    // c 26種類
    // 単純に探索すると、行列交互に26文字
    // (2000*2)*2000*26 = 208*10^6
    // ギリあふれるのでは？
    vector<map<ll, ll>> hm(h, map<ll, ll>());
    vector<map<ll, ll>> wm(w, map<ll, ll>());
    rep(i, h) {
        rep(j, w) {
            hm[i][c[i][j] - 'a']++;
            wm[j][c[i][j] - 'a']++;
        }
    }

    vector<map<ll, ll>> hmr(h, map<ll, ll>());
    vector<map<ll, ll>> wmr(w, map<ll, ll>());
    rep(i, h) hmr[i] = hm[i];
    rep(i, w) wmr[i] = wm[i];

    bool cont{false};
    do {
        cont = false;
        for(auto &m : hm) {
            if(m.size() == 1) {
                auto [k, nm] = *m.begin();
                /* cout << "DB1:" << k << " " << nm << endl; */
                /* cout << "    " << m.size() << endl; */
                if(nm > 1) {
                    for(auto &mm : wm) {
                        if(mm[k] == 1) {
                            mm.erase(k);
                        } else if(mm[k] > 0) {
                            mm[k]--;
                        }
                    }
                    m.erase(k);
                    /* cout << "    " << m.size() << endl; */
                    cont = true;
                }
            }
        }
        for(auto &m : wm) {
            if(m.size() == 1) {
                auto [k, nm] = *m.begin();
                /* cout << "DB2:" << k << " " << nm << endl; */
                /* cout << "    " << m.size() << endl; */
                if(nm > 1) {
                    for(auto &mm : hm) {
                        if(mm[k] == 1) {
                            mm.erase(k);
                        } else if(mm[k] > 0) {
                            mm[k]--;
                        }
                    }
                    m.erase(k);
                    /* cout << "    " << m.size() << endl; */
                    cont = true;
                }
            }
        }
    } while(cont);

    ll ans{0};
    for(auto m : hm) {
        for(auto [k, nm] : m) {
            ans += nm;
        }
    }

    cont = false;
    do {
        cont = false;
        for(auto &m : wmr) {
            if(m.size() == 1) {
                auto [k, nm] = *m.begin();
                /* cout << "DB2:" << k << " " << nm << endl; */
                /* cout << "    " << m.size() << endl; */
                if(nm > 1) {
                    for(auto &mm : hmr) {
                        if(mm[k] == 1) {
                            mm.erase(k);
                        } else if(mm[k] > 0) {
                            mm[k]--;
                        }
                    }
                    m.erase(k);
                    /* cout << "    " << m.size() << endl; */
                    cont = true;
                }
            }
        }
        for(auto &m : hmr) {
            if(m.size() == 1) {
                auto [k, nm] = *m.begin();
                /* cout << "DB1:" << k << " " << nm << endl; */
                /* cout << "    " << m.size() << endl; */
                if(nm > 1) {
                    for(auto &mm : wmr) {
                        if(mm[k] == 1) {
                            mm.erase(k);
                        } else if(mm[k] > 0) {
                            mm[k]--;
                        }
                    }
                    m.erase(k);
                    /* cout << "    " << m.size() << endl; */
                    cont = true;
                }
            }
        }
    } while(cont);

    ll ansr{0};
    for(auto m : hmr) {
        for(auto [k, nm] : m) {
            ansr += nm;
        }
    }

    cout << min(ans, ansr) << endl;
}
