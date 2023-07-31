#include<bits/stdc++.h>

using namespace std;
int f(int a)
{

    if(a == 1 || a == 0) return 0;

    if(a != 1){
        return (f(a - 1) + f(a - 2));
    }
}
int main( )
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cout << f(i) << " ";
    }
    return 0;
}