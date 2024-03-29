//
// Created by BH on 2023-03-30.
//

/**
 提瓦特大陆.上有-个贫穷的占星术士小码哥，在占星的时候，小码哥时常需要将命运
启示他的信息与手中命运之轮上的命星一一对应，现在有n个启示和n个命星需要
对应，有时，因为命运实在太过难以言明，小码哥会将所有的启示与命星都对应
错了，此时称小码哥犯了一个巨大的错误，问一共有多少种情况可被称为“巨大的错
误”。
格式
输入格式:输入-一个正整数n
输出格式:输出一个正整数代表所求答案
输入：2
 输出：1
 */
/*
错排公式：
n个元素放在n个位置，元素编号和位置编号各不对应的种数设为D(n),则有
D(n)=(n-1)*( D(n-1) + D(n-2) ).其中 D(1) = 0,D(2) = 1.
公式推导：
当n≥3时,任意一个数k的排列在n个位置上时有两种情况：

1、当k排在第n位上时，有n-2种排列方式，即D(n-2)，比如1 2 3分别在A B C的位置上，当3放在A位置上，刚开始成了3 2 1，那么就只剩1种情况可排，2 1 3.

2、当k不在第n个位置上时，可以认为第n位上被一个新的数取代，还是（n-1）种错排，即D(n-1)。
因为k的位置有n-1种取法，所以公式为D(n)=(n-1)*( D(n-1) + D(n-2) )
*/
//错排公式的应用
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll a[21] = {0, 0, 1};
int main() {
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++)
        a[i]= (i - 1) * (a[i - 2] + a[i - 1]);
    cout<< a[n];
    return 0;
}
