#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int num0 = 0, num1 = 0;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '0') num0 ++;
        else num1 ++;
        if (num0 > num1) {
            num0 = 0;  num1 = 0;
        }
    }
    int len = num0 + num1;
    if (len == 0 || len >= 4) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
