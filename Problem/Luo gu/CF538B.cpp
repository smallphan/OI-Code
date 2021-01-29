#include <bits/stdc++.h>

int n, bit, num[8];

inline bool check();

int main() {
    scanf("%d", &n);
    while (++bit && n) {
        num[bit] = n % 10;
        n /= 10;
    }
    int ans = 0;    
    for (int i = 1; i <= 7; i++) ans = std::max(ans, num[i]);
    printf("%d\n", ans);
    while (check()) {
        int ans = 0;
        for (int i = 7; i >= 1; i--) {
            ans *= 10;
            if (num[i]) {
                num[i]--;
                ans++;
            }
        }
        printf("%d ", ans);
    }
    return 0;
}

inline bool check() {
    for (int i = 1; i <= 7; i++) {
        if (num[i]) return true;
    }
    return false;
}