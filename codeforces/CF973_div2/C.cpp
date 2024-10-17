#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    string s = "1";
    string ss;
    for (int i=1; i<=n; i++) ss += '0';
    cout << "? " << ss << endl;
    int p;  cin >> p;
    if (p ) {
        cout << "! " << ss << endl;
        return;
    }
    bool bo = true;
    int i = 1;
    for (i=1; i<n; i++) {
        if (bo) {
            string fs = s + '1';
            cout << "? " << fs << endl;
            cin >> p;
            if (p ) {
                s += '1';
            } else {
                fs = s + '0';
                cout << "? " << fs << endl;
                cin >> p;
                if (p ) {
                    s += '0';
                } else {
                    bo = false;
                    i --;
                }
            }
        } else {
            string fs = '1' + s;
            cout << "? " << fs << endl;
            cin >> p;
            if (p ) {
                s = fs;
            } else {
                s = '0' + s;
            }
        }
    }
    cout << "! " << s << endl;
}
int main()
{
    // #ifdef QHK
    // freopen("qi.in","r",stdin);
    // freopen("qi.out","w",stdout);
    // #endif
    // ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // scanf("%d",&T);
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
