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

typedef long long ll;

const int maxn = 2e3 + 5;
const int lim = 2e3;

ll t, k, n, m;
ll C[maxn][maxn], sum[maxn][maxn];

inline void init();

int main() {
    t = read(), k = read(), init();
    while (t--) {
        n = read(), m = read(), m = m > n ? n : m;
        printf("%lld\n", sum[n][m]);
    }
    return 0;
}

inline void init() {
    for (int i = 0; i <= lim; i++) C[i][0] = 1;
    for (int i = 1; i <= lim; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
        }
    }
    for (int i = 1; i <= lim; i++) {
        for (int j = 1; j <= lim; j++) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if (!C[i][j]) sum[i][j]++;
        }
        sum[i][i + 1] = sum[i][i];
    }
}