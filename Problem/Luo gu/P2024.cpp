#include <cstdio>

using namespace std;

const int maxn = 5e4 + 5;
int n, m, op, u, v, tot;

inline long long read();
inline void work();
namespace mode {
    int fat[maxn << 2];
    inline void init();
    inline int find(int);
    inline void merge(int, int);
}

int main() {
    n = read(), m = read(), mode::init();
    while (m--) work();
    printf("%d\n", tot);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void work() {
    op = read(), u = read(), v = read();
    if (u > n || v > n) tot++;
    else if (op == 1) {
        if (mode::find(u + n) == mode::find(v) || mode::find(u) == mode::find(v + n)) tot++;
        else {
            mode::merge(u, v);
            mode::merge(u + n, v + n);
            mode::merge(u + n + n, v + n + n);
        }
    } else if (op == 2) {
        if (mode::find(u) == mode::find(v) || mode::find(u) == mode::find(v + n)) tot++;
        else {
            mode::merge(u + n, v);
            mode::merge(u + n + n, v + n);
            mode::merge(u, v + n + n);
        }
    }
}
namespace mode {
    inline void init() {
        for (int i = 1; i <= n * 3; i++) fat[i] = i;
    }
    inline int find(int now) {
        return now == fat[now] ? now : (fat[now] = find(fat[now]));
    }
    inline void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) fat[u] = v;
    }
}