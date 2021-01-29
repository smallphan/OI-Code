#include <cstdio>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        if (str == '-') tag = -1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = (ans << 3) + (ans << 1) + str - '0';
        str = getchar();
    }
    return ans * tag;
}

using namespace std;

int main() {
    printf("%d\n", read() / read());
    return 0;
}