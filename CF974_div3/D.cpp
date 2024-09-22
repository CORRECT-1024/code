#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> sum(n+10, 0);
    for (int i=1; i<=k; i++) {
        int l, r;
        cin >> l >> r;
        sum[max(1, l - d + 1)] ++;  sum[r + 1] --;
    }
    for (int i=1; i<=n; i++) {
        sum[i] += sum[i-1];
    }
    int ans1 = -1, id1, ans2 = 1e9, id2;
    // priority_queue<int, vector<int>, less<>> pri;
    // map<int, int> mp;
    for (int i=1; i<=n - d + 1; i++) {
        if (sum[i] > ans1) {
            ans1 = sum[i];  id1 = i;
        }
        if (sum[i] < ans2) {
            ans2 = sum[i];  id2 = i;
        }
        // pri.push(sum[i]);
        // mp[sum[i]] ++;
        // if (i < d)  continue;
        // if (i > d) {
        //     mp[sum[i-d]] --;
        // }
        // while (mp[pri.top()] == 0) {
        //     pri.pop();
        // }
        // int fans = pri.top();
        // if (fans > ans1) {
        //     ans1 = fans;  
        //     // id1 = i - d + 1;
        //     id1 = i;
        // }
        // if (fans < ans2) {
        //     ans2 = fans;  
        //     // id2 = i - d + 1;

        // }
    }
    cout << id1 << ' ' << id2 << '\n';
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
