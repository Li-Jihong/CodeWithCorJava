//
// Created by BH on 2023-03-29.
//

/*
 题目描述
给定一个正整数n,求[1, n]范围内有多少个素数。
输入描述
一个正整数n (2≤n≤1e6) 。
输出描述
输出一个整数，表示[1, n]范围内的素数个数。
样例1
输入
6
输出
3
解释
[1, 6]范围内的素数有2、3、5,共3个

 * */

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

//bool isPrime(int n) {
//    if (n <= 1) {
//        return false;  //不是素数
//    }
//    int sqr = (int)sqrt(1.0 * n);
//    for (int i = 2; i <= sqr; i++) {
//        if (n % i == 0) {
//            return false; //不是素数
//        }
//    }
//    return true;  //都不满足条件，那就是素数
//}

const int MAXN = 1000000 + 1;
bool isPrime[MAXN];
vector<int> primes;

void getPrimes(int n) {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {  //填充法
            primes.push_back(i);
            for (int j = i + i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);

    int n;
    int ans = 0;
    scanf("%d", &n);
    getPrimes(n);
    for (int i = 0; i < primes.size(); i++) {
        ans++;
    }
    cout << ans;
    return 0;
}