//
// Created by BH on 2023-04-02.
// 算法标签：前缀和

/*
输入一个长度为n的整数序列。
接下来再输入m个询问，每个询问输入一对 l,r。
对于每个询问，输出原序列中从第l个数到第r个数的和。
输入格式
第一行包含两个整数n和m。
第二行包含n个整数，表示整数数列。
接下来m行，每行包含两个整数 l和 r，表示一个询问的区间范围。
输出格式
共m行，每行输出一个询问的结果。
数据范围
1≤l≤r≤n,
1≤n,m≤100000,
−1000≤数列中元素的值≤1000
输入样例：
5 3
2 1 3 6 4
1 2
1 3
2 4
输出样例：
3
6
10
*/

#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
int n, m;
int a[N]; //表示原数组
int s[N]; //表示前缀和数组

int main() {
    scanf("%d%d" ,&n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    while(m--){
        int l, r;
        scanf("%d%d", &l ,&r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}












