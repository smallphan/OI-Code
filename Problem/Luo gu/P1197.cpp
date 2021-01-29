#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 4e5 + 5;
vector<int> edge[maxn];
int n, m, u, v, k;
int tot, dam[maxn], ans[maxn];
bool tag[maxn];

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
        u = read(), v = read();
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    k = read(), tot = n - k;
    for (int i = 1; i <= k; i++) dam[i] = read(), tag[dam[i]] = true;
    for (int i = 1; i <= n; i++) {
        if (!tag[i]) {
            for (int j = 0; j < edge[i].size(); j++) {
                int end = edge[i][j];
                if (!tag[end]) {
                    if (mode::merge(i, end)) tot--;
                }
            }
        }
    }
    ans[k + 1] = tot;
    for (int i = k; i >= 1; i--) {
        tag[dam[i]] = false, tot++;
        for (int j = 0; j < edge[dam[i]].size(); j++) {
            int end = edge[dam[i]][j];
            if (!tag[end]) {
                if (mode::merge(dam[i], end)) tot--;
            }
        }
        ans[i] = tot;
    }
    for (int i = 1; i <= k + 1; i++) printf("%d\n", ans[i]);
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
        if (u != v) {
            fat[u] = v;
            return true;
        } else return false;
    }
}