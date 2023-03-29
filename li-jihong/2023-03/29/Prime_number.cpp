/*
 * @Author: your name
 * @Date: 2023-03-29 15:35:33
 * @LastEditTime: 2023-03-29 15:57:36
 * @LastEditors: BH04250909
 * @Description: In User Settings Edit
 * @FilePath: \CodeWithCorJava\li-jihong\2023-03\29\Prime number.cpp
 */
/*
题目描述
给定一个正整数N，请你输出N以内(不包含N)的质数以及质数的个数。
输入描述
输入一行，包含一个正整数N。1≤N≤1e3
输出描述
共两行。
第1行包含若干个素数，每两个素数之间用一个空格隔开，素数从小到大输出。
第2行包含一个整数，表示N以内质数的个数。
输入输出样例
示例
输入
10
输出
2 3 5 7
4
*/
#include<bits/stdc++.h> //引用标准库
using namespace std;

int main() //主函数
{
    int n;
    cin>>n; //输入n
    bool prime[n+1]; //定义一个布尔数组，表示从2到n的数是否为素数
    memset(prime,true,sizeof(prime)); //初始化数组，全部设置为true
    for(int p=2;p*p<=n;p++) //从2到根号n循环，每次找出一个素数p
    {
        if(prime[p]==true) //如果p是素数
        {
            for(int i=p*p;i<=n;i+=p) //将p的倍数全部标记为非素数
            {
                prime[i]=false;
            }
        }
    }
    int count=0; //记录素数的个数
    for(int p=2;p<n;p++) //输出素数
    {
        if(prime[p]) //如果p是素数
        {
            cout<<p<<" "; //输出p
            count++; //计数器加1
        }
    }
    cout<<endl<<count<<endl; //输出素数的个数
    return 0;
}
