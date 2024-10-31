#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int find(int x, vector<int> &fa) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x], fa);
}
void work() {
    int n, ans = 0;
    cin >> n;
    vector<int> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> fa(n+10, 0);
    for (int i=1; i<=n; i++)  fa[i] = i;
    for (int i=1; i<=n; i++) {
        if (fa[i] != i)  continue;
        int id = a[i], num = 1;
        while (id != i) {
            num ++;
            fa[find(id, fa)] = i;
            id = a[id];
        }
        ans += (num - 1) / 2;
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
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
