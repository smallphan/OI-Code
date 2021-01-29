#include <queue>
#include <cstdio>
#include <vector>

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

queue<int> que, ans;
vector<int> edge[maxn];
int n, m, u, v, in[maxn];
bool inq[maxn];

inline void topolosort();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        edge[u].push_back(v);
        in[v]++;
    }
    topolosort();
    while (!ans.empty()) {
        printf("%d ", ans.front()), ans.pop();
    }
    return 0;
}

inline void topolosort() {
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            que.push(i);
            inq[i] = true;
        }
    }
    while (!que.empty()) {
        int now = que.front();
        ans.push(now), que.pop();
        for (int i = 0; i < edge[now].size(); i++) {
            int end = edge[now][i];
            if (inq[end]) continue;
            in[end]--;
            if (!in[end]) {
                que.push(end);
                inq[end] = true;
            }
        }
    }
}