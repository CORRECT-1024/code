#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 2e5 + 10;
int xds1[N * 4], xds2[N * 4];

void build1(int k, int l, int r, vector<int> &a) {
    if (l == r) {
        xds1[k] = a[l];  return;
    }
    int mid = ((l + r ) >> 1);
    build1(2*k, l, mid, a);
    build1(2*k+1, mid + 1, r, a);
    xds1[k] = __gcd(xds1[2*k], xds1[2*k+1]);
}
void build2(int k, int l, int r, vector<int> &b) {
    if (l == r) {
        xds2[k] = b[l];  return;
    }
    int mid = ((l + r ) >> 1);
    build2(2*k, l, mid, b);
    build2(2*k+1, mid + 1, r, b);
    xds2[k] = __gcd(xds2[2*k], xds2[2*k+1]);
}
int check1(int k, int l, int r, int vl, int vr) {
    if (l >= vl && r <= vr) return xds1[k];
    int mid = ((l + r ) >> 1);
    int ans = 0;
    if (vr <= mid) ans = check1(2*k, l, mid, vl, vr);
    else if (vl > mid) ans = check1(2*k+1, mid + 1, r, vl, vr);
    else ans = __gcd(check1(2*k, l, mid, vl, vr), check1(2*k+1, mid + 1, r, vl, vr));
    return ans;
}
int check2(int k, int l, int r, int vl, int vr) {
    if (l >= vl && r <= vr) return xds2[k];
    int mid = ((l + r ) >> 1);
    int ans = 0;
    if (vr <= mid) ans = check2(2*k, l, mid, vl, vr);
    else if (vl > mid) ans = check2(2*k+1, mid + 1, r, vl, vr);
    else ans = __gcd(check2(2*k, l, mid, vl, vr), check2(2*k+1, mid + 1, r, vl, vr));
    return ans;
}
// int gcd(int x, int y) {
//     if (x == 0)  return y;
//     if (y == 0)  return x;
//     return __gcd(x, y);
// }
void work() {
    int n;
    cin >> n;
    vector<int> a(n+10, 0), b(n+10, 0);
    int na = 0, nb = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if ( na )  na = __gcd(na, a[i]);
        else na = a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        if ( nb )  nb = __gcd(nb, b[i]);
        else nb = b[i];
    }
    build1(1, 1, n, a);
    build2(1, 1, n, b);
    int ans = 0;
    vector<int> suma1(n+10, 0), suma2(n+10, 0), sumb1(n+10, 0), sumb2(n+10, 0);
    suma1[1] = a[1];  sumb1[1] = b[1];  suma2[n] = a[n];  sumb2[n] = b[n];
    for (int i=2; i<=n; i++) {
        suma1[i] = __gcd(suma1[i-1], a[i]);
        sumb1[i] = __gcd(sumb1[i-1], b[i]);
    }
    for (int i=n-1; i>=1; i--) {
        suma2[i] = __gcd(suma2[i+1], a[i]);
        sumb2[i] = __gcd(sumb2[i+1], b[i]);
    }
    map<int, LL> mp;
    for (int i = 1; i<=n; i++) {
        // cout << i << "**" << '\n';
        int l = i, r = n;
        int fa = na, fb = nb;
        int lastans = fa + fb, lastr = i;
        int gcdlra = -1, gcdlrb = -1, gcdrna = suma2[i], gcdrnb = sumb2[i]; 
        while (true) {
            while (l < r) {
                int mid = ((l + r ) >> 1);

                if (suma2[mid + 1] != gcdrna) {
                    r = mid;  continue;
                }
                if (sumb2[mid + 1] != gcdrnb) {
                    r = mid;  continue;
                }
                if (gcdlra != -1 && check2(1, 1, n, i, mid) != gcdlra) {
                    r = mid;  continue;
                }
                if (gcdlrb != -1 && check1(1, 1, n, i, mid) != gcdlrb) {
                    r = mid;  continue;
                }
                l = mid + 1;
            }
            int aans = 0, bans = 0;
            aans = check2(1, 1, n, i, l);
            gcdlra = aans;  gcdrna = suma2[l + 1];
            if (i != 1) aans = __gcd(aans, suma1[i-1]);
            if (l != n) aans = __gcd(aans, suma2[l + 1]);
            bans = check1(1, 1, n, i, l);
            gcdlrb = bans;  gcdrnb = sumb2[l + 1];
            if (i != 1) bans = __gcd(bans, sumb1[i-1]);
            if (l != n) bans = __gcd(bans, sumb2[l + 1]);
            ans = max(ans, aans + bans);
            mp[lastans] += l - lastr;
            // cout << l << '\n';
            // cout << lastans << ": " << l - lastr << '\n';
            lastans = aans + bans;  
            lastr = l;
            if (l == n) {
                mp[lastans] ++;  
                // cout << lastans << ": " << 1 << '\n';
                break;
            }
            l ++; r = n;
        }
    }
    cout << ans << ' ' << mp[ans] << '\n';
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
