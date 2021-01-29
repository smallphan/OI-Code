#include <cstdio>

inline long long read() {
    char str = getchar(); long long ans = 0, tag = 1;
    while (str < '0' || str > '9') { tag = str == '-' ? -1 : 1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = ans * 10 + str - '0'; str = getchar(); }
    return ans * tag;
}
inline int max(int a, int b) { return a > b ? a : b; }

const int maxv = 2e4 + 5, maxn = 35;

int v, n, ans, val[maxn], dp[maxv];

int main() {
    v = read(), n = read();
    for (int i = 1; i <= n; i++) {
        val[i] = read();
        for (int j = v; j >= val[i]; j--) {
            dp[j] = max(dp[j], dp[j - val[i]] + val[i]);
        }
    }
    for (int i = 1; i <= v; i++) ans = max(ans, dp[i]);
    return printf("%d\n", v - ans), 0;
}