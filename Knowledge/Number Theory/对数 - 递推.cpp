#include <cstdio>

using namespace std;

const int maxn = 1e4 + 5;
int n, log[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) log[i] = log[i >> 1] + 1;
    for (int i = 1; i <= n; i++) {
        printf("[%d] %d\n", i, log[i]);
    }
}