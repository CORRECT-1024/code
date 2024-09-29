#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n, ans, ansnum;
    cin >> n;
    vector<int> a(n+10, 0), b(n+10, 0);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    //a b的前缀异或和
    vector<int> suma(n+10, 0), sumb(n+10, 0);
    //a b的不同前缀异或和的值和位置
    vector<array<int, 2> > pa{{0, 0}}, pb{{0, 0}};
    for (int i=1; i<=n; i++) {
        suma[i] = gcd(suma[i-1], a[i]);
        sumb[i] = gcd(sumb[i-1], b[i]);
    }
    for (int i=1; i<=n; i++) {
        if (suma[i] != suma[i+1]) {
            pa.push_back({suma[i], i});
            // cout << suma[i] << ' ' << i << '\n';
        }
        if (sumb[i] != sumb[i+1]) {
            pb.push_back({sumb[i], i});
        }
    }
    // cout << '\n';
    pa.push_back({suma[n], n});
    pb.push_back({sumb[n], n});
    ans = suma[n] + sumb[n];
    ansnum = 0;
    //a b的后缀异或和
    vector<int> fsuma(n+10, 0), fsumb(n+10, 0);
    for (int i=n; i>=1; i--) {
        fsuma[i] = gcd(fsuma[i+1], a[i]);
        fsumb[i] = gcd(fsumb[i+1], b[i]);
    }
    //gcd(l, r) != gcd(l+1, r)时，存{gcd(l, r), l}
    //随r一直维护
    vector<array<int, 2> > fa, fb;
    fa.push_back({0, 1});
    fb.push_back({0, 1});
    for (int r=1; r<=n; r++) {
        //维护fa, fb的过程和jls不一样，如果wa了再来研究
        //先维护fa, fb;
        int k = 0;
        for (int i=0; i<fa.size(); i++) {
            fa[i][0] = gcd(fa[i][0], a[r]);
            int t = fa[i][0];
            if (k && fa[i][0] == fa[k-1][0]) {
                //只改fa[k-1][1] (l)
                fa[k-1][1] = fa[i][1];
            } else {
                fa[k] = fa[i];
                k ++;
            }
        }
        //方便后面直接push_back
        fa.resize(k);
        k = 0;
        for (int i=0; i<fb.size(); i++) {
            fb[i][0] = gcd(fb[i][0], b[r]);
            if (k && fb[i][0] == fb[k-1][0]) {
                fb[k-1][1] = fb[i][1];
            } else {
                fb[k] = fb[i];
                k ++;
            }
        }
        fb.resize(k);
        fa.push_back({0, r});
        fb.push_back({0, r});
        //l：pa，pb，fa，fb
        int l = 0, last = -1;
        //左：suma[l]，中：fa[faid]，右：fsuma[r+1];
        int paid = 0, pbid = 0, faid = 0, fbid = 0;
        while (true) {
            l = min({pa[paid][1], pb[pbid][1], fa[faid][1], fb[fbid][1]});
            if (l >= r) break;
            if (l != last) {
                int fans = 0;
                fans += gcd(suma[l], gcd(fb[fbid][0], fsuma[r+1]));
                fans += gcd(sumb[l], gcd(fa[faid][0], fsumb[r+1]));
                // cout << l << ' ' << r << ' ' << fans << '\n';
                // cout << suma[l] << ' ' << fb[fbid][0] << ' ' << fsuma[r+1] << '\n';
                // cout << sumb[l] << ' ' << fa[faid][0] << ' ' << fsumb[r+1] << '\n';
                // cout << '\n';
                if (fans > ans) {
                    // cout << l << ' ' << r << ' ' << fans << '\n';
                    ans = fans;
                    ansnum = l - last;
                } else if (fans == ans) {
                    // cout << l << ' ' << r << ' ' << fans << '\n';
                    ansnum += l - last;
                }
            }
            while (l >= pa[paid][1]) {
                paid ++;
            }
            while (l >= pb[pbid][1]) {
                pbid ++;
            }
            while (l >= fa[faid][1]) {
                faid ++;
            }
            while (l >= fb[fbid][1]) {
                fbid ++;
            }
            last = l;
        }
    }
    cout << ans << ' ' << ansnum << '\n';
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("std.txt","w",stdout);
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


