#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
int edge[maxn][maxn], path[maxn][maxn];
int n, m, u, v, w;

inline long long read();
void floyd();
void dfs(int, int, int);

int main() {
    memset(path, -1, sizeof(path));
    memset(edge, inf, sizeof(edge));
    n = read(), m = read();
    for (int i = 1; i <= n; i++) edge[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        edge[u][v] = edge[v][u] = min(edge[u][v], w);
        path[u][v] = u, path[v][u] = v;
    }
    floyd();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                printf("[%d -> %d] [min distance] %-3d [path] ", i, j, edge[i][j]);
                dfs(i, j, j);
                printf("\n");
            }
        }
    }
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (edge[i][j] > edge[i][k] + edge[k][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
}
void dfs(int start, int end, int endpoint) {
    if (start == end) {
        printf("%d -> ", start);
    } else if (path[start][end] != -1) {
        dfs(start, path[start][end], endpoint);
        printf("%d", end);
        if (end != endpoint) printf(" -> ");
    }
}