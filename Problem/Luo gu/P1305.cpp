#include <cstdio>

using namespace std;

const int maxn = 30;
int n, root, lson[maxn], rson[maxn];
char str[5];

inline int idx(char);
inline char find(int);
void dfs(int);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        if (!root) root = idx(str[1]);
        lson[idx(str[1])] = str[2] == '*' ? 0 : idx(str[2]);
        rson[idx(str[1])] = str[3] == '*' ? 0 : idx(str[3]);
    }
    dfs(root);
    return 0;
}

inline int idx(char ch) {
    return ch - 'a' + 1;
}
inline char find(int ch) {
    return (char) ch + 'a' - 1;
}
void dfs(int now) {
    if (now) {
        printf("%c", find(now));
        dfs(lson[now]);
        dfs(rson[now]);
    }
}