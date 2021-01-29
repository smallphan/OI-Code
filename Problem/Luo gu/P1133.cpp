#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
int n, ans, value[maxn][5], dp[maxn][5];

// [1] 10 | [2] 20 & left higher | [3] 20 & left lower | [4] 30

inline long long read();

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        value[i][1] = read();
        value[i][2] = value[i][3] = read();
        value[i][4] = read();
    }
    for (int i = 2; i <= n; i++) {
        dp[i][1] = max(dp[i - 1][3], dp[i - 1][4]) + value[i][1];
        dp[i][2] = dp[i - 1][4] + value[i][2];
        dp[i][3] = dp[i - 1][1] + value[i][3];
        dp[i][4] = max(dp[i - 1][1], dp[i - 1][2]) + value[i][4];
    }
    dp[1][1] = max(dp[n][3], dp[n][4]) + value[1][1];
    dp[1][2] = dp[n][4] + value[1][2];
    dp[1][3] = dp[n][1] + value[1][3];
    dp[1][4] = max(dp[n][1], dp[n][2]) + value[1][4];
    for (int i = 1; i <= 4; i++) ans = max(ans, dp[1][i]);
    printf("%d\n", ans);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}