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

const int maxn = 80 + 5;

int a, b, c;
int cnt[maxn], ans, sum;

int main() {
    a = read(), b = read(), c = read();
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                cnt[i + j + k]++;
                if (cnt[i + j + k] > sum) {
                    sum = cnt[i + j + k], ans = i + j + k;
                } else if (cnt[i + j + k] == sum) {
                    ans = std::min(ans, i + j + k);
                }
            }
        }
    }
    return printf("%d\n", ans), 0;
}