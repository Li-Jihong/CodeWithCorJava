//
// Created by BH on 2023-03-30.
//


/*
 题目描述
给定一个正整数n,对n的质因子中2的个数。
输入描述
一个正整数n (2≤n≤1e6) 。
输出描述
输出一个整数，表示n的质因子中2的个数。
样例
输入
40
输出
3
解释
40= 2^3 * 5^1

 */
#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int counter = 0;
    while (n % 2 == 0) {
        counter++;
        n /= 2;
    }
    printf("%d", counter);
    return 0;
}