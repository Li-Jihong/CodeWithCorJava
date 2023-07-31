//
// Created by BH on 2023-03-31.
//

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
const LL maxn = 1e06+7;
const LL N=1e05;
pair<int,int>pl;
priority_queue<LL , vector<LL>, greater<LL> >t;
priority_queue<LL> q;
int cmp(int a,int b)
{
    return a<b;
}
int prime[N+5],cnt;//素数筛模板
bool st[N+5];
void init(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
            prime[cnt++]=i;
        for(int j=0;j<cnt&&prime[j]*i<=n;j++)
        {
            st[prime[j]*i]=true;
            if(i%prime[j]==0)
                break;
        }
    }
}
bool vis[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    LL l,r;
    cin>>l>>r;
    init(sqrt(r)+4);//筛出(L,R)范围内所有可能存在的因子
    for(int i=0;i<cnt;i++)
    {
        LL p=prime[i];
        //大于等于L的最小的p的倍数P0 =（L+P-1）/P*P,P是素数，所以P0=max(P*2,(L+P-1)/P*P)
        for(LL j=max(p*2,(p+l-1)/p*p);j<=r;j+=p)//埃式筛法
        {
            vis[j-l]=true;
        }
    }
    for(int i=0;i<r-l;i++)
    {
        if(vis[i]==false&&i+l>1)
            cout<<i+l<<endl;
    }
    return 0;
}
