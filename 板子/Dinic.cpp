using ll = long long;

#define INF  2147483467
const int maxn = 1000, maxm = 100000; 
int s, t;

struct Edge{
    ll to, next, weight;
};
Edge edges[maxm]; 
int edge_cnt = 1, head[maxn], cur[maxn];

void init() {
    edge_cnt = 1;
    for (int i=0; i<maxn; i++) head[i] = 0;
}
void add(int x,int y,int w){
    edges[++edge_cnt].next = head[x];
    edges[edge_cnt].to = y;
    edges[edge_cnt].weight = w;
    head[x] = edge_cnt;
}
void add2(int x, int y, int w, int p) {
    add(x, y, w);
    add(y, x, p ? 0 : w);
}

int level[maxn];
bool bfs(){
    memset(level, 0, sizeof(level));
    memcpy(cur, head, sizeof(head));
    queue<int> q;
    q.push(s);
    level[s] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != 0; i = edges[i].next){
            ll v = edges[i].to, flow = edges[i].weight;
            if (flow > 0 && level[v] == 0){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }   
    }
    return (level[t] != 0);
}

int dfs(int p = s, int cur_flow = INF){
    if (p == t) return cur_flow;
    ll ret = 0;
    for (int i = cur[p]; i != 0; i = edges[i].next){
        cur[p] = i;
        ll v = edges[i].to, vol = edges[i].weight;
        if (level[v] == level[p] + 1 && vol > 0){
            int f = dfs(v, min(cur_flow - ret, vol));
            edges[i].weight -= f;
            edges[i^1].weight += f;
            ret += f;
            if (ret == cur_flow) return ret;
        }
    }
    return ret;
}

ll dinic(){
    ll max_flow = 0;
    while (bfs()){
        max_flow += dfs();
        // cout << max_flow << '\n';
    }
    return max_flow;
}