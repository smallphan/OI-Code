#include <cstdio>

using namespace std;

const int maxn = 1e5 + 5;
struct node {
    int name, lkid, rkid;
} point[maxn];
int n, s, name, lkid, rkid;

inline long long read();
void preorder(int);
void inorder(int);
void postorder(int);

int main() {
    n = read(), s = read();
    for (int i = 1; i <= n; i++) {
        name = read(), lkid = read(), rkid = read();
        point[i] = (node) { name, lkid, rkid };
    }
    printf("[preorder]  ");
    preorder(s);
    printf("\n[inorder]   ");
    inorder(s);
    printf("\n[postorder] ");
    postorder(s);
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
void preorder(int num) {
    if (num) {
        printf("%d ", point[num].name);
        preorder(point[num].lkid);
        preorder(point[num].rkid);
    }
}
void inorder(int num) {
    if (num) {
        inorder(point[num].lkid);
        printf("%d ", point[num].name);
        inorder(point[num].rkid);
    }
}
void postorder(int num) {
    if (num) {
        postorder(point[num].lkid);
        postorder(point[num].rkid);
        printf("%d ", point[num].name);
    }
}