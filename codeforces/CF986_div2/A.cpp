#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int x = 0, y = 0;
    int num = 100;
    while (num --) {
        for (int i=0; i<s.size(); i++) {
            if (x == a && y == b) {
                cout << "Yes\n";
                return;
            }
            if (s[i] == 'N') y ++;
            if (s[i] == 'S') y --;
            if (s[i] == 'E') x ++;
            if (s[i] == 'W') x --;
            if (x == a && y == b) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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
