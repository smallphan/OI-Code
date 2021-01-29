#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct nodefir {
    int end, value;
}; vector <nodefir> edge[maxn];
struct nodesec {
    int point, dis;
    bool operator < (const nodesec& data) const {
        return dis > data.dis;
    }
}; priority_queue <nodesec> heap;
int dis[maxn], path[maxn];
int n, m, s, u, v, w;
bool vis[maxn];

inline long long read();
inline void dijkstra(int);

int main() {
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        edge[u].push_back((nodefir) { v, w }), edge[v].push_back((nodefir) { u, w });
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        printf("[%d -> %d] [min distance] %-3d [path] ", s, i, dis[i]);
        vector <int> vec;
        for (int j = i; j; j = path[j]) vec.push_back(j);
        for (int j = vec.size() - 1; j >= 0; j--) {
            printf("%d", vec[j]);
            if (j) printf(" -> ");
        }
        printf("\n");
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void dijkstra(int start) {
    memset(dis, inf, sizeof(dis));
    dis[start] = 0;
    heap.push((nodesec) { start, 0 });
    while (!heap.empty()) {
        int now = heap.top().point;
        heap.pop();
        if (vis[now]) continue;
        vis[now] = true;
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i].end, value = edge[now][i].value;
            if (dis[end] > dis[now] + val) {
                dis[end] = dis[now] + value;
                path[end] = now;
                if (!vis[end]) heap.push((nodesec) { end, dis[end] });
            }
        } 
    }
}