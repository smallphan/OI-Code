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

const int maxn = 1e5 + 5;

int n, ans, num[maxn];
int init[maxn], tree[maxn];

namespace TR {
    inline int lowbit(int);
    inline void add(int, int);
    inline int profix(int);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) init[i] = num[i] = read();
    std::sort(init + 1, init + 1 + n);
    int size = std::unique(init + 1, init + 1 + n) - (init + 1);
    for (int i = 1; i <= n; i++) {
        num[i] = std::lower_bound(init + 1, init + 1 + size, num[i]) - init;
    }
    for (int i = n; i >= 1; i--) {
        ans += TR::profix(num[i] - 1);
        TR::add(num[i], 1);
    }
    return printf("%d\n", ans), 0;
}

namespace TR {
    inline int lowbit(int num) {
        return num & (-num);
    }

    inline void add(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) {
            tree[i] += val;
        }
    }

    inline int profix(int pos) {
        int ans = 0;
        for (int i = pos; i >= 1; i -= lowbit(i)) {
            ans += tree[i];
        }
        return ans;
    }
}