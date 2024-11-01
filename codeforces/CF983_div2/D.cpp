#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    cin >> n;
    n --;
    // vector<vector<int> > a;
    vector<int> a(n+10, 0);
    // a.push_back(vector<int> ());
    priority_queue<array<int, 2> , vector<array<int, 2> > , greater<> > pri;
    // {len, first_id};
    int endid = 1;
    vector<int> ans(n+10, 0);
    for (int i=2; i<=n; i++) {
        cout << "? " << 1 << ' ' << i << endl;
        int p;  cin >> p;
        if (p == 0) {
            // cout << "ans[" << i << "] = 1\n";
            ans[i] = 1;
            endid = i;  break;
        }
    }
    for (int i=1; i<endid; i++) {
        ans[i] = 0;
    }
    for (int i=2; i<endid; i++) {
        // a.push_back(vector<int> ());
        a[i] = i;
        pri.push({1, i});
    }
    pri.push({2, 1});
    a[1] = endid;
    int pid = -1, num = endid-1;
    bool bo = false;
    for (int i=endid+1; i<=n; i++) {
        while (num > 1) {
            // cout << num << '\n';
            int k = pri.top()[1];
            cout << "? " << k << ' ' << i << endl;
            int p;  cin >> p;
            if (p == 1) {
                pri.pop();
                num --;
            } else {
                auto to = pri.top();  pri.pop();
                to[0] ++;
                pri.push(to);
                // a[k].push_back(i);
                ans[i] = a[k];
                a[k] = i;
                break;
            }
        }
        if (num == 1) {
            bo = true;
            pid = pri.top()[1];
            endid = i;  break;
        }
    }
    for (int i=endid; bo && i<=n; i++) {
        // a[pid].push_back(i);
        ans[i] = a[pid];
        a[pid] = i;
    }
    cout << "! ";
    for (int i=1; i<=n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main()
{
    // #ifdef QHK
    // freopen("qi.in","r",stdin);
    // freopen("qi.out","w",stdout);
    // #endif
    // ios::sync_with_stdio(false); cin.tie(0); 
    int T=1;
    cin >> T;
    while(T--){
        work();
    }

   return 0;
}
