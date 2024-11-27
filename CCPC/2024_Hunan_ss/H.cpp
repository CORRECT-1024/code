#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int mod = 998244353;

const int maxn=1e6+10;
int nxt[maxn];
// string s,p;

void get_nxt(string p)
{
    nxt[0]=0; nxt[1]=0;
    for (int i=1; i<p.size(); i++) {
        int j=nxt[i];
        while( j && p[j]!=p[i] )  {
            j=nxt[j];
        }
        if ( p[j] == p[i] ) nxt[i+1]=j+1;
        else nxt[i+1] = 0;
    }
}

void work() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    get_nxt(s);
    // for (int i=0; i<s.size(); i++) {
    //     cout << nxt[i] << ' ';
    // }
    // cout << '\n';
    vector<vector<int> > to(s.size() + 10, vector<int> (30, 0) );
    for (int i=1; i<=s.size(); i++) {
        for (int j=0; j<26; j++) {
            int fto = i-1;
            while (fto && s[fto] != 'a' + j) fto = nxt[fto];
            if (s[fto] == 'a' + j) fto ++;
            to[i][j] = fto;
            // cout << i << ' ' << nxt[i-1] << ' ' << (char)('a' + j) << ' ' << fto << '\n';
        }
    }

    vector<vector<LL> > dp(n+10, vector<LL> (s.size() + 10, 0));
    dp[0][0] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=0; j<s.size(); j++) {
            for (int c = 'a'; c<='z'; c++) {
                int fto = to[j][c - 'a'];
                dp[i][fto] += dp[i-1][j];
                dp[i][fto] %= mod; 
            }
        }
    }

    vector<int> bo(s.size() + 10, 1);
    for (int i=0; i<s.size(); i++) {
        if (s.substr(0, i + 1) == s.substr(s.size()-i-1, i + 1)) {
            bo[i + 1] = 0;
        }
    }

    vector<LL> num(n+10, 0);
    for (int i=0; i<=n; i++) {
        for (int j=0; j<s.size(); j++) {
            if (bo[j] )  num[i] += dp[i][j];
        }
        num[i] %= mod;
        // cout << i << ' ' << num[i] << '\n';
    }

    LL ans = 0;
    vector<vector<LL> > ddp(n+10, vector<LL> (k + 5, 0));
    ddp[0][0] = 1;
    int slen = s.size();
    for (int i=1; i<=n; i++) {
        for (int j=0; j<= i - slen; j++) {
            for (int m = 0; m < k; m ++) {
                ddp[i][m + 1] += ddp[j][m] * num[i - slen - j] % mod;
                ddp[i][m + 1] %= mod;
            }
        }
        ans += ddp[i][k] * num[n - i];
        ans %= mod;
        // cout << i << ' ';
        // cout << ddp[i][k] << ' ' << n - i << ' ' << num[n-i] << '\n';
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
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
