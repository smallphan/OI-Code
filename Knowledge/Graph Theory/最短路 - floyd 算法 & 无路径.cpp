#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
int n, m, u, v, w, edge[maxn][maxn];

inline long long read();

int main() {
    memset(edge, inf, sizeof(edge));
    n = read(), m = read();
    for (int i = 1; i <= n; i++) edge[i][i] = 0;
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        edge[u][v] = edge[v][u] = min(edge[u][v], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (edge[i][j] != inf && i != j) {
                printf("[%d -> %d] [min distance] %d\n", i, j, edge[i][j]);
            }
        }
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}