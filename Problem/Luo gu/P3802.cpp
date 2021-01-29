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

double a[8], sum, ans = 1;

int main() {
    for (int i = 1; i <= 7; i++) {
        a[i] = read(), sum += a[i];
    }
    for (int i = 0; i <= 6; i++) {
        ans *= (i + 1) * a[i + 1];
        if (i != 6) ans /= sum - i;
    }
    return printf("%.3lf\n", ans), 0;
}