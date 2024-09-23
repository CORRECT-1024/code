#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void work() {
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int u, v;
    std::cin >> u >> v;
    u--;
    v--;
    
    std::vector<int> p(n), dep(n);
    // auto dfs = [&](auto &self, int x) -> void {
    //     for (auto y : adj[x]) {
    //         if (y == p[x]) {
    //             continue;
    //         }
    //         dep[y] = dep[x] + 1;
    //         p[y] = x;
    //         self(self, y);
    //     }
    // };
    // p[0] = -1;
    // dep[0] = 0;
    // dfs(dfs, 0);
    
    // int s = std::max_element(dep.begin(), dep.end()) - dep.begin();
    
    // p[s] = -1;
    // dep[s] = 0;
    // dfs(dfs, s);
    
    // s = std::max_element(dep.begin(), dep.end()) - dep.begin();
    
    // if (dep[s] % 2 == 1) {
    //     std::cout << "No\n";
    //     return;
    // }
    
    // int dia = dep[s];
    // for (int i = 0; i < dia / 2; i++) {
    //     s = p[s];
    // }
    
    // bool ok = true;
    std::vector<int> h(n);
    auto dfs1 = [&](auto &self, int x) -> void {
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            p[y] = x;
            dep[y] = dep[x] + 1;
            self(self, y);
            h[x] = std::max(h[x], 1 + h[y]);
        }
    };
    
    int s = 0;
    p[s] = -1;
    dep[s] = 0;
    dfs1(dfs1, s);
    
    std::vector<int> a(n), b(n), c(n);
    
    const int logn = std::__lg(n);
    std::vector fl(n, std::vector<int>(logn + 1));
    std::vector fr(n, std::vector<int>(logn + 1));
    
    auto work = [&](int i) {
        fl[i][0] = i;
        fr[i][0] = i;
        b[i] = a[i] + i;
        c[i] = a[i] - i;
        for (int j = 0; (2 << j) <= i + 1; j++) {
            int ni = i - (1 << j);
            fl[i][j + 1] = c[fl[i][j]] >= c[fl[ni][j]] ? fl[i][j] : fl[ni][j];
            fr[i][j + 1] = b[fr[i][j]] > b[fr[ni][j]] ? fr[i][j] : fr[ni][j];
        }
    };
    
    auto askl = [&](int l, int r) {
        r++;
        int k = std::__lg(r - l);
        r--;
        l += (1 << k) - 1;
        return c[fl[l][k]] >= c[fl[r][k]] ? fl[l][k] : fl[r][k];
    };
    
    auto askr = [&](int l, int r) {
        r++;
        int k = std::__lg(r - l);
        r--;
        l += (1 << k) - 1;
        return b[fr[l][k]] > b[fr[r][k]] ? fr[l][k] : fr[r][k];
    };
    
    auto check = [&](int k) {
        if (k == 0) {
            return true;
        }
        // for (int i = 0; i <= k; i++) {
        //     std::cerr << a[i] << " \n"[i == k];
        // }
        // for (int i = 0; i <= k; i++) {
        //     std::cerr << b[i] << " \n"[i == k];
        // }
        // for (int i = 0; i <= k; i++) {
        //     std::cerr << c[i] + k << " \n"[i == k];
        // }
        // std::cerr << "---\n";
        int l = askr(0, k / 2), r = askl(k / 2 + 1, k);
        while (true) {
            // std::cerr << "(" << l << ", " << r << ")\n";
            if (l <= k - r) {
                if (b[l] > c[askl(l + 1, k - l)] + k) {
                    return true;
                }
                if (l == k / 2) {
                    return false;
                }
                l = askr(l + 1, k / 2);
            } else {
                if (c[r] + k >= b[askr(k - r + 1, r - 1)]) {
                    return false;
                }
                if (r == k / 2 + 1) {
                    return true;
                }
                r = askl(k / 2 + 1, r - 1);
            }
        }
        assert(false);
        return false;
    };
    
    std::vector<bool> ans(n);
    auto dfs2 = [&](auto &self, int x) -> void {
        int mx[2] {};
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            int v = 1 + h[y];
            if (v > mx[0]) {
                mx[1] = mx[0];
                mx[0] = v;
            } else if (v > mx[1]) {
                mx[1] = v;
            }
        }
        a[dep[x]] = h[x];
        work(dep[x]);
        ans[x] = check(dep[x]);
        for (auto y : adj[x]) {
            if (y == p[x]) {
                continue;
            }
            a[dep[x]] = mx[mx[0] == 1 + h[y] ? 1 : 0];
            work(dep[x]);
            self(self, y);
        }
    };
    dfs2(dfs2, s);
    
    std::vector<bool> l, r;
    while (u != v) {
        if (dep[u] > dep[v]) {
            l.push_back(ans[u]);
            u = p[u];
        } else {
            r.push_back(ans[v]);
            v = p[v];
        }
    }
    l.push_back(ans[u]);
    std::reverse(r.begin(), r.end());
    l.insert(l.end(), r.begin(), r.end());
    
    for (auto x : l) {
        std::cout << (x ? "Alice" : "Bob") << "\n";
    }
}
int main()
{
    #ifdef QHK
    freopen("qi.in","r",stdin);
    freopen("baoli.txt","w",stdout);
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