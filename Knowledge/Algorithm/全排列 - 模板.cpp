#include <cstdio>

using namespace std;

const int maxn = 15;
int n, num[maxn];
bool vis[maxn];

void dfs(int);

int main() {
    scanf("%d", &n);
    dfs(1);
    return 0;
}

void dfs(int depth) {
    if (depth == n + 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
    } else {
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            num[depth] = i;
            vis[i] = true;
            dfs(depth + 1);
            vis[i] = false;
        }
    }
}