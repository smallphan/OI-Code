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

typedef unsigned long long ull;

const int maxn = 1e5 + 5;
const ull base = 998244353;

char str[maxn];
int len, q, l, r;
ull hash[maxn], p[maxn];

inline ull get(int, int);

int main() {
    q = read(), scanf("%s", str + 1);
    len = std::strlen(str + 1);
    p[0] = 1;
    for (int i = 1; i <= len; i++) {
        hash[i] = hash[i - 1] * base + str[i];
        p[i] = p[i - 1] * base;
    }
    while (q--) {
        l = read(), r = read();
        printf("%llu\n", get(l, r));
    }
}

inline ull get(int l, int r) {
    return hash[r] - hash[l - 1] * p[r - l + 1];
}