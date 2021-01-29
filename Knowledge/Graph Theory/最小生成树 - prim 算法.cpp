#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

const int maxn = 1e5 + 5, inf = 0x7f7f7f7f;
struct node {
    int next, end, value;
} edge[maxn << 2];
int first[maxn], cnt;
int n, m, s, u, v, w, ans;
int dis[maxn];
bool vis[maxn];

inline long long read();
void addedge(int, int, int);
void prim(int, int&);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read(), s = rand() % n;
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w), addedge(v, u, w);
    }
    prim(s, ans);
    printf("[min value] %d\n", ans);
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
void prim(int start, int& ans) {
    memset(dis, inf, sizeof(dis));
    ans = dis[start] = 0;
    for (int i = 1; i <= n; i++) {
        int mindis = inf, point = 0;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && mindis > dis[j]) {
                mindis = dis[j];
                point = j;
            }
        }
        dis[point] = inf;
        vis[point] = true;
        ans += mindis;
        for (int j = first[point]; j != -1; j = edge[j].next) {
            int end = edge[j].end, value = edge[j].value;
            if (!vis[end] && dis[end] > value) {
                dis[end] = value;
            }
        }
    }
}