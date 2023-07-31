//
// Created by BH on 2023-04-03.
//

/*
地图上有 N个目标，用整数 Xi,Yi表示目标在地图上的位置，每个目标都有一个价值 Wi。
注意：不同目标可能在同一位置。
现在有一种新型的激光炸弹，可以摧毁一个包含R×R个位置的正方形内的所有目标。
激光炸弹的投放是通过卫星定位的，但其有一个缺点，就是其爆炸范围，即那个正方形的边必须和 x，y轴平行。
求一颗炸弹最多能炸掉地图上总价值为多少的目标。
输入格式
第一行输入正整数 N和R，分别代表地图上的目标数目和正方形包含的横纵位置数量，数据用空格隔开。
接下来N行，每行输入一组数据，每组数据包括三个整数 Xi,Yi,Wi，分别代表目标的 x坐标，y坐标和价值，数据用空格隔开。
输出格式
输出一个正整数，代表一颗炸弹最多能炸掉地图上目标的总价值数目。
数据范围
0≤R≤109,
0<N≤10000,
0≤Xi,Yi≤5000,
0≤Wi≤1000
输入样例：
2 1
0 0 1
1 1 1
输出样例：
1
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5010;

int n, m;
int s[N][N];

int main() {
    int cnt, R;
    cin >> cnt >> R;
    R = min(5001, R);

    n = m = R;
    while (cnt --) {
        int x, y, w;
        cin >> x >> y >> w;
        x ++, y ++;
        n = max(x, n), m = max(y, m); // 确定该矩阵的边界
        s[x][y] += w;
    }

    // 预处理前缀和
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];

    int res = 0;

    // 枚举所有边长是R的矩形，枚举(i, j)为右下角
    for (int i = R; i <= n; i ++)
        for (int j = R; j <= m; j ++)
            res = max(res, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);

    cout << res;

    return 0;
}

















