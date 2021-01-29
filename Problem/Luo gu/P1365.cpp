#include <bits/stdc++.h>

int n; char c;
double ans, len;

int main() {
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%c", &c);
        switch (c) {
            case 'o' : ans += 2 * (len++) + 1; break;
            case 'x' : len = 0; break;
            case '?' : ans += len + 0.5, len = (len + 1) / 2; break;
        }
    }
    return printf("%.4lf", ans), 0;
}