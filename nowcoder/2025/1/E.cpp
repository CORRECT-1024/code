#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    vector<LL> a(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n+1]);
    LL sum1 = 0, fsum = 0;
    for (int i=1; i<=n/2; i++) {
        sum1 += a[i];
    }
    LL qans1=1e15, qx1 = -1, qans2=1e15, qx2 = -1;
    for (int i=1; i<=n/2; i++) {
        if (a[i] == a[i-1])  continue;
        fsum += a[i-1];
        LL fans = a[i] * (i - 1)  - fsum  +  sum1 - fsum - a[i] * (n / 2 - i + 1);
        if (fans < qans1) {
            qx2 = qx1;  qans2 = qans1;
            qx1 = a[i];  qans1 = fans;
            // qx2 = a[i] - 1;  qans2 = fans  +  n/2 - i + 1  -  (i - 1);
        } else if (fans <= qans2) {
            qx2 = a[i];  qans2 = fans;
        }
        LL ffans = fans  +  n/2 - i + 1  -  (i - 1);
        if (ffans < qans1) {
            qx2 = qx1;  qans2 = qans1;
            qx1 = a[i] - 1;  qans1 = ffans;
        } else if (ffans < qans2) {
            qx2 = a[i] - 1;  qans2 = ffans;
        }
    }
    
    sum1 = 0, fsum = 0;
    for (int i=n/2 + 1; i<=n; i++) {
        sum1 += a[i];
    }
    LL hans1 = 1e15, hx1 = -1, hans2 = 1e15, hx2 = -1;
    for (int i=n; i>n/2; i--) {
        if (a[i] == a[i + 1])  continue;
        fsum += a[i + 1];
        LL fans = fsum - a[i] * (n - i)  +  a[i] * (i - n / 2) - (sum1 - fsum);
        // cout << a[i] << ' ' << fans << '\n';
        if (fans < hans1) {
            hx2 = hx1;  hans2 = hans1;
            hx1 = a[i];  hans1 = fans;
            // hx2 = a[i] + 1;  hans2 = fans  +  (i - n/2)  -  (n - i);
        } else if (fans <= hans2) {
            hx2 = a[i];  hans2 = fans;
        }
        LL ffans = fans  +  (i - n/2)  -  (n - i);
        if (ffans < hans1) {
            hx2 = hx1;  hans2 = hans1;
            hx1 = a[i] + 1;  hans1 = ffans;
        } else if (ffans < hans2) {
            hx2 = a[i] + 1;  hans2 = ffans;
        }
    }
    
    // cout << qx1 << ' ' << qans1 << ' ' << qx2 << ' ' << qans2 << '\n';
    // cout << hx1 << ' ' << hans1 << ' ' << hx2 << ' ' << hans2 << '\n';

    if (qx1 != hx1) {
        cout << qans1 + hans1 << '\n';
    } else {
        cout << min(qans1 + hans2, qans2 + hans1) << '\n';
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
