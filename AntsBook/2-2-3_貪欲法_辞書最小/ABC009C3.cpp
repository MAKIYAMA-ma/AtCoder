#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(vec) vec.begin(), vec.end()

/* cnt1:残り部分を初期文字列のままにするのに必要な文字 */
/* cnt2:未使用文字 */
/* -> 足りない文字数分、残り文字列部分で変更回数が必要 */
int check(vector<int> &cnt1, vector<int> &cnt2)
{
    int tmp = 0;
    rep(i, 26) {
        tmp += max(0, cnt1.at(i) - cnt2.at(i));
    }
    return tmp;
}

int main()
{
    int n, k;
    int num = 0;
    string s, ans;

    cin >> n >> k;
    cin >> s;

    vector<int> cnt1(26, 0);
    vector<int> cnt2(26, 0);

    if(k <= 1) {
        // 最初から1以下のKでは入替不可
        cout << s << endl;
        return 0;
    }

    /* 各英字の個数をカウント */
    rep(i, n) {
        cnt1.at(s[i]-'a')++;
        cnt2.at(s[i]-'a')++;
    }

    rep(i, n) {
        /* 上書きされる文字のカウントをcnt1から減らす */
        /* cnt1は初期文字列で、残り部分で必要な文字をカウントしている */
        cnt1.at(s[i]-'a')--;
        if(num == k) {
            ans += s[i];
            continue;
        }
        rep(j, 26) {
            if(!cnt2.at(j)) {
                /* cnt2で無くなった文字はスキップする */
                continue;
            }
            if(s[i]-'a' == j){
                /* 変更不要だったケース */
                /* ansに採用したらその文字をcnt2で減らす */
                /* cnt2は残っている文字を表しているっぽい */
                cnt2.at(j)--;
                ans += s[i];
                break;
            }
            cnt2.at(j)--;
            if((num + check(cnt1, cnt2) + 1) <= k) {
                num++;
                ans += (char)(j+'a');
                break;
            }
            cnt2.at(j)++;
        }
    }
    cout << ans << endl;
    return 0;
}
