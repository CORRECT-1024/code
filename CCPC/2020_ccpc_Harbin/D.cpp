#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 i128;

void work() {
    LL p, q;
    cin >> p >> q;
    map<LL, array<int, 11> > mp;
    int lenp = 0, lenq = 0;
    LL pp = p, qq = q;
    vector<int> bitp, bitq;
    while (pp) {
        lenp ++;  
        bitp.push_back(pp % 10);
        pp /= 10;
    }
    while (qq) {
        lenq ++;
        bitq.push_back(qq % 10);
        qq /= 10;
    }
    for (int i=1; i<(1 << lenp); i++) {
        LL to = 0, f = 1;
        array<int, 11> del{0};
        int fi = i;
        for (int j=0; j<lenp; j++) {
            if (fi & 1) {
                to += f * bitp[j];
                f *= 10;
            } else {
                if (fi == 0 && bitp[j] == 0) del[10] ++;
                else del[bitp[j]] ++;
            }
            fi >>= 1;
        }
        if (to) {
            if (mp.find(to) == mp.end()) mp[to] = del;
            else if (mp[to][0] > del[0]) {
                mp[to][0] = del[0];  mp[to][10] = del[10];
            }
        }
    }
    array<LL, 2> ans{p, q};
    for (int i=1; i<(1 << lenq); i++) {
        LL to = 0, f = 1;
        int fi = i;
        vector<int> del(11, 0);
        for (int j=0; j<lenq; j++) {
            if (fi & 1) {
                to += f * bitq[j];
                f *= 10;
            } else {
                if (fi == 0 && bitq[j] == 0) del[10] ++;
                else del[bitq[j]] ++;
            }
            fi >>= 1;
        }
        // cout << i << ' ' << to << '\n';
        if (to == 0)  continue;
        i128 fp = p, fto = to;
        i128 ji = fp * fto;
        if (ji % q != 0) continue;
        ji /= q;
        if (ji >= ((ULL)1 << 63)) continue;
        LL pto = ji;
        if (mp.find(pto) == mp.end()) continue;
        auto&ptodel = mp[pto];
        bool bo = true;
        for (int j=1; j<=9; j++) 
            if (ptodel[j] != del[j])  bo = false;
        if (!bo)  continue;
        if (ptodel[0] + ptodel[10] >= del[0] && del[0] + del[10] >= ptodel[0]) {
            ans = min(ans, {pto, to});
        }
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
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
    while(T--){
        work();
    }

   return 0;
}
