#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

int n, k;

bool check(LL x, vector<LL>&a, vector<LL>&b) {
    if (x == 0)  return true;
    priority_queue<LL, vector<LL>, less<>> pri;
    for (int i=1;i<=n; i++) {
        pri.push(x * a[i]);
    }
    vector<LL> bb(b);
    for (int i=k; i>=1; i--) {
        while (bb[i] && !pri.empty() && pri.top() > (1 << (i - 1)) ) {
            LL t = pri.top() / (1 << (i - 1));
            t = min(t, bb[i]);
            LL la = pri.top() - t * (1 << (i - 1));
            pri.pop();
            if (la) pri.push(la);
            bb[i] -= t;
        }
        while (bb[i] && !pri.empty() && pri.top() <= (1 << (i - 1)) ) {
            pri.pop();
            bb[i] --;
        }
    }
    if (pri.empty()) return true;
    return false;
}
void work() {
    cin >> n >> k;
    vector<LL> a(n+10, 0), b(k+10, 0);
    LL suma = 0, sumb = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        suma += a[i];
    }
    for (int i=1; i<=k; i++) {
        cin >> b[i];
        sumb += (1 << (i - 1)) * b[i];
    }
    LL l = 0, r = sumb / suma;
    while (l < r) {
        LL mid = ((l + r + 1) >> 1);
        if (check(mid, a, b) ) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
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
