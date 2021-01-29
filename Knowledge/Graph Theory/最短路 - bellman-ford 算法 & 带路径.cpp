#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
struct node {
    int next, end, value;
} edge[maxn << 2];
int first[maxn], cnt, dis[maxn], path[maxn];
int n, m, s, u, v, w;

inline long long read();
void addedge(int, int, int);
void bellmanford(int);

int main() {
    memset(first, -1, sizeof(first));
    memset(path, -1, sizeof(path));
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w);
    }
    bellmanford(s);
    for (int i = 1; i <= n; i++) {
        if (i == s || dis[i] == inf) continue;
        vector <int> point;
        printf("[%d->%d] [min distance] %d\n", s, i, dis[i]);
        for (int j = i; j != -1; j = path[j]) point.push_back(j);
        printf("[path]");
        for (int j = point.size() - 1; j >= 0; j--) {
            printf("%d", point[j]);
            if (j != 0) printf("->");
        }
        printf("\n");
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void addedge(int start, int end, int value) {
    edge[++cnt] = (node) { first[start], end, value };
    first[start] = cnt;
}
void bellmanford(int start) {
    memset(dis, inf, sizeof(dis));
    dis[start] = 0;
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = first[i]; j != -1; j = edge[j].next) {
                int end = edge[j].end, value = edge[j].value;
                if (dis[end] > dis[i] + value) {
                    dis[end] = dis[i] + value;
                    path[end] = i;
                }
            }
        }
    }
}