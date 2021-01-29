#include <bits/stdc++.h>

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        if (k) k--, printf("%d %d ", i * 2, i * 2 - 1);
        else printf("%d %d ", i * 2 - 1, i * 2);
    }
    return 0;
}