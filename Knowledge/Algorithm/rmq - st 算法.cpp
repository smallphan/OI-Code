#include <cstdio>
#include <algorithm>

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

using namespace std;

const int maxn = 1e5 + 5;

int n, m, l, r;
int st[maxn][30], lg[maxn];

inline void init();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        st[i][0] = read();
    }
    init();
    while (m--) {
        l = read(), r = read();
        int s = lg[r - l + 1], k = r - (1 << s) + 1;
        printf("[%d,%d] [min] %d\n", l, r, min(st[l][s], st[k][s]));
    }
    return 0;
}

inline void init() {
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int s = 1; s <= lg[n]; s++) {
        for (int l = 1; l + (1 << s) - 1 <= n; l++) {
            int r = l + (1 << (s - 1));
            st[l][s] = min(st[l][s - 1], st[r][s - 1]);
        }
    }
}