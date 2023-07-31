//
// Created by BH on 2023-03-30.
//
/*
 题目描述
给定一一个正整数n,求n的约数个数。
输入描述
一个正整数n (2≤n≤1e6) 。
输出描述
输出一个整数，表示n的约数个数。
样例
输入
12
输出
6
解释
12的约数有1、2、 3、4、6、12, 共6个

 * */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

const int MAXN = 1000 + 1;
bool isPrime[MAXN];
vector<int> primes;

void getPrimes(int n) {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getPrimes((int)sqrt(1.0 * n));
    int result = 1;
    for (int i = 0; i < primes.size() && n > 1; i++) {
        int counter = 0;
        while (n > 1 && n % primes[i] == 0) {
            counter++;
            n /= primes[i];
        }
        if (counter > 0) {
            result = result * (counter + 1);
        }
    }
    if (n > 1) {
        result = result * 2;
    }
    printf("%d", result);
    return 0;
}