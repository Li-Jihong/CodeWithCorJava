//
// Created by BH on 2023-03-30.
//
/*
 题目描述
给定两个正整数a、b,求它们的最大公约数。
输入描述
两个正整数a、b (1≤a<1e3, 1≤b<1e3)。
输出描述
输出a和b的最大公约数。
样例1
输入
12 16
输出复制
4
解释
12的约数有1、2、3、4、6、12;
16的约数有1、2、4、8、16;
因此12和16的最大公约数是4。

 */

#include <cstdio>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a % b);
    }
}

int main(){
    int a, b;
    scanf(("%d%d"), &a, &b);
    printf("%d", gcd(a, b));
}