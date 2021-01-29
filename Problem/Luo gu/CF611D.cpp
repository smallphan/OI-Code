#include <cstdio>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 5e3 + 5;

char c;
int n, num[maxn], dp[maxn][maxn];
int sum[maxn][maxn], lcp[maxn][maxn];

inline bool check(int, int, int, int);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c);
        num[i] = c - '0';
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= 1; j--) {
            if (num[i] != num[j]) lcp[i][j] = 0;
            else lcp[i][j] = lcp[i + 1][j + 1] + 1;
        }
    }
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            if (!num[i - j + 1]) continue;
            dp[i][j] = (dp[i][j] + sum[i - j][min(j - 1, i - j)]) % mod;
            if (i - j >= j && check(i - j - j + 1, i - j, i - j + 1, i)) {
                dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
            }
        }
        for (int j = 1; j <= i; j++) {
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
        }
    }
    printf("%d", sum[n][n]);
    return 0;
}

inline bool check(int a, int b, int c, int d) {
    if (b - a != d - c) return b - a < d - c;
    if (lcp[a][c] > b - a) return false;
    return num[a + lcp[a][c]] < num[c + lcp[a][c]];
}