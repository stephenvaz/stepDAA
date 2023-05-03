#include<stdio.h>
#include<strings.h>

void lcs(char str1[], char str2[]) {
    // printf("before loop -1");
    int table[20][20];
    int m = strlen(str1);
    int n = strlen(str2);
    // printf("%d %d", m, n);
    // printf("before loop 0");
    for (int i = 0; i <=m; i++)
    {
        table[i][0] = 0;
    }
    for (int i = 0; i <=n; i++) {
        table[0][i] = 0;
    }
    // fill table, if i == j
    // printf("before loop");
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
            }
            else if(table[i-1][j] >= table[i][j-1]) {
                table[i][j] = table[i-1][j];
            }
            else {
                table[i][j] = table[i][j-1];
            }
        }
        
    }
    // //table filed
    // printf("after loop");
    int lenLcs = table[m][n];
    printf("length: %d", lenLcs);

    // now to print the lcs
    char lcsString[lenLcs];
    lcsString[lenLcs] = '\0';
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(str1[i-1] == str2[j -1]) {
            lcsString[lenLcs-1] = str1[i-1];
            i--;
            j--;
            lenLcs--;
        }
        else if(table[i-1][j] > table[i][j-1]) {
            i--;
        }
        else {
            j--;
        }

    }
    printf("lcs string: %s", lcsString);

    
    
}

int main() {
    char str1[100], str2[100];
    printf("str1: ");
    scanf("%[^\n]s", str1);
    getchar();
    printf("str2: ");
    scanf("%[^\n]s", str2);   
    // printf("str1: %s", str1);
    lcs(str1, str2);
}