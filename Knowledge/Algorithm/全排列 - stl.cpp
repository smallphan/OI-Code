#include <cstdio>
#include <algorithm>

using namespace std;

int n, num[11] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

int main() {
    scanf("%d", &n);
    do {
        for (int i = 1; i <= n; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
    } while (next_permutation(num + 1, num + 1 + n));
    return 0;
}