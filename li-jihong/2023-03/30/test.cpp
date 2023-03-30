#include <bits/stdc++.h>
using namespace std;

struct accont {
    double count;
    double warn;
} a[1000 + 5];
int main(){
    int n, m;
    int flag = 0;
    double ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].count;
        a[i].warn = 0;
    }
    int x, y;
    double z;
    for(int i = 1; i <= m; i++){
        cin >> x >> y >> z;
        if(a[x].count < z)
            break;
        a[x].count -= z;
        a[y].count += floor(z);
        ans += z - floor(z);
        a[y].warn += z - floor(z);
        if(a[y].warn > 1)
            break;
    }
    printf("%.2lf\n", ans);
    return 0;
}