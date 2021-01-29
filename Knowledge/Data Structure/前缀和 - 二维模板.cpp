#include <cstdio>

using namespace std;

const int maxn = 1e3 + 5;
struct node { int x, y; };
int n, m, q, sum[maxn][maxn];

inline long long read();
inline int getsum(node, node);

int main() {
    n = read(), m = read(), q = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + read();
        }
    }
    while (q--) {
        node fir = (node) { read(), read() };
        node sec = (node) { read(), read() };
        printf("[%d,%d] -> [%d,%d] %d\n", fir.x, fir.y, sec.x, sec.y, getsum(fir, sec));
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline int getsum(node fir, node sec) {
    return sum[sec.x][sec.y] - sum[fir.x - 1][sec.y] - sum[sec.x][fir.y - 1] + sum[fir.x - 1][fir.y - 1];
}