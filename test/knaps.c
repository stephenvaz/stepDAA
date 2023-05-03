#include<stdio.h>
#include<strings.h>

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    int n = 5;
    int cap =  5;
    int p[] = {5, 10, 2, 8 ,15};
    int w[] = {1,2,1,2,3};
    //sorting p and w
    for(int i = 1; i <n ; i ++) {
        int j = i;
        while (j > 0 && p[j]/w[j] > p[j-1]/w[j-1])
        {
            swap(&p[j], &p[j-1]);
            swap(&w[j], &w[j-1]);
            j--;
        }
        
    }
    // for(int i = 0; i < n; i ++) {
    //     printf("%d, %d\n", p[i], w[i]);
    // }
    // arrays sorted according to p/w
    //now keep assigning to knapsack and deduct the 
    //for 0/1 knapsack
    int sel[n];
    memset(sel, -1, sizeof(sel[0])*n);
    int curr_cap = cap;
    // int prof = 0;
    // for(int i = 0; i < n; i++) {
    //     if(curr_cap - w[i]>=0) {
    //         curr_cap = curr_cap - w[i];
    //         sel[i] = i;
    //         prof += p[i];
    //         printf("selected: %d\n", i+1);
    //     }

    // }
    // printf("total prof = %d", prof);

    // for fractional knapsack
    double prof = 0.0;
    for(int i = 0; i < n; i++) {
        if(curr_cap - w[i]>=0) {
            curr_cap = curr_cap - w[i];
            sel[i] = i;
            prof += (double)p[i];
            printf("selected: %d\n", i+1);
        }
        else {
            //put max that you can in it
            int max_possible = curr_cap; // max possible weight that can be put
            curr_cap = curr_cap - max_possible;
            sel[i] = i;
            printf("selected frac: (%d)%d\n", max_possible,i+1);
            prof += (double)p[i]*(double)max_possible/w[i];
            break;
        }
    }
    printf("total prof = %f", prof);
    return 0;
}