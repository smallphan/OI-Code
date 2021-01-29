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

const int maxn = 1e4 + 5;
const int maxt = 1e3 + 5;

int n, t;
struct node {
    int t, c, p;
        // t => time | c => beauty | p => times
} tree[maxn];
int dp[maxt];

int main() {
    t = - (read() * 60 + read()) + (read() * 60 + read()), n = read();
    for (int i = 1; i <= n; i++) {
        tree[i] = (node) { read(), read(), read() };
    }
    for (int i = 1; i <= n; i++) {
        if (tree[i].p == 0) {
            for (int j = tree[i].t; j <= t; j++) {
                dp[j] = std::max(dp[j], dp[j - tree[i].t] + tree[i].c);
            }
        } else {
            for (int k = 1; k <= tree[i].p; k++) {
                for (int j = t; j >= tree[i].t; j--) {
                    dp[j] = std::max(dp[j], dp[j - tree[i].t] + tree[i].c);
                }
            }
        }
    }
    return printf("%d\n", dp[t]), 0;
}