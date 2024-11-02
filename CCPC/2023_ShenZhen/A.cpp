#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void fun(int be, int en, vector<vector<int> > &a, vector<array<int, 2> > &ans) {
    if (be == en)  return;
    int mid = ((be + en) >> 1);
    int rbe = mid + 1;
    for (int i=rbe; i<=en; i++) {
        for (auto &id : a[i]) {
            ans.push_back({2, id});
        }
    }
    for (int i=be + 2; i<=rbe; i++) {
        ans.push_back({1, i - 1});
    }
    fun(rbe, en, a, ans);
    fun(be, mid, a, ans);
}
void work() {
    int n;
    cin >> n;
    vector<vector<int> > a(n+10, vector<int>());
    for (int i=1; i<=n; i++) {
        int x;  cin >> x;
        a[x].push_back(i);
    }
    vector<array<int, 2> > ans;
    fun(0, n, a, ans);
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) {
        cout << x << ' ' << y << '\n';
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
