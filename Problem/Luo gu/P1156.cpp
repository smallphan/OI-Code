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

const int maxd = 105;
const int maxg = 105;

int d, g;
int dp[maxd];
// dp[high] = max life

struct node {
    int t, f, h;
    inline bool operator < (const node& tmp) const { return t < tmp.t; }
} q[maxg];

int main() {
    d = read(), g = read();
    for (int i = 1; i <= g; i++) q[i] = (node) { read(), read(), read() };
    std::sort(q + 1, q + 1 + g);
    dp[0] = 10;
    for (int i = 1; i <= g; i++) {
        for (int j = d; j >= 0; j--) {
            if (dp[j] >= q[i].t) {
                if (j + q[i].h >= d) return printf("%d\n", q[i].t), 0;
                dp[j + q[i].h] = std::max(dp[j], dp[j + q[i].h]);
                dp[j] += q[i].f;
            }
        }
    }
    return printf("%d\n", dp[0]), 0;
}