// 傻逼汉化翻译，一坨狗屎
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    int m1, m2;
    cin >> m1;
    vector<array<int, 2> > bian1(m1+10);
    for (int i=1; i<=m1; i++) {
        int u, v;  cin >> u >> v;
        if (u > v) swap(u, v);
        bian1[i][0] = u;  bian1[i][1] = v;
    }
    cin >> m2;
    vector<array<int, 2> > bian2(m2+10);
    for (int i=1; i<=m2; i++) {
        int u, v;  cin >> u >> v;
        if (u > v) swap(u, v);
        bian2[i][0] = u;  bian2[i][1] = v;
    }
    // for (int i=1; i<=m1; i++) {
    //     for (int j=1; j<=m2; j++) {
    //         if (bian1[i] == bian2[j]) {
    //             bo[bian1[i][0]] = 1; 
    //             bo[bian1[i][1]] = 1;
    //         }
    //     }
    // }
    vector<vector<int> > num(n+10, vector<int> (n+10, 1e9));
    num[s1][s2] = 0;
    vector<int> bo1(n+10, 0), bo2(n+10, 0);
    bo1[s1] = n;  bo2[s2] = n;
    int cnum = n;
    while (cnum --) {
        bool bo = false;
        for (int i=1; i<=m1; i++) {
            int u1 = bian1[i][0], v1 = bian1[i][1];
            if ( !(bo1[u1] >= cnum || bo1[v1] >= cnum) )  continue;
            for (int j=1; j<=m2; j++) {
                int u2 = bian2[j][0], v2 = bian2[j][1];
                if ( !(bo2[u2] >= cnum || bo2[v2] >= cnum) )  continue;
                if (num[v1][v2] > num[u1][u2] + abs(v1 - v2)) {
                    num[v1][v2] = num[u1][u2] + abs(v1 - v2);
                    bo = true;
                }
                if (num[v1][u2] > num[u1][v2] + abs(v1 - u2)) {
                    num[v1][u2] = num[u1][v2] + abs(v1 - u2);
                    bo = true;
                }
                if (num[u1][v2] > num[v1][u2] + abs(u1 - v2)) {
                    num[u1][v2] = num[v1][u2] + abs(u1 - v2);
                    bo = true;
                }
                if (num[u1][u2] > num[v1][v2] + abs(u1 - u2)) {
                    num[u1][u2] = num[v1][v2] + abs(u1 - u2);
                    bo = true;
                }
                if (!bo2[u2] )  bo2[u2] = cnum - 1;
                if (!bo2[v2] )  bo2[v2] = cnum - 1;
            }
            if (!bo1[u1] )  bo1[u1] = cnum - 1;
            if (!bo1[v1] )  bo1[v1] = cnum - 1;
        }
        if (!bo) {
            break;
        }
    }
    int ans = 1e9;
    for (int i=1; i<=m1; i++) {
        for (int j=1; j<=m2; j++) {
            if (bian1[i] == bian2[j]) {
                // cout << bian1[i][0] << ": " << num[bian1[i][0]][bian1[i][0]] << '\n';
                // cout << bian1[i][1] << ": " << num[bian1[i][1]][bian1[i][1]] << '\n';
                ans = min(ans, num[bian1[i][0]][bian1[i][0]]);
                ans = min(ans, num[bian1[i][1]][bian1[i][1]]);
            }
        }
    }
    if (ans == 1e9)  ans = -1;
    cout << ans << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
