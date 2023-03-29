/*
 * @Author: your name
 * @Date: 2023-03-29 15:52:22
 * @LastEditTime: 2023-03-29 15:58:02
 * @LastEditors: BH04250909
 * @Description: In User Settings Edit
 * @FilePath: \CodeWithCorJava\li-jihong\2023-03\29\Decimal in the NTH place.cpp
 */
/*
题目描述 
我们知道，整数做除法时，有时得到有限小数，有时得到无限循环小数。 
如果我们把有限小数的末尾加上无限多个0，它们就有了统—的形式。 
本题的任务是:在上面的约定下，求整数除法小数点后的第n位开始的3位数。

输入描述 输入一行三个整数: a b n，用空格分开。
α是被除数，b是除数，n是所求的小数后位置(0<a,b, n <1e9) 
输出描述 
输出一行3位数字，表示:α除以b，小数后第n位开始的3位数字。

输入输出样例
输入
1 8 1
输出
125
运行限制
最大运行时间：1s
最大运行内存: 256M
难度: 中等   标签: 数论, 快速幂, 2017, 国赛
*/

#include<iostream> 
#include<vector>

using namespace std;

typedef long long ll;

int main(){
	ll a;
	ll b;
	int n;
	cin>>a>>b>>n;
	while(n - 10 > 0){ //快速减小n,逼近第n位
		a *= 1e10; //不能*的太大，否则会溢出
		a %= b;
		n -= 10;
	}
	for(int i = 0; i < n + 2; i++){
		a *= 10;//①因为之前是对b取余得到的，所以此时的a一定小于吧，对a*10，在对b取余可获得一位数
		if(i >= n - 1){ //开始输出三个位
			cout<<a/b;	
		}
		a %= b;//①所说的取余
	}
	return 0;
} 




