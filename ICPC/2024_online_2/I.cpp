#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void work() {
    LL n;
    cin >> n;
    vector<int> b(50, 0);
    for (int i=0; i<=31; i++) {
        if (n & 1) {
            b[i] = 1;
        }
        n >>= 1;
        // cout << i << ": " << b[i] << '\n';
    }
    if (b[0] == 0 && b[1] == 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    bool bo = false;
    int p = 0;
    for (int i=31; i>=0; i--) {
        if (bo) {
            p = 0;
            if (b[i] == 1)  bo = false;
            b[i] = -1;
        } else {
            if (b[i] == 1) {
                p = 0;
                continue;
            } 
            else {
                if (p == 0) {
                    p ++;  continue;
                } else {
                    b[i] = 1;  bo = true;
                    p = 0;
                }
            }
        }
    }
    for (int i=0; i<=31; i++) {
        cout << b[i] << ' ';
        if ((i + 1) % 8 == 0) cout << '\n';
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("qi.out","w",stdout);
    #endif
    ios::sync_with_stdio(false);  cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        work();
    }

    return 0;
}