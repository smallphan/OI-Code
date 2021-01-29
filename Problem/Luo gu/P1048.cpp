#include <cstdio>

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

inline void chkmax(int& a, int b) { a = a > b ? a : b; };

const int maxm = 105;
const int maxt = 1e3 + 5;

int t, m;
int tim[maxm], val[maxm];
int dp[maxt], ans;

int main() {
    t = read(), m = read();
    for (int i = 1; i <= m; i++) {
        tim[i] = read(), val[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= tim[i]; j--) {
            chkmax(dp[j], dp[j - tim[i]] + val[i]);
        }
    }
    for (int i = 1; i <= t; i++) chkmax(ans, dp[i]);
    printf("%d\n", ans);
    return 0;
}