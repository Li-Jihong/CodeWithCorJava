/*
 * @Author: your name
 * @Date: 2023-03-29 11:06:12
 * @LastEditTime: 2023-03-29 11:06:52
 * @LastEditors: BH04250909
 * @Description: In User Settings Edit
 * @FilePath: \CodeWithCorJava\li-jihong\2023-03\29\Prime factorization.cpp
 */
/**
题目描述
已知正整数n是两个不同的质数的乘积，试求出较大的那个质数。
输入描述
输入只有一行，包含一个正整数n，6<n ≤2 × 1e9。
输出描述
输出只有一行，包含一个正整数p，即较大的那个质数。
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i;
    for (i = 2; i <= n; i++) {
        if (n % i == 0) {
            n /= i;
            i--;
        }
    }
    cout << i << endl;
    return 0;
}