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
#define Def2A(a, b, n) vl a(n); rep(i, n) cin >> a[i] >> b[i];
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

    Def(q);
    // 中央がなければqueueでいいわけだが
    // 中央に入れるものだけ別管理というのは可能か？
    // 現在の要素数をもとに、何番になったら出すか決める。
    // でもO(Q)かというと微妙？中央入れの際に
    // -> 違う。中央入れのほうも常に最後尾でいいはず
    // ----> 違う。立て続けに中央に入れれば、前に来たり後に来たりする。
    // setで管理？その場合、cntが当初のindexを超えたら出してOKか？
    // ----> setじゃダメ
    //       後から同じindexが来るのを前に入れないといけない
    //       何で管理すればいい？？？

    deque<string> ph, bh;
    rep(i, q) {
        char odr;
        cin >> odr;
        switch(odr) {
            case 'A':
                {
                    string s;
                    cin >> s;

                    bh.push_back(s);
                }
                break;
            case 'B':
                {
                    string s;
                    cin >> s;

                    bh.push_front(s);
                }
                break;
            case 'C':
                {
                    ph.pop_front();
                }
                break;
            case 'D':
                {
                    cout << ph.front() << endl;
                }
                break;
        }

        while(ph.size() < bh.size()) {
            auto tmp = bh.front();
            bh.pop_front();
            ph.push_back(tmp);
        }
    }
}
