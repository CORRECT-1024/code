// 应该是写不完了
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

vector<array<int, 3> > tree;
// {由谁创建，p，t}

void work() {
    int q;
    cin >> q;
    int id = 1;
    tree.push_back({0, 0, 0});
    vector<int> begin; begin.push_back(1);
    vector<int> end;   end.push_back(1);
    while (q --) {
        int op;  cin >> op;
        if (op == 1) {
            int x;  cin >> x;
            id ++;
            // add id  f[id] = x;
        } else if (op == 2) {
            int x, p, t;  cin >> x >> p >> t;
            // add {p, t} to tree[endx]
            
        } else if (op == 3) {
            int x;  cin >> x;
            // beginx = tree[beginx.to[fid[x]]]
        } else {
            int x, p;  cin >> x >> p;
            // 暴力跑背包可以吗？
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
    // cin >> T;
    while(T--){
        work();
    }

   return 0;
}
