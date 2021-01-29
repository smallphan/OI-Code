#include <bits/stdc++.h>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

int n, opt;
std::priority_queue<int> heap;

int main() {
    n = read();
    while (n--) {
        opt = read();
        switch (opt) {
            case 1 : heap.push(-read()); break;
            case 2 : printf("%d\n", -heap.top()); break;
            case 3 : heap.pop(); break;
        }
    }
    return 0;
}