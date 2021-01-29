#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int end, value;
}; vector <node> edge[maxn];
int n, m, a, b, c;

inline long long read();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        a = read(), b = read(), c = read();
        edge[a].push_back((node) { b, c });
        edge[b].push_back((node) { a, c });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < edge[i].size(); j++) {
            printf("[%d->%d]%d\n", i, edge[i][j].end, edge[i][j].value);
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