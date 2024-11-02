#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    string s;
    cin >> s;
    int q;  cin >> q;
    int num = 0;
    vector<int> bo(s.size() + 10, 0);
    for (int i=3; i<s.size(); i++) {
        if (s[i-3] == '1' && s[i-2] == '1' && s[i-1] == '0' && s[i] == '0') {
            bo[i] = 1;  num ++;
        }
    }
    while (q --) {
        int id, val;  cin >> id >> val;
        id --;
        if (s[id] != '0' + val) {
            s[id] = '0' + val;
            for (int i=id; i<min((int)s.size(), id + 4); i++) {
                if (bo[i] ) {
                    bo[i] = 0;  num --;
                } else if (i >= 3) {
                    if (s[i-3] == '1' && s[i-2] == '1' && s[i-1] == '0' && s[i] == '0') {
                        bo[i] = 1;  num ++;
                    }
                }
            }
        }
        if (num ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
    while(T--){
        work();
    }

   return 0;
}
