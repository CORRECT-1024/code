#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    for (int i=-50; i<=50; i+=10) {
        for (int j=0; j<10; j++) {
            cout << "./Project1 ./Instances/25-20-300-" << i << "/rand-2-25-20-300-" << 221 + i << "-fcd-" << j << "_ext-merged.xml ./ans/25-20-300-" << i <<".txt\n";
        }
    }
}
int main()
{
    #ifdef QHK
    freopen("1.sh","w",stdout);
    #endif
    ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    // cin >> T;
    while(T--) {
        work();
    }

   return 0;
}
