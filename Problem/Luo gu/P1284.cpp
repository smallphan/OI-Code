#include <bits/stdc++.h>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

typedef double lf;

const int maxn = 45;
const int maxl = 805;

int n, len[maxn], sum;
bool dp[maxl][maxl];
lf ans = -1;

inline lf helen(lf, lf, lf);
inline bool check(lf, lf, lf);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        len[i] = read(), sum += len[i];
    }
    dp[0][0] = true;
    for (int k = 1; k <= n; k++) {
        for (int i = sum / 2; i >= 0; i--) {
            for (int j = sum / 2; j >= 0; j--) {
                if (i >= len[k] && dp[i - len[k]][j]) dp[i][j] = true;
                if (j >= len[k] && dp[i][j - len[k]]) dp[i][j] = true;
            }
        }
    }
    for (int i = sum / 2; i >= 0; i--) {
        for (int j = sum / 2; j >= 0; j--) {
            if (!dp[i][j] || !check(i, j, sum - i - j)) continue;
            ans = std::max(ans, helen(i, j, sum - i - j));
        }
    }
    return printf("%lld\n", ans == -1 ? -1ll : (long long) (ans * 100)), 0;
}

inline lf helen(lf a, lf b, lf c) {
    lf p = (a + b + c) / 2.0;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

inline bool check(lf a, lf b, lf c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}