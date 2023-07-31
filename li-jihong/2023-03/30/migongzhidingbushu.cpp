//
// Created by BH on 2023-03-30.
//

/*
题目描述
现有一-个n* m大小的迷宫，其中1表示不可通过的墙壁，0 表示平地。
每次移动只能向上下左右移动一格(不允许移动到曾经经过的位置)，
且只能移动到平地上。现从迷宫左上角出发，问能否在恰好第k步时到达
右下角。
输入描述
第一行三个整数n、m、k (2≤n≤5,2≤m≤5,2≤k≤n*m) ，分别表示迷
宫的行数、列数、移动的步数;
接下来n行，每行m个整数(值为θ或1),表示迷宫 。
输出描述
如果可行，那么输出Yes，否则输出No。
样例1
输入
3 3 4
0 1 0
0 0 0
0 1 0
输出
Yes
解释
假设左上角坐标是(1, 1)，行数增加的方向为x增长的方向,列数增加的
方向为y增长的方向。
可以得到从左上角到右下角的步数为4的路径为: (1,1)=>(2,1)=>(2,2)
=>(2,3)=>(3, 3)。
样例2
输入
3 3 6
0 1 0
0 0 0
0 1 0
输出
No
解释
由于不能移动到曾经经过的位置，因此无法在恰好第6步时到达右下角。
 * */
#include <cstdio>

const int MAXN = 5;
int n, m, k, maze[MAXN][MAXN];
bool visited[MAXN][MAXN] = {false};
bool canReach = false;

const int MAXD = 4;
int dx[MAXD] = {0, 0, 1, -1};
int dy[MAXD] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y];
}

void DFS(int x, int y, int step) {
    if (canReach) {
        return;
    }
    if (x == n - 1 && y == m - 1) {
        if (step == k) {
            canReach = true;
        }
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < MAXD; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (step < k && isValid(nextX, nextY)) {
            DFS(nextX, nextY, step + 1);
        }
    }
    visited[x][y] = false;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    DFS(0, 0, 0);
    printf(canReach ? "Yes" : "No");
    return 0;
}