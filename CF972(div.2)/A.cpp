#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define QHK 1

void work() {
    int n;
    cin >> n;
    int k = n / 5;
    n %= 5;
    string s = "aeiou";
    for (int i=0; i<5; i++) {
        for (int j=1; j<=k; j++) {
            cout << s[i];
        }
        if (i < n) cout << s[i];
    }
    cout << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    // ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
