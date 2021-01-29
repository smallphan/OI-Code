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

const int inf = 0x7f7f7f7f;

int n, now, dp, ans = -inf;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        dp = std::max(0, dp) + read();
        ans = std::max(ans, dp);
    }
    return printf("%d\n", ans), 0;
}
