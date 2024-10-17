#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n;

int check(int ml, int mr, vector<vector<int> > &b) {
    int l = ml, r = mr;
    int last = -1;
    bool bo = true;
    int t0 = -1;
    for (int i=1; i<=n; i++) {
        if (b[i].size() == 0)  continue;
        if (bo) {
            t0 = i - (r - l + 1);
            bo = false;
            last = i;
        } else {
            bool boo = false;
            int dl = 0;
            if (b[i][0] < l) {
                dl = l - b[i][0];
                l = b[i][0];
                boo = true;
            }
            int dr = 0;
            if (b[i][b[i].size()-1] > r) {
                dr = b[i][b[i].size()-1] - r;
                r = b[i][b[i].size()-1];
                boo = true;
            }
            if (boo) {
                t0 += i - last - dl - dr;
                last = i;
            }
        }
        if (t0 < 0) break;
    }
    return t0;
}
void work() {
    cin >> n;
    vector<int> a(n+10, 0);
    vector<vector<int> > b(n+10, vector<int>());
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    int ml = -1, mr = -1;
    for (int i=1; i<=n; i++) {
        if (b[i].size() == 0)  continue;
        ml = b[i][0];  mr = b[i][b[i].size()-1];
        break;
    }
    int t0 = check(ml, mr, b);
    if (t0 < 0) {
        cout << 0 << '\n';
        return;
    }
    int nowl = max(1, ml - t0), nowr = min(n, mr + t0);
    int l = 1, r = nowl;
    while (l < r) {
        int mid = ((l + r - 1) >> 1);
        int fml = min(ml, mid), fmr = mr;
        t0 = check(fml, fmr, b);
        if (t0 >= 0) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    nowl = l;
    l = nowr, r = n;
    while (l < r) {
        int mid = ((l + r + 1) >> 1);
        int fmr = max(mr, mid), fml = ml;
        t0 = check(fml, fmr, b);
        if (t0 >= 0) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    nowr = l;
    int ans = nowr - nowl + 1;
    // cout << nowl << ' ' << nowr << '\n';
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
