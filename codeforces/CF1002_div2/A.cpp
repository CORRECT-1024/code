#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    map<int, int> mp1, mp2;
    int num1 = 0, num2 = 0;
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        if (mp1[x] == 0)  num1 ++;
        mp1[x] = 1;
    }
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        if (mp2[x] == 0)  num2 ++;
        mp2[x] = 1;
    }
    if (num1 > num2)  swap(num1, num2);
    if (num1 == 1) {
        if (num2 >= 3) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    cout << "YES\n";
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
