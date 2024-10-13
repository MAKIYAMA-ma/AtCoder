#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#if 1
using mint = modint1000000007;
#else
using mint = modint998244353;
#endif
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) (vec).begin(), (vec).end()
#define rall(vec) (vec).rbegin(), (vec).rend()

const ll MAXLL = 1e18;
const ll MINLL = -1e18;
const ll MAXLD = 1e18;
const ll MINLD = -1e18;
/* const ll MAXLL = numeric_limits<ll>::max(); */
/* const ll MINLL = numeric_limits<ll>::min(); */
/* const ll MAXLD = numeric_limits<long double>::max(); */
/* const ll MINLD = numeric_limits<long double>::min(); */


int main() {
    int n, k;
    cin >> n >> k;

    // 与えられた木の中で、V1-Vkを繋ぐ際、間にいくつの頂点が余計に含まれるかということ
    // いらないはっぱを順番に削って行くのが良いのでは
    vector<set<int>> ab(n+1);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        ab.at(a).insert(b);
        ab.at(b).insert(a);
    }
    vector<bool> vl(n+1, false);
    rep(i, k) {
        int v;
        cin >> v;
        vl.at(v) = true;
    }

    // いらない葉を取り除いていく
    // これだとTLE
    // ---> vector<set<int>> ab(n+1); だとOK
    // ---> vector<vector<int>> ab(n+1); だとTLE
    // だった
    // vectorの場合、eraseもremoveもO(N)
    // setだとO(logN)
    // 削除処理を行うならsetにしておいたほうが良い
    int rmvd = 0;
    stack<int> st;
    rep(i, n+1) {
        if(ab.at(i).size() == 1) {
            st.push(i);
        }
    }
    while(!st.empty()) {
        auto nxt = st.top();
        st.pop();

        if(!vl.at(nxt)) {
            /* cout << "DB:" << nxt << endl; */
            auto pk = *ab.at(nxt).begin();
            ab.at(pk).erase(nxt);
            rmvd++;
            if(ab.at(pk).size() == 1) {
                st.push(pk);
            }
        }
    }
    cout << n-rmvd << endl;
}
