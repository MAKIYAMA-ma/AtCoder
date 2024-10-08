#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

typedef modint998244353 mint;
typedef long long ll;

bool has_negative_cycle(int n, vector<int> &s, vector<int> &t, vector<double> &c){
    int m = s.size();
    vector<double> d(n);
    for (int i=0; i<n+1; i++){
        bool update = false;
        for (int j=0; j<m; j++){
            if (d[t[j]] > d[s[j]] + c[j]){
                d[t[j]] = d[s[j]] + c[j];
                update = true;
            }
        }
        if (update == false){
            return false;
        }
        if (i==n){
            return true;
        }
    }
    return false;
}

int main(){
    cout << setprecision(14);
    int n, m, k; cin >> n >> m >> k;
    vector<int> v(k);
    vector<double> val(k);
    for (int i=0; i<k; i++){
        cin >> v[i] >> val[i];
        v[i]--;
    }
    vector<int> u(m);
    vector<int> w(m);
    vector<double> c(m);
    for (int i=0; i<m; i++){
        cin >> u[i] >> w[i] >> c[i];
        u[i]--;
        w[i]--;
    }

    double ub = 1e14;
    double lb = -1e14;

    for (int num=0; num<100; num++){
        double targ = (ub + lb) / 2;
        vector<int> s(0), t(0);
        vector<double> cost(0);

        for (int i=0; i<k; i++){
            s.push_back(n);
            t.push_back(v[i]);
            cost.push_back(val[i]);

            s.push_back(v[i]);
            t.push_back(n);
            cost.push_back(-val[i]);
        }

        for (int i=0; i<m; i++){
            s.push_back(w[i]);
            t.push_back(u[i]);
            cost.push_back(targ-c[i]);
        }

        if (has_negative_cycle(n+1, s, t, cost)){
            lb = targ;
        }else{
            ub = targ;
        }
    }

    if (lb < (-9e13)){
        cout << "#" << endl;
    }else{
        cout << ub << endl;
    }
}
