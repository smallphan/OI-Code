#include <cstdio>

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

using namespace std;

const int root = 1;
const int maxn = 1e5 + 5;

struct node {
    int go[70], pos;
} trie[maxn];

int n, m, cnt = 1, tot;
char str[maxn];

inline void insert(char*);
inline int search(char*);

int main() {
    n = read(), m = read();
    while (n--) {
        scanf("%s", str + 1);
        insert(str);
    }
    while (m--) {
        scanf("%s", str + 1);
        printf("%d\n", search(str));
    }
    return 0;
}

inline void insert(char* str) {
    int now = root;
    for (int i = 1; str[i]; i++) {
        int to = str[i] - 'A' + 1;
        if (!trie[now].go[to]) {
            trie[now].go[to] = ++cnt;
        }
        now = trie[now].go[to];
    }
    trie[now].pos = ++tot;
}

inline int search(char* str) {
    int now = root;
    for (int i = 1; str[i]; i++) {
        int to = str[i] - 'A' + 1;
        if (!trie[now].go[to]) return -1;
        now = trie[now].go[to];
    }
    return trie[now].pos;
}