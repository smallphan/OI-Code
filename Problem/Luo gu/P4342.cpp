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

const int maxn = 100 + 5;
const int inf = 0x3f3f3f3f;

char c;
int n, ans;
int max[maxn][maxn], min[maxn][maxn];
struct node {
    int w, s, e;
        // s & e = 0 ==> add | s & e = 1 ==> mul
} q[maxn];

inline int maxfunc(int, int, int, int, int);
inline int minfunc(int, int, int, int, int);

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        scanf(" %c", &c), q[i].w = read();
        q[i].s = c == 't' ? 0 : 1;
        if (i == 1) q[n].e = q[i].s;
        else q[i - 1].e = q[i].s;
    }
    for (int i = 1; i <= n - 1; i++) q[i + n] = q[i];
    int lim = 2 * n - 1;
    for (int l = 1; l <= lim; l++) {
        for (int r = l; r <= lim; r++) {
            max[l][r] = -inf, min[l][r] = inf;
        }
    }
    for (int i = 1; i <= lim; i++) max[i][i] = min[i][i] = q[i].w;
    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = len; r <= lim; l++, r++) {
            for (int mid = l; mid <= r - 1; mid++) {
                if (q[mid].e == 1) {
                    max[l][r] = maxfunc(max[l][r], max[l][mid] * max[mid + 1][r], min[l][mid] * min[mid + 1][r], max[l][mid] * min[mid + 1][r], min[l][mid] * max[mid + 1][r]);
                    min[l][r] = minfunc(min[l][r], max[l][mid] * max[mid + 1][r], min[l][mid] * min[mid + 1][r], max[l][mid] * min[mid + 1][r], min[l][mid] * max[mid + 1][r]);
                } else {
                    max[l][r] = std::max(max[l][r], max[l][mid] + max[mid + 1][r]);
                    min[l][r] = std::min(min[l][r], min[l][mid] + min[mid + 1][r]);
                }
            }
        }
    }
    for (int l = 1, r = n; r <= lim; l++, r++) {
        ans = std::max(ans, max[l][r]);
    }
    printf("%d\n", ans);
    for (int l = 1, r = n; r <= lim; l++, r++) {
        if (max[l][r] == ans) printf("%d ", l);
    }
    return 0;
}

inline int maxfunc(int a, int b, int c, int d, int e) {
    return std::max(a, std::max(b, std::max(c, std::max(d, e))));
}

inline int minfunc(int a, int b, int c, int d, int e) {
    return std::min(a, std::min(b, std::min(c, std::min(d, e))));
}