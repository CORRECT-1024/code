//看题解
// 这题为什么要看题解?
// 啊啊啊啊啊啊
// 写假题啦，不玩啦！！！！！
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    LL n, m;
    cin >> n >> m;
    vector<vector<int> > aid(n+10, vector<int>());
    vector<array<LL, 3> > b(m+10);
    for (int i=1; i<=m; i++) {
        cin >> b[i][0] >> b[i][2] >> b[i][1];
        for (int j=0; j<=b[i][1]; j++) {
            int id = b[i][0] + j * b[i][2];
            aid[id].push_back(i);
        }
    }
    vector<int> f(n+10, 0);
    for (int i=1; i<=n; i++)  f[i] = i;
    int ans = 0;
    vector<int> bom(m+10, 0);
    for (int i=1; i<=n; i++) {
        if (f[i] == i) {
            ans ++;
        } else  continue;
        queue<int> qu;
        qu.push(i);
        while (!qu.empty() ) {
            int x = qu.front();
            qu.pop();
            for (auto &bid : aid[x]) {
                if (bom[bid] )  continue;
                bom[bid] = 1;
                for (int j=0; j<=b[bid][1]; j++) {
                    int to = b[bid][0] + j * b[bid][2];
                    if (f[to] != to || to == i)  continue;
                    f[to] = i;
                    qu.push(to);
                }
            }
        }
    }
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
