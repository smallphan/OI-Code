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

const int n = 9;
const int maxn = 10;

int score[maxn][maxn] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
    { 0, 6, 7, 7, 7, 7, 7, 7, 7, 6 },
    { 0, 6, 7, 8, 8, 8, 8, 8, 7, 6 },
    { 0, 6, 7, 8, 9, 9, 9, 8, 7, 6 },
    { 0, 6, 7, 8, 9,10, 9, 8, 7, 6 },
    { 0, 6, 7, 8, 9, 9, 9, 8, 7, 6 },
    { 0, 6, 7, 8 ,8, 8, 8, 8, 7, 6 },
    { 0, 6, 7, 7, 7, 7, 7, 7, 7, 6 },
    { 0, 6, 6, 6, 6, 6, 6, 6, 6, 6 },
}, board[maxn][maxn];
bool vish[maxn][maxn], visl[maxn][maxn], visblock[maxn][maxn];
int cnt[maxn], seq[maxn] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int ans = -1;

struct node {
    int x, y;
} queue[maxn * maxn];

inline bool cmp(int, int);
inline int find(int, int);
void dfs(int, int);

int main() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = read();
            if (board[i][j]) {
                vish[i][board[i][j]] = visl[j][board[i][j]] = visblock[find(i, j)][board[i][j]] = true;
            } else cnt[i]++;
        }
    }
    std::sort(seq + 1, seq + 1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            queue[(i - 1) * n + j] = (node) { seq[i], j };
        }
    }
    dfs(1, 0);
    return printf("%d\n", ans), 0;
}

inline bool cmp(int a, int b) {
    return cnt[a] < cnt[b];
}

inline int find(int x, int y) {
    if (x <= 3) {
        if (y <= 3) return 1;
        else if (y <= 6) return 2;
        else return 3;
    } else if (x <= 6) {
        if (y <= 3) return 4;
        else if (y <= 6) return 5;
        else return 6;
    } else {
        if (y <= 3) return 7;
        else if (y <= 6) return 8;
        else return 9;
    }
}

void dfs(int now, int sum) {
    if (now == n * n + 1) {
        ans = std::max(ans, sum);
    } else {
        node dot = queue[now];
        if (board[dot.x][dot.y]) dfs(now + 1, sum + score[dot.x][dot.y] * board[dot.x][dot.y]);
        else {
            for (int i = 1; i <= n; i++) {
                if (vish[dot.x][i] || visl[dot.y][i] || visblock[find(dot.x, dot.y)][i]) continue;
                vish[dot.x][i] = visl[dot.y][i] = visblock[find(dot.x, dot.y)][i] = true;
                dfs(now + 1, sum + score[dot.x][dot.y] * i);
                vish[dot.x][i] = visl[dot.y][i] = visblock[find(dot.x, dot.y)][i] = false;
            }
        }
    }
}