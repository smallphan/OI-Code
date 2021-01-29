#include <queue>
#include <cstdio>

using namespace std;

int n, m, k;
queue <int> que;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) que.push(i);
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        k++;
        if (k == m) {
            printf("%d ", now);
            k = 0;
        } else {
            que.push(now);
        }
    }
    return 0;
}