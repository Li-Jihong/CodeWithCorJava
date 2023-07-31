#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

float IY_ai(int len, float pbj_ai[], float pbj[]) {//计算i给定时 I（ai；Y)

    int k;
    float sum, IY_ai;
    sum = 0;
    IY_ai = 0;
    for (k = 0; k < len; k++) {
        if (pbj_ai[k] < 0) {
            printf("prob errr!!!\n");
            return -1;
        }
        if (pbj_ai[k] > 0.999999999) return 0;
        if (pbj_ai[k] < 0.00000001) continue;
        if (pbj[k] < 0.00000001) continue;
        // printf("..%8.6f   ",pbj[k]);
        IY_ai += pbj_ai[k] * log10(pbj_ai[k] / pbj[k]);
        // printf("%8.6f   ",pbj_ai[k]/pbj[k]);
    }
    IY_ai /= log10(2.0);
    return IY_ai;
}

void cal_pbj(int len_ai, float pbj_ai[], float pai[], float pbj[], int len_bj) {
    int n, m;
    for (m = 0; m < len_bj; m++) {
        pbj[m] = 0;
        for (n = 0; n < len_ai; n++) {
            pbj[m] += pai[n] * pbj_ai[len_bj * n + m];
        }
        // printf("%8.6f   ",pbj[m]);
    }

}

float cal_IXY(int row, int col, float pbj_ai[], float pai[], float pbj[]) {//由p(ai),p(bj|ai)来计算I(X;Y)
    int m;
    float IXY;
    IXY = 0;
    cal_pbj(row, pbj_ai, pai, pbj, col);
    for (m = 0; m < row; m++) {
        IXY += IY_ai(col, pbj_ai + m * col, pbj) * pai[m];
    }
    return IXY;
}

float cal_IXY_2(int len_air, int len_bjs, float pai_bj[], float pbj_ai[], float pai[]) {
    /*
    int m;
    float IXY_2;


    */
}

void cal_pai_bj(int len_ai, int len_bj, float pai[], float pbj_ai[], float pbj[]) {
    int m, n, k;
    float *pai_bj, pij, *temp_ai, y;
    float cnn, cnn_1;
    pai_bj = (float *) calloc(len_ai * len_bj, sizeof(float));
    temp_ai = (float *) calloc(len_ai, sizeof(float));
    printf("org  pai =..............\n");
    for (n = 0; n < len_ai; n++) {

        printf(" %f     ", pai[n]);
    }
    printf(" ..............\n");
    for (k = 0;; k++) {

        cal_pbj(len_ai, pbj_ai, pai, pbj, len_bj);
        for (m = 0; m < len_bj; m++) {
            // printf("\n");
            for (n = 0; n < len_ai; n++) {
                pai_bj[m * len_ai + n] = pai[n] * pbj_ai[n * len_bj + m];
                if (pbj[m] > 0.0000001)pai_bj[m * len_ai + n] /= pbj[m];
                // printf("%f    ",pai_bj[m*len_ai+n]);
            }
        }//pai_bj


        cnn = 0;
        for (n = 0; n < len_ai; n++) {
            for (m = 0; m < len_bj; m++) {
                pij = pai[n] * pbj_ai[n * len_bj + m];
                if (pai[n] > 0.0000001 && pai_bj[m * len_ai + n] > 0.0000001)
                    cnn += pij * log10(pai_bj[m * len_ai + n] / pai[n]);
            }
        }
        cnn /= log10(2.0);

        y = 0;
        for (n = 0; n < len_ai; n++) {
            temp_ai[n] = 0;
            for (m = 0; m < len_bj; m++) {
                if (pai_bj[m * len_ai + n] > 0.00000001)
                    temp_ai[n] += pbj_ai[n * len_bj + m] * log(pai_bj[m * len_ai + n]);
                // if(pai[n]>0.0000001 &&pai_bj[m*len_ai+n]>0.0000001) cnn +=pij*log10(pai_bj[m*len_ai+n]/pai[n]);
            }
            //printf("temp_ai[n] = %f    exp(-2)= %f\n",temp_ai[n],exp(-0.5));
            temp_ai[n] = exp(temp_ai[n]);
            // printf("...temp_ai[n] = %f    exp(-2)= %f\n",temp_ai[n],exp(-0.5));
            y += temp_ai[n];
        }
        cnn_1 = log(y) / log(2.0);

        printf("pai =..............\n");
        for (n = 0; n < len_ai; n++) {
            pai[n] = temp_ai[n] / y;
            //  printf(" %f     ",pai[n]);
        }
        //printf(" ..............\n");
        printf("\ncnn = %f    \n", cnn);
        printf("cnn_1 = %f\n", cnn_1);
        printf("\n k=....%d     \n", k);
        fflush(stdout);
        if (fabs(cnn_1 - cnn) < 0.0000001) break;

    }
    free(temp_ai);
    free(pai_bj);
}


int main(int argc, char *argv[]) {
    unsigned char *data8;
    float prop1[256] = {0};
    /*  float pbj_ai[6]={0.9,0.1,0.0,0.0,0.1,0.9};
   float pai[2]={0.95,0.05};*/
    float pbj_ai[9] = {0.9, 0.1, 0.0, 0.333333, 0.333333, 0.333334, 0.0, 0.1, 0.9};
    float pai[3] = {0.9, 0.05, 0.05};
    float pbj[3];
    float IXY;
    float p;
    cal_pai_bj(3, 3, pai, pbj_ai, pbj);
/* for(p=0;p<1.0;p+=0.005){
  pai[0]=p;
  pai[1]=1.0-p;

  IXY =cal_IXY(2,3, pbj_ai, pai ,  pbj);
 // printf("\n%f    %f    %f  \n  cap = %f\n",pbj[0],pbj[1],pbj[2],IXY);
  printf("pp=%f  IXY = %f\n",p,IXY);
 }
 */

    return 0;
}