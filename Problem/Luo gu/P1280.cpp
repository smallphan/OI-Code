/**
 * ~~彳艮女少白勺~~ 想法
 * 如果存在一个任务 从 p 开始 并持续 t 的时间
 * 则可以从 p 到 p+t 建立一条 边权为 t 的边
 * 然后跑 1 ~ n+1 最短路 就能求出 niko 的最短工作时间
 * 用总时间 n 减去 dis[n+1] 即为我们所求的最大空暇时间
 **/

#include <bits/stdc++.h>

#define pb push_back

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

const int maxn = 1e4 + 5;

int n, k, p, t;

struct aode {
    int v, w;
}; std::vector<aode> edge[maxn];

struct bode {
    int v, w;
    inline bool operator < (const bode& tmp) const {
        return w > tmp.w;
    }
}; std::priority_queue<bode> heap;
int dis[maxn]; 
bool vis[maxn];

inline void dijkstra();

int main() {
    n = read(), k = read();
    for (int i = 1; i <= k; i++) {
        p = read(), t = read();
        edge[p].pb((aode) { p + t, t });
    }
    for (int i = 1; i <= n; i++) {
        if (!edge[i].size()) edge[i].pb((aode) { i + 1, 0 });
    }
    dijkstra();
    return printf("%d\n", n - dis[n + 1]), 0;
}

inline void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0, heap.push((bode) { 1, 0 });
    while (!heap.empty()) {
        int now = heap.top().v;
        heap.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = 0; i < edge[now].size(); i++) {
            int v = edge[now][i].v, w = edge[now][i].w;
            if (dis[v] > dis[now] + w) {
                dis[v] = dis[now] + w;
                if (!vis[v]) heap.push((bode) { v, dis[v] });
            }
        }
    }
}