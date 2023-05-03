#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// void swap (int *x, int *y) {
//     int t = *x;
//     *x = *y;
//     *y = t;
// }

void swap (int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}
void insertion(int a[], int n) {
    clock_t start = clock();
    // for(int i = 1; i <= n; i ++) {
    //     int k = i;
    //     while (k>0 && a[k] < a[k-1])
    //     {
    //         swap(&a[k], &a[k-1]);
    //         k--;
    //     }
    // }
    for(int i = 1; i <= n; i++) {
        int j = i;
        while(j>0 && a[j] < a[j-1])
        {
            swap(&a[j], &a[j-1]);
            j--;
        }
    }
    clock_t end = clock();
    double time =  (double) (end-start) /CLOCKS_PER_SEC;
    printf("time for insertion sort: %f", time);
}

void sel(int a[], int n) {
    // loop through the elements
    for(int i = 0; i <= n; i++) {
        int min = i;// select current ith element as min
        for (int  j = i+1; j <= n; j++) { // loop through further elements from i+1 to n
            if(a[j] < a[min]){ // if current element is less that selected ith minimum
                min = j; // then update minimum index to current index
            }
        }
        swap(&a[i], &a[min]); // swap minimum of subarray with previously selected minimum
    }
}

void printArr(int a[], int n) {
    printf("\n");
    for(int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int n = 100;
    int a[n], b[n];
    clock_t start = clock();
    for (int i = 0; i < n; i++) {
        int r = rand();
        a[i] = b[i] = r;
    }
    clock_t end = clock();
    double timeElapsed = (double)(end - start)/CLOCKS_PER_SEC;
    printf("time to populate: %f", timeElapsed);
    insertion(a,n);
    printArr(a,n);
    sel(b,n);
    printArr(b,n);
}
// 114807987
// 578354438