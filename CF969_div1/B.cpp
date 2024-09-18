#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL n, m;

int dfs(int x, int to, vector<vector<int> >&bian, vector<int>&num, vector<vector<int> >&a) {
    if (x != 1) {
        num[(x + n - 2) % n + 1] ++;  
        a[x].push_back((x + n - 2) % n  + 1);
    }
    int l = bian[x].size();
    int fto = to;
    while (l --) {
        fto = dfs(fto, fto % n + 1, bian, num, a);
    }
    if (x == 1)  return 0;
    num[(fto + n - 2) % n + 1] ++;
    a[x].push_back((fto + n - 2) % n + 1);
    return fto;
}
void work() {
    cin >> n >> m;
    vector<vector<int> > bian(n+10, vector<int>());
    for (int i=2; i<=n; i++) {
        int fa;  cin >> fa;
        bian[fa].push_back(i);
    }
    vector<int> num(n+10, 0);
    vector<vector<int> > a(n+10, vector<int> ());
    dfs(1, 2, bian, num, a);
    // for (int i=1; i<=n; i++) {
    //     cout << i << ":  " << num[i] << '\n';
    //     for (auto &p : a[i]) {
    //         cout << p << ' ' ;
    //     }
    //     cout << '\n';
    // }
    // return;
    int q = n - 1;
    LL ans = n * m;
    // vector<int> fnum(num);
    // vector<vector<int> > fa(n+10, vector<int> ());
    // for (int i=2; i<=n; i++) {
    //     for (auto&p : a[i]) {
    //         fa[p].push_back(i);
    //     }
    // }
    LL man = 0;
    int wan = n;
    vector<LL> ansnum(n+10, 0);
    while (q --) {
        LL x, y;  cin >> x >> y;
        m -= y;
        man += y * (LL)a[x].size();
        int fei = 0;
        for (auto &p : a[x]) {
            num[p] --;
            ansnum[p] += y;
            if (num[p] == 0) {
                ans = ans - m;
                n --;
                // man += ansnum[p];
                wan --;
            } else {
                fei ++;
            }
        }
        ans -= y * (n - fei);
        cout << ans << ' ' ;
        // LL fans = man + m * wan;
        // cout << fans << ' ';
        // cout << '\n';
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
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
