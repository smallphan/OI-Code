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

const int maxn = 105;

int n, sum, now, ans, a[maxn];

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read(), sum += a[i];
    }
    sum /= n;
    for (int i = 1; i <= n; i++) {
        a[i] -= sum;
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i]) continue;
        a[i + 1] += a[i];
        ans++;
    }
    return printf("%d\n", ans), 0;
}