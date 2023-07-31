//
// Created by BH on 2023-04-02.
// 算法标签：二分，递推

/*
机器人正在玩一个古老的基于 DOS 的游戏。
游戏中有 N+1座建筑——从 0到 N编号，从左到右排列。
编号为 0的建筑高度为 0个单位，编号为 i的建筑高度为 H(i)个单位。
起初，机器人在编号为 0的建筑处。
每一步，它跳到下一个（右边）建筑。
假设机器人在第 k个建筑，且它现在的能量值是 E，下一步它将跳到第 k+1个建筑。
如果 H(k+1)>E，那么机器人就失去 H(k+1)−E的能量值，否则它将得到 E−H(k+1)的能量值。
游戏目标是到达第 N个建筑，在这个过程中能量值不能为负数个单位。
现在的问题是机器人至少以多少能量值开始游戏，才可以保证成功完成游戏？

输入格式
第一行输入整数 N。
第二行是 N个空格分隔的整数，H(1),H(2),…,H(N)代表建筑物的高度。
输出格式
输出一个整数，表示所需的最少单位的初始能量值上取整后的结果。
数据范围
1≤N,H(i)≤105,
输入样例1：
5
3 4 3 2 4
输出样例1：
4
输入样例2：
3
4 4 4
输出样例2：
4
输入样例3：
3
1 6 4
输出样例3：
3
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace  std;

const int N = 100010;
int n;
int h[N];

bool check(int e)
{
    for(int i = 1; i <= n; i++){
        e = e * 2 - h[i];
        if(e >= 1e5) return true;
        if(e < 0) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);

    int l = 0, r = 1e5;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);
    return 0;
}








