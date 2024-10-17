#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    string s;
    cin >> n >> s;
    if ((int)sqrt(n) * (int)sqrt(n) != n) {
        cout << "NO\n";
        return;
    }
    int m = sqrt(n);
    bool bo = true;
    for (int i=0; i<n; i++) {
        int x = i / m, y = i % m;
        if (x == 0 || x == m-1 || y == 0 || y == m-1) {
            if (s[i] == '0')  bo = false;
        } else {
            if (s[i] == '1')  bo = false;
        }
    }
    if (bo) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
