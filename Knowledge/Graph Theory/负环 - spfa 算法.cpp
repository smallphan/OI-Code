#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>

namespace ips {
    inline long long read() {
        char str = getchar(); long long ans = 0, tag = 1;
        while (str < '0' || str > '9') { if (str == '-') tag = -1; str = getchar(); }
        while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
        return ans * tag;
    }
}

using namespace ips;
using namespace std;

const int maxn = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct node {
    int end, val;
}; vector<node> edge[maxn];

int dis[maxn], cnt[maxn];
bool vis[maxn];
queue<int> que;

int n, m, s, u, v, w;

inline bool spfa(int);

int main() {
    n = read(), m = read(), s = read();
    while (m--) {
        u = read(), v = read(), w = read();
        edge[u].push_back((node) { v, w });
    }
    printf("%s\n", spfa(s) ? "YES" : "NO");
    return 0;
}

inline bool spfa(int s) {
    memset(dis, inf, sizeof(dis));
    dis[s] = 0, vis[s] = true, que.push(s);
    while (!que.empty()) {
        int now = que.front();
        vis[now] = false;
        que.pop();
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i].end, val = edge[now][i].val;
            if (dis[end] > dis[now] + val) {
                dis[end] = dis[now] + val;
                cnt[end] = cnt[now] + 1;
                if (cnt[end] >= n) return true;
                if (!vis[end]) {
                    que.push(end);
                    vis[end] = true;
                }
            }
        }
    }
    return false;
}