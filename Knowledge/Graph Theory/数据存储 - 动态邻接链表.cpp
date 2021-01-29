#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int end, val;
}; vector<node> edge[maxn];
int n, m, u, v, w; 

inline long long read();

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read(), w = read();
        edge[u].push_back((node) { v, w });
        edge[v].push_back((node) { u, w });
    } 
    for (int i = 1; i <= n; i++) {
        for (vector<node>::iterator j = edge[i].begin(); j < edge[i].end(); j++) {
            printf("[%d -> %d] [value] %d\n", i, (*j).end, (*j).val);
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