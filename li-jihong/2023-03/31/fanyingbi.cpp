//
// Created by BH on 2023-03-31.
//

/*
小明正在玩一个“翻硬币”的游戏。

桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。

比如，可能情形是：**oo***oooo

如果同时翻转左边的两个硬币，则变为：oooo***oooo

现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？

我们约定：把翻动相邻的两个硬币叫做一步操作。
 输入格式
两行等长的字符串，分别表示初始状态和要达到的目标状态。

输出格式
一个整数，表示最小操作步数

数据范围
输入字符串的长度均不超过100。
数据保证答案一定有解。
输入样例1：
**********
o****o****
输出样例1：
5
输入样例2：
*o**o***o***
*o***o**o***
输出样例2：
1

 * */
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define pb push_back

const int N = 110;
int n;
char start[N], endd[N];

void turn (int i){
    if(start[i] == '*') start[i] = 'o';
    else start[i] = '*';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    cin >> start >> endd;
    n = strlen(start);
    int res = 0;
    for(int i = 0; i < n - 1; i ++){
        if(start[i] != endd[i]){
            turn(i), turn(i + 1);
            res ++ ;
        }
    }
    cout << res << endl;
    return 0;
}

