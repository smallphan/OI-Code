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

const int maxn = 2e6 + 5;

int n, m, ans;

struct aode {
    int p, a;
    inline bool operator < (const aode& tmp) const {
        return p < tmp.p;
    }
} fam[maxn];

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        fam[i] = (aode) { read(), read() };
    }
    std::sort(fam + 1, fam + 1 + m);
    for (int i = 1; i <= m; i++) {
        if (n > fam[i].a) n -= fam[i].a, ans += fam[i].p * fam[i].a;
        else {
            ans += n * fam[i].p;
            break;
        }
    }
    return printf("%d\n", ans), 0;
}