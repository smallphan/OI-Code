//从三角形的顶点走向底边，每次只能向右下方或向下方走一格，求路径所经过的点的最大加权(value)和
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 1e3 + 5;
int n, ans;
int dp[maxn][maxn], value[maxn][maxn];

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) value[i][j] = read();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + value[i][j];
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}