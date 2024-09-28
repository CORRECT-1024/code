#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    vector<LL> a(20, 0);
    for (int i=1; i<=19; i++) {
        cin >> a[i];
    }
    vector<array<int, 3> > to(60);
    to[1] = {1, 2, 3};
    to[2] = {4, 5, 6};
    to[3] = {5, 6, 7};
    to[4] = {8, 9,10};
    to[5] = {9, 10, 11};
    to[6] = {10, 11, 12};
    to[7] = {13, 14, 15};
    to[8] = {14, 15, 16};
    to[9] = {17, 18, 19};
    to[10] = {1, 4, 8};
    to[11] = {2, 5, 9};
    to[12] = {5, 9, 13};
    to[13] = {3, 6, 10};
    to[14] = {6, 10, 14};
    to[15] = {10, 14, 17};
    to[16] = {7, 11, 15};
    to[17] = {11, 15, 18};
    to[18] = {12, 16, 19};
    to[19] = {8, 13, 17};
    to[20] = {4, 9, 14};
    to[21] = {9, 14, 18};
    to[22] = {1, 5, 10};
    to[23] = {5, 10, 15};
    to[24] = {10, 15, 19};
    to[25] = {2, 6, 11};
    to[26] = {6, 11, 16};
    to[27] = {3, 7, 12};
    vector<int> b(30, 0);
    for (int i=1; i<=19; i++) {
        b[i] = (1 << (i - 1));
    }
    vector<LL> dp((1 << 19) + 10, 0);
    vector<vector<int> > p(20, vector<int>());
    for (int i=1; i<(1 << 19); i++) {
        int t = i, num = 0;
        while (t) {
            if (t & 1) num ++;
            t >>= 1;
        }
        p[num].push_back(i);
    }
    for (int num=1; num<=19; num++) {
        for (auto &i : p[num]) {
            for (int j=1; j<=27; j++) {
                if ((i & b[to[j][2]]) && !(i & b[to[j][0]]) && !(i & b[to[j][1]])) {
                    int fto1 = i - b[to[j][2]] + b[to[j][0]] + b[to[j][1]]; 
                    dp[fto1] = max(dp[fto1], dp[i] + a[to[j][1]]);
                }
                if ((i & b[to[j][0]]) && !(i & b[to[j][1]]) && !(i & b[to[j][2]])) {
                    int fto2 = i - b[to[j][0]] + b[to[j][1]] + b[to[j][2]];
                    dp[fto2] = max(dp[fto2], dp[i] + a[to[j][1]]);
                }
            }
            for (int j=1; j<=19; j++) {
                dp[i | b[j]] = max(dp[i | b[j]], dp[i]);
                // if ((i | b[i]) == abc) {
                //     cout << dp[i | b[i]] << '\n';
                // }
            }
        }
    }
    int q;  cin >> q;
    while (q --) {
        int x = 0, id = 1;
        for (int i=1; i<=5; i++) {
            string s;  cin >> s;
            for (int j=0; j<s.size(); j++) {
                if (s[j] == '#') {
                    x += b[id]; 
                }
                id ++;
            }
        }
        // cout << x << ' ';
        cout << dp[x] << '\n';
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
