/**
 * 看完题后 可以考虑 dp
 * 1) 设置状态: dp[i] 表示 i 点到 n 点 路径总长度的 期望值
 * 2) 设置边界: dp[n] = 0, 终点到终点的 路径总长度的 期望肯定为 0
 * 3) 考虑转移方程: 设存在一条从 u 到 v 且边权为 w 的边, 则 dp[v] += (dp[u] + w) / degree[v]
 * 4) 可以考虑建反图 用拓扑排序逆序转移
 **/

#include <bits/stdc++.h>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

const int maxn = 1e5 + 5;
const int maxm = maxn << 1;

int n, m, u, v, w;
int in[maxn], degree[maxn];
double dp[maxn];

struct node {
    int u, v, w;
} edge[maxm];
int fir[maxn], cnt;

std::queue<int> q;
bool inq[maxn];

inline void addedge(int, int, int);
inline void topo();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        addedge(v, u, w);
        in[u]++, degree[u]++;
    }
    topo();
    return printf("%.2lf\n", dp[1]), 0;
}

inline void addedge(int u, int v, int w) {
    edge[++cnt] = (node) { fir[u], v, w }, fir[u] = cnt;
}

inline void topo() {
    q.push(n), inq[n] = true;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();
        for (int i = fir[u]; i; i = edge[i].u) {
            int v = edge[i].v, w = edge[i].w;
            if (inq[v]) continue;
            in[v]--;
            dp[v] += (dp[u] + w) / degree[v];
            if (!in[v]) {
                inq[v] = true;
                q.push(v);
            }
        }
    }
}