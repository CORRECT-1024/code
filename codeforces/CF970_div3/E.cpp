#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<array<int, 30> > sum1(n+10, array<int, 30>{0}), sum0(sum1);
    sum0[0][s[0] - 'a'] = 1;
    for (int i=1; i<n; i++) {
        for (int j=0; j<26; j++) sum1[i][j] = sum1[i-1][j], sum0[i][j] = sum0[i-1][j];
        if (i & 1) sum1[i][s[i] - 'a'] ++;
        else sum0[i][s[i] - 'a'] ++;
    }
    if (n & 1) {
        int ans = 1e9;
        for (int i=0; i<n; i++) {
            array<int, 30> fsum1 = {0}, fsum0 = {0};
            for (int j=0; j<26 && i ; j++) {
                fsum1[j] += sum1[i-1][j];
                fsum0[j] += sum0[i-1][j];
            }
            for (int j=0; j<26 && i < n-1; j++) {
                fsum1[j] += sum0[n-1][j] - sum0[i][j];
                fsum0[j] += sum1[n-1][j] - sum1[i][j];
            }
            int ma1 = 0, ma0 = 0;
            for (int i=0; i<26; i++) {
                ma1 = max(ma1, fsum1[i]);
                ma0 = max(ma0, fsum0[i]);
            }
            int fans = n - 1 - ma1 - ma0;
            ans = min(ans, fans);
        }
        ans ++;
        cout << ans << '\n';
    } else {
        int ma1 = 0, ma0 = 0;
        for (int i=0; i<26; i++) {
            ma1 = max(ma1, sum1[n-1][i]);
            ma0 = max(ma0, sum0[n-1][i]);
        }
        int ans = n - ma1 - ma0;
        cout << ans << '\n';
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
