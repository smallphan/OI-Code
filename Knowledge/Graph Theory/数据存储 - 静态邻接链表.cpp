#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int next, end, value;
} edge[maxn << 2];
int first[maxn], cnt;
int n, m, u, v, w;

inline long long read();
void addedge(int, int, int);

int main() {
    memset(first, -1, sizeof(first));
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        addedge(u, v, w), addedge(v, u, w);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = first[i]; j != -1; j = edge[j].next) {
            printf("[%d->%d] [value] %d\n", i, edge[j].end, edge[j].value);
        }
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