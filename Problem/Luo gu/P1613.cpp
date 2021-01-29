#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 65, inf = 0x3f3f3f3f;
int n, m, u, v, dis[maxn][maxn];
bool can[maxn][maxn][maxn];

inline long long read();

int main() {
    memset(dis, inf, sizeof(dis));
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        can[u][v][0] = true;
        dis[u][v] = 1;
    }
    for (int l = 1; l <= 64; l++) {
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= n; k++) {
                for (int j = 1; j <= n; j++) {
                    if (can[i][k][l - 1] && can[k][j][l - 1]) {
                        can[i][j][l] = true;
                        dis[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    printf("%d\n", dis[1][n]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}