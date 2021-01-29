#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct node {
    int next, end, value;
} edge[maxn << 1];
int first[maxn], cnt, dis[maxn];
int n, m, s, u, v, w;
bool vis[maxn];

inline long long read();
void addedge(int, int, int);
void dijkstra(int);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w), addedge(v, u, w);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        printf("[%d -> %d] [dis] %d\n", s, i, dis[i]);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(int start, int end, int value) {
    edge[++cnt] = (node) { first[start], end, value };
    first[start] = cnt;
}
void dijkstra(int start) {
    memset(dis, inf, sizeof(dis));
    dis[start] = 0;
    for (int i = 1; i <= n; i++) {
        int mindis = inf, point = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && mindis > dis[j]) {
                mindis = dis[j];
                point = j;
            }
        }
        vis[point] = true;
        for (int j = first[point]; j != -1; j = edge[j].next) {
            int end = edge[j].end, value = edge[j].value;
            if (!vis[end] && dis[point] + value < dis[end]) {
                dis[end] = dis[point] + value;
            }
        }
    }
}