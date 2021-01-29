#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int end, pos;
}; vector <node> query[maxn];
vector <int> edge[maxn];
int n, q, s, u[maxn], v[maxn];
int lca[maxn], fat[maxn], dep[maxn];
bool vis[maxn];

inline long long read();
namespace unionset {
    void init();
    int find(int);
    void merge(int, int);
}
void tarjan(int, int);
int dis(int, int, int);

int main() {
    n = read(), q = read(), s = read(), vis[s] = true;
    unionset::init();
    for (int i = 1; i <= n - 1; i++) {
        u[0] = read(), v[0] = read();
        edge[u[0]].push_back(v[0]), edge[v[0]].push_back(u[0]);
    }
    for (int i = 1; i <= q; i++) {
        u[i] = read(), v[i] = read();
        query[u[i]].push_back((node) { v[i], i });
        query[v[i]].push_back((node) { u[i], i });
    }
    tarjan(s, s);
    for (int i = 1; i <= q; i++) {
        printf("[%-2d-> %-2d] [dis] %d\n", u[i], v[i], dis(u[i], v[i], lca[i]));
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
namespace unionset {
    void init() {
        for (int i = 1; i <= n; i++) fat[i] = i;
    }
    int find(int now) {
        if (now == fat[now]) return now;
        else return fat[now] = find(fat[now]);
    }
    void merge(int fir, int sec) {
        fir = find(fir), sec = find(sec);
        if (fir != sec) fat[fir] = sec;
    }
}
void tarjan(int now, int fat) {
    dep[now] = dep[fat] + 1;
    for (int i = 0; i < edge[now].size(); i++) {
        int end = edge[now][i];
        if (end == fat) continue;
        tarjan(end, now);
        unionset::merge(end, now);
        vis[end] = true;
    }
    for (int i = 0; i < query[now].size(); i++) {
        int end = query[now][i].end, pos = query[now][i].pos;
        if (vis[end]) lca[pos] = unionset::find(end);
    }
}
int dis(int u, int v, int lca) {
    return dep[u] + dep[v] - 2 * dep[lca];
}