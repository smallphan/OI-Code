#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 105;
const int maxm = (1 << 10) + 5;
int n, m, ans;
int map[maxn], sum[maxm];
int dp[3][maxm][maxm];

inline long long read();
inline void input();
inline void ouput();
inline void init();
inline void work();
inline int get(int);

int main() {
    input();
    init();
    work();
    ouput();
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void input() {
    n = read(), m = read();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            map[i] = map[i] << 1;
            map[i] += (ch == 'H');
        }
    }
}
inline void ouput() {
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {
            ans = max(ans, dp[(n - 1) % 3][i][j]);
        }
    }
    printf("%d\n", ans);
}
inline void init() {
    for (int i = 1; i < (1 << m); i++) sum[i] = get(i);
    for (int i = 0; i < (1 << m); i++) {
        if (i & map[0] || i & (i << 1) || i & (i << 2)) continue;
        dp[0][i][0] = sum[i];
    }
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (i & j || i & (i << 1) || i & (i << 2) || j & (j << 1) || j & (j << 2)
            || i & map[0] || j & map[1]) continue;
            dp[1][i][j] = sum[i] + sum[j];
        }
    }
}
inline void work() {
    for (int k = 2; k < n; k++) {
        for (int i = 0; i < (1 << m); i++) {
            if (i & map[k - 1] || i & (i << 1) || i & (i << 2)) continue;
            for (int j = 0; j < (1 << m); j++) {
                if (j & map[k] || i & j || j & (j << 1) || j & (j << 2)) continue;
                for (int l = 0; l < (1 << m); l++) {
                    if (l & map[k - 2] || j & l || i & l || l & (l << 1) || l & (l << 2)) continue;
                    dp[k % 3][i][j] = max(dp[k % 3][i][j], dp[(k - 1) % 3][l][i] + sum[j]);
                }
            }
        }
    }
}
inline int get(int num) {
    int tot = 0;
    while (num && ++tot) num -= num & (-num);
    return tot;
}