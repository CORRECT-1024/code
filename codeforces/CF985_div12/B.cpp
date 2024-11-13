#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;  cin >> n;
    string s, t;
    cin >> s >> t;
    vector<int> num(5, 0);
    for (auto &c : s) {
        if (c == '0')  num[0] ++;
        else num[1] ++;
    }
    for (auto &c : t) {
        if (num[0] && num[1]) {
            num[0] --;  num[1] --;
            num[c - '0'] ++;
            continue;
        }
        cout << "NO\n";
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
