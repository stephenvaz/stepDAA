#include<stdio.h>
#include<strings.h>

void match(char str[], char pat[], int q) {
    int str_len = strlen(str);
    int pat_len = strlen(pat);
    int pat_hash = 0, str_hash = 0, h = 1, d = 256;
    for(int i = 0; i < pat_len - 1; i++) {
        h = (h*d)%q;
    }
    for(int i = 0; i < pat_len; i ++) {
        pat_hash = (d*pat_hash + pat[i])%q;
        str_hash = (d*str_hash + str[i])%q;
    }
    for(int i = 0; i <= str_len - pat_len; i++) {
        if(pat_hash == str_hash) {

        }
        if( i < str_len - pat_len) {
            str_hash = (d*(str_hash - str[i]*h) + str[i+pat_len])%q;
            if(str_hash < 0)
                str_hash += q;
        }
    }
    print("\nMatch not found\n");
}

int main()
{
    char str1[100], str2[100];
    printf("Str1: ");
    scanf("%[^\n]s", str1);
    getchar();
    printf("pat: ");
    scanf("%[^\n]s", str2);
    printf("str1: %s\n", str1);
    printf("pat: %s\n", str2);
    match(str1, str2, 269);
    return 0;
}