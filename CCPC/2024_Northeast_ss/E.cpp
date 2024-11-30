#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int num = 0;
    for (auto &c : s) {
        if (c == '1') num ++;
    }
    int ans = -1;
    for (int i=num; i<(1<<k) && i <= num + k; i++) {
        int ii = i;
        int fnum = 0;
        while (ii) {
            if (ii & 1) fnum ++;
            ii >>= 1;
        }
        if (i == num + fnum) {
            ans = i;  break;
        }
    }
    if (ans == -1) {
        cout << "None\n";
        return;
    }
    vector<int> fans(k+10, 0);
    for (int i=0; i<k; i++) {
        if (ans & 1) {
            fans[i] = 1;
        }
        ans >>= 1;
    }
    for (int i=k-1; i>=0; i--) {
        cout << fans[i];
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
    cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
