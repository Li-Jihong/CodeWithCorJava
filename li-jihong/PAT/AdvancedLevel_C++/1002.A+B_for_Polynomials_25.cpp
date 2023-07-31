//
// Created by BH on 2023-07-12.
//

/*
 * lijihong's rule
 * */
#include<iostream>
using namespace std;

float c[1001];

int main()
{
    int a, b, k;
    float coe;
    scanf("%d", &k);
    int cnt = 0;
    for(int i = 0; i < k; i++){
        cin >> cnt >> coe;
        c[cnt] += coe;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        cin >> cnt >> coe;
        c[cnt] += coe;
    }
    cnt = 0; //clean cnt to 0
    for(int i = 0; i < 1001; i++){
        if(c[i] != 0.0)
            cnt += 1;
    }
    printf("%d", cnt);
    for(int i = 1000; i >= 0; i--){
        if(c[i] != 0.0)
            printf(" %d %.1f", i , c[i]);
    }
    return 0;
}


/*
 * liuchuo's rule
 * */
/*
#include <iostream>
using namespace std;
int main() {
    float c[1001] = {0};
    int m, n, t;
    float num;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (c[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
*/