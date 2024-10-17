#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int find(int x, vector<int>&fa) {
    if (fa[x] == x)  return x;
    return fa[x] = find(fa[x], fa);
}
void work() {
    int n;
    cin >> n;
    vector<int> p(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> p[i];
    }
    string s;
    cin >> s;
    vector<int> num(n+10, 0), fa(n+10, 0);
    for (int i=1; i<=n; i++) {
        fa[i] = i;
        num[i] = (s[i-1] == '0');
    }
    for (int i=1; i<=n; i++) {
        if (fa[i] == i) {
            int id = p[i];
            while (id != i) {
                num[i] += num[find(id, fa)];
                num[fa[id]] = 0;
                fa[fa[id]] = i;
                id = p[id];
            }
        } else {
            num[i] = num[fa[i]];
        }
        cout << num[i] << ' ';
    }
    cout << '\n';
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
