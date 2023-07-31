//
// Created by BH on 2023-04-04.
//

/*
给定一个长度为 N的数列，A1,A2,…AN，如果其中一段连续的子序列 Ai,Ai+1,…Aj之和是 K的倍数，我们就称这个区间 [i,j]是 K倍区间。
你能求出数列中总共有多少个 K倍区间吗？
输入格式
第一行包含两个整数N和K。
以下N行每行包含一个整数 Ai。
输出格式
输出一个整数，代表K倍区间的数目。
数据范围
1≤N,K≤100000,
1≤Ai≤100000
输入样例：
5 2
1
2
3
4
5
输出样例：
6
*/

//#include <bits/stdc++.h>
#include <cstdio>

using namespace std;
const int N = 1e5 + 5;
int n, k;
int a[N], s[N];  //初始化为0

int main() {
    int res = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(s[i] % k == 0){
            res ++;
        }
    }
    printf("%d", res);
    return 0;
}











