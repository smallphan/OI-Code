#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int beg, end, val;
    inline bool operator < (const node& data) const {
        return val < data.val;
    }
} edge[maxn << 2];
int n, m, u, v, w, ans;
bool use[maxn];

inline long long read();
namespace mode {
    int fat[maxn];
    inline void init();
    inline int find(int);
    inline bool merge(int, int);
}

int main() {
    n = read(), m = read(), mode::init();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        edge[i] = (node) { u, v, w };
    }
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i++) {
        int beg = edge[i].beg, end = edge[i].end, val = edge[i].val;
        if (mode::merge(beg, end)) {
            use[i] = true;
            ans += val;
        }
    }
    printf("[size of min built tree] %d\n", ans);
    printf("[edges used]\n");
    for (int i = 1; i <= m; i++) {
        int beg = edge[i].beg, end = edge[i].end, val = edge[i].val;
        if (use[i]) printf("[%d <-> %d] [value] %d\n", beg, end, val);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
namespace mode {
    inline void init() {
        for (int i = 1; i <= n; i++) fat[i] = i;
    }
    inline int find(int now) {
        return now == fat[now] ? now : (fat[now] = find(fat[now]));
    }
    inline bool merge(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) return fat[u] = v, true;
        else return false;
    }
}