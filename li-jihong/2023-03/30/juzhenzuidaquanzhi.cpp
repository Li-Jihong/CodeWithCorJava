//
// Created by BH on 2023-03-30.
//

/*
题目描述
现有一个n * m大小的矩阵，矩阵中的每个元素表示该位置的权值。现需
要从矩阵左上角出发到达右下角，每次移动只能向上下左右移动一格
(不允许移动到曾经经过的位置)。求最后到达右下角时路径上所有位
置的权值之和的最大值。
输入描述
第一行两个整数n、m (2≤n≤5, 2≤m≤5)，分别表示矩阵的行数和列数;
接下来n行，每行m个整数(- 100<整数≤100)，表示矩阵每 个位置的权值。
输出描述
一个整数,表示权值之和的最大值。
样例
输入
2 2
1 2
3 4
输出
8
解释
从左上角到右下角的最大权值之和为1 + 3 + 4 = 8。
 * */

#include <cstdio>

const int MAXN = 5;
const int INF = 0x3f;
int n, m, maze[MAXN][MAXN];
bool visited[MAXN][MAXN] = {false};
int maxValue = -INF;

const int MAXD = 4;
int dx[MAXD] = {0, 0, 1, -1};
int dy[MAXD] = {1, -1, 0, 0};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y];
}

void DFS(int x, int y, int nowValue) {
    if (x == n - 1 && y == m - 1) {
        if (nowValue > maxValue) {
            maxValue = nowValue;
        }
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < MAXD; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (isValid(nextX, nextY)) {
            int nextValue = nowValue + maze[nextX][nextY];
            DFS(nextX, nextY, nextValue);
        }
    }
    visited[x][y] = false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    DFS(0, 0, maze[0][0]);
    printf("%d", maxValue);
    return 0;
}