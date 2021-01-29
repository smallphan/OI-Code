/**
 * 思路：所有石子异或和为 0, 则先手必输.
 * 证明：
 * 1) 反正最终情况就是每堆都为 0, 先手必输, 所以我们考虑怎么把情况转换到这里.
 * 2) 如果异或和的最高位为 i, 则有一堆石子第 i 位为 1 (不然怎么会有 i 位).
 * 3) 设 a 就为那堆石子, 其他堆石子异或和设为 x, 总异或和设为 k, 则 a ^ x = k, 把 a 变成 (a ^ k), 那么后手面对的则是 (a ^ k) ^ x = 0.
 * 4) 举个例子: 11001 ^ 11100 = 101, 则有 (11001 ^ 101) ^ 11100 = 0.
 * 5) 如果现在的异或和已经为 0 了 (不为最终情况), 那么怎么转换异或和都不能为0.
 * 6) 根据 3, 4, 5 点得出: 如果先手异或和不为 0, 可以一步让后手的情况为异或和为 0; 如果先手异或和为 0, 那么后手异或和就不为 0.
 * 7) 终于开始进行游戏了, 如果现在先手面对的情况异或和不为 0, 则一直让后手异或和为 0, 最后面对最终情况, 后手输, 则先手赢; 如果先手面对的情况异或和为 0, 后手则赢.
 **/

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

int t, n;

inline void work();

int main() {
    t = read();
    while (t--) work();
    return 0;
}

inline void work() {
    n = read();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans ^= read();
    }
    puts(ans ? "Yes" : "No");
}