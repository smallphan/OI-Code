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

const int maxn = 1e7 + 5;

int n, a, b, c, num[maxn];
double ans;

inline void data();

int main() {
    data();
    for (int i = 1; i <= n; i++) {
        ans += 1.0 / (double) std::max(num[i], num[i - 1]);
    }
    return printf("%.3lf\n", ans), 0;
}

inline void data() {
    n = read(), a = read(), b = read(), c = read(), num[1] = read();
    for (int i = 2; i <= n; i++) {
        num[i] = ((long long) num[i - 1] * a + b) % ((int) 1e8 + 1);
    }
    for (int i = 1; i <= n; i++) {
        num[i] = num[i] % c + 1;
    }
    num[0] = num[n];
}