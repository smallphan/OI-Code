#include <cstdio>

const int maxn = 3e4 + 5, maxm = 30;
int n, m, ans, v[maxm], w[maxm], dp[maxn];

inline long long read() {
    char str = getchar(); long long ans = 0, tag = 1;
    while (str < '0' || str > '9') { tag = str == '-' ? -1 : 1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = ans * 10 + str - '0'; str = getchar(); }
    return ans * tag;
}
inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        v[i] = read(), w[i] = v[i] * read();
        for (int j = n; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    return printf("%d\n", ans), 0;
}