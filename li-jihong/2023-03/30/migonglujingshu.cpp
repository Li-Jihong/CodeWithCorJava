//
// Created by BH on 2023-03-30.
//

/*
题目描述
现有一个n * m大小的迷宫，其中1表示不可通过的墙壁，0 表示平地。
每次移动只能向上下左右移动一格(不允许移动到曾经经过的位置)，
且只能移动到平地上。求从迷宫左上角到右下角的所有可行路径的条
数。
输入描述
第一行两个整数n、m (2≤n≤5, 2≤m≤5)，分别表示迷宫的行数和列
数;
接下来n行，每行m个整数(值为θ或1)， 表示迷宫。
输出描述
一个整数,表示可行路径的条数。
样例
输入
000
010
000
输出
2
解释
假设左上角坐标是(1, 1),行数增加的方向为x增长的方向，列数增加的
方向为y增长的方向。
可以得到从左上角到右下角有两条路径:
1. (1,1)=>(1, 2)=>(1, 3)=>(2, 3)=> (3,3)
2. (1,1)=>(2,1)=>(3,1)=>(3,2)=>(3, 3)
 * */

#include <iostream>
using namespace std;

const int MAXN = 5;

int n, m, maze[MAXN][MAXN];
bool isvisited[MAXN][MAXN] = {false};
int counter = 0;

const int MAXD = 4;
int dx[MAXN] = {0, 0, 1, -1};
int dy[MAXN] = {1, -1, 0, 0};

bool isValid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !isvisited[x][y];
}

void DFS(int x, int y){
    if(x == n - 1 && y == m - 1){
        counter++;
        return;
    }
    isvisited[x][y] = true;
    for(int i = 0; i < MAXD; i++){
        int nestx = x + dx[i];
        int nexty = y + dy[i];
        if(isValid(nestx, nexty)){
            DFS(nestx, nexty);
        }
    }
    isvisited[x][y] = false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }
    DFS(0, 0);
    cout << counter;
}







