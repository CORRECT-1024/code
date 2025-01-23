#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0);
    map<int, int> mp;
    int num = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) num ++;
        mp[a[i]] ++;
    }
    if (num != 2) {
        cout << "No\n";
        return;
    }
    int fnum = -1;
    for (auto &[_, se] : mp) {
        if (fnum == -1) fnum = se;
        else fnum -= se;
    }
    if (fnum == 0) {
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
