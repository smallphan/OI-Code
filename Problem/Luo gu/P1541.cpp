#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 45;
int n, m, dp[maxn][maxn][maxn][maxn], card[5], val[maxn << 3];

inline long long read();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) val[i] = read();
    while (m--) card[read()]++;
    dp[0][0][0][0] = val[1];
    for (int i = 0; i <= card[1]; i++) {
        for (int j = 0; j <= card[2]; j++) {
            for (int k = 0; k <= card[3]; k++) {
                for (int l = 0; l <= card[4]; l++) {
                    int pos = 1 + i + j * 2 + k * 3 + l * 4;
                    if (i) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + val[pos]);
                    if (j) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + val[pos]);
                    if (k) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + val[pos]);
                    if (l) dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + val[pos]);
                }
            }
        }
    }
    printf("%d\n", dp[card[1]][card[2]][card[3]][card[4]]);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}