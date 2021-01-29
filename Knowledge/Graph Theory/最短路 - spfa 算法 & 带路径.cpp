#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5, inf = 0x7f7f7f7f;
struct node {
    int end, val;
}; vector <node> edge[maxn];
int dis[maxn], path[maxn];
int n, m, s, u, v, w;
bool inq[maxn];

inline long long read();
inline void spfa(int);

int main() {
    n = read(), m = read(), s = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        edge[u].push_back((node) { v, w });
    }
    spfa(s);
    for (int i = 1; i <= n; i++) {
        if (i == s || dis[i] == inf) continue;
        vector <int> dot;
        printf("[%d->%d] [mindis] %d\n", s, i, dis[i]);
        for (int j = i; j; j = path[j]) dot.push_back(j);
        printf("[path]");
        for (int j = dot.size() - 1; j >= 0; j--) {
            printf("%d", dot[j]);
            if (j) printf("->");
        }
        puts("");
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline void spfa(int beg) {
    memset(dis, inf, sizeof(dis));
    queue <int> que;
    dis[beg] = 0;
    inq[beg] = true;
    que.push(beg);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        inq[now] = false;
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i].end, val = edge[now][i].val;
            if (dis[end] > dis[now] + val) {
                dis[end] = dis[now] + val;
                path[end] = now;
                if (!inq[end]) {
                    que.push(end);
                    inq[end] = true;
                }
            }
        }
    }
}