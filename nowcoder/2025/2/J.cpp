#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

struct node {
    string id, date, time;
};

void work() {
    int n;
    string h, m;
    cin >> n >> h >> m;
    if (m.size() < 2)  m = "0" + m;
    vector<node > a(n + 10);
    for (int i=1; i<=n; i++) {
        cin >> a[i].id >> a[i].date >> a[i].time;
    }
    map<string, int> mp1, mp2, mp3;
    for (int i=1; i<=n; i++) {
        if (a[i].date.substr(0, 4) != h)  continue;
        if (a[i].date.substr(5, 2) != m)  continue;
        if (a[i].time >= "07:00:00" && a[i].time <= "09:00:00")  mp1[a[i].id] = 1;
        if (a[i].time >= "18:00:00" && a[i].time <= "20:00:00")  mp1[a[i].id] = 1;
        if (a[i].time >= "11:00:00" && a[i].time <= "13:00:00")  mp2[a[i].id] = 1;
        if (a[i].time >= "22:00:00" || a[i].time <= "01:00:00")  mp3[a[i].id] = 1;
    }
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for (auto &p : mp1)  ans1 ++;
    for (auto &p : mp2)  ans2 ++;
    for (auto &p : mp3)  ans3 ++;
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
