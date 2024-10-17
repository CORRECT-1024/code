#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

bool cmp(array<int, 2>&x, array<int, 2>&y) {
    return x[0] > y[0];
}
void work() {
    int n;
    string s;
    cin >> n >> s;
    vector<array<int, 2> > a(30, {0, 0});
    for (int i=0; i<26; i++)  a[i][1] = i;
    for (int i=0; i<s.size(); i++) {
        int id = s[i] - 'a';
        a[id][0] ++;
    }
    sort(&a[0], &a[26], cmp);
    string ans = "";
    while (ans.size() < n) {
        for (int i=0; i<26; i++) {
            if (a[i][0] == 0)  break;
            ans += 'a' + a[i][1];
            a[i][0] --;
        }
    }
    cout << ans << '\n';
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
