//
// Created by BH on 2023-03-30.
//

/*
 题目描述
孪生素数是指两个恰好相差2的素数。现在给定一个正整数n, 求第n对孪生素数。
输入描述
一个正整数n (1≤n≤100) 。
输出描述
输出两个素数，表示第n对孪生素数，中间用空格隔开。
样例
输入
3
输出
11 13
解释
前三对孪生素数分别是3和5、5和7、 11和13

 */
#include <cstdio>
#include <cmath>

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    int sqr = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sqr; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int getTwinPrime(int n) {
    int k = 1;
    for (int i = 0; i < n; i++) {
        do {
            k += 2;
        } while (!isPrime(k) || !isPrime(k + 2));
    }
    return k;
}

int main() {
    int n;
    scanf("%d", &n);
    int twinPrime = getTwinPrime(n);
    printf("%d %d", twinPrime, twinPrime + 2);
    return 0;
}