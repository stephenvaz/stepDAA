#include<stdio.h>
#include<strings.h>
#include<limits.h>

void bracks(int s[][5], int i, int j) {
    if(i == j ){
        printf("A%d", i);
        return;
    }
    printf("(");
    bracks(s, i, s[i][j]);
    bracks(s,s[i][j]+1, j);
    printf(")");
}

void mcm(int p[], int n) {
    int m[n][n], s[n][n];
    memset(m, 0, sizeof(m[0][0])*n*n);
    memset(s, 0, sizeof(s[0][0])*n*n);
    int L,i,j,k,q;
    for(L = 2; L<n; L++) {
        for (i = 1; i< n-L+1; i++) {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for(k = i; k<j; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q< m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Cost is %d\n\nM\n", m[1][n-1]);
    for(int i = 1; i < n; i ++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\ns:\n");
    for(int i = 1; i < n; i ++) {
        for (int j = 1; j < n; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    printf("\npara: ");
    bracks(s,1,n-1);
}

// void mcm(int p[], int n) {
//     int m[n][n];
//     int s[n][n];
//     memset(m, 0, sizeof(m[0][0])*n*n);
//     memset(s, 0, sizeof(s[0][0])*n*n);
//     int L,i,j,k, q;
//     for(L = 2; L < n; L++) {
//         for(i = 1; i< n-L+1; i++) {
//             j = i+L-1;
//             m[i][j] = INT_MAX;
//             for(k = i; k < j; k++){
//                 q = m[i][k]+m[k+1][j] + p[i-1]*p[k]*p[j];
//                 if(q< m[i][j]) {
//                     m[i][j] = q;
//                     s[i][j] = k;
//                 }
//             }
//         }
//     }
//     for(int i = 1; i < n; i++) {
//         for (int j = 1; j <n; j++) {
//             printf("%d ", m[i][j]);
//         }
//         printf("\n");
//     }

//     for(int i = 1; i < n - 1; i++) {
//         for (int j = 1; j <n; j++) {
//             // if(i < j) {
//                 printf("%d ", s[i][j]);
//             // }
//             // else {
//             //     printf("")
//             // }
            
//         }
//         printf("\n");
//     }

// }

int main()
{
    int n = 5;
    int p[] = {5,4,6,2,7};
    mcm(p,n);
    return 0;
}