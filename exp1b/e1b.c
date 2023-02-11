#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

double populate(int a[], int b[], int n) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for(int i = 0; i <= n; i++)
    {
        int r = rand();
        a[i] = b[i] = r;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

double selection(int a[], int n) {
    FILE *fp = fopen("./selection.csv", "w+");
    // printf("File opened\n");
    double totalTime = 0;
    if(!fp) {
        printf("Error opening file\n");
        return -1;
    }
    fprintf(fp, "n, time\n");
    for (int i = 100; i <= n; i+=100)
    {
        // printf("%d\n", i);
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        for(int j = 0; j < i; j++) {
            int min = j;
            for(int k = j+1; k < i; k++) {
                if(a[k] < a[min]) {
                    min = k;
                }
            }
            int temp = a[j];
            a[j] = a[min];
            a[min] = temp;
        }
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += cpu_time_used;
        fprintf(fp, "%d, %f\n", i, cpu_time_used);
        
        printf("Sorted from 0 to %d in %.2fs\n", i, cpu_time_used);

        // for(int z = 0; z < i; z++) {
        //     printf("%d\n", a[z]);
        // }
        // getchar();
    }
    fclose(fp);
    fp = fopen("./selection.txt", "w+");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    return totalTime;
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

double insertion(int a[], int n) {
    FILE *fp = fopen("./insertion.csv", "w+");
    // printf("File opened\n");
    double totalTime = 0;
    if(!fp) {
        printf("Error opening file\n");
        return -1;
    }
    fprintf(fp, "n, time\n");
    //insertion sort
    //first sort from 0 to 100 the 0 to 200 and so on upto n
    for (int i = 100; i <= n; i+=100)
    {
        // printf("%d\n", i);
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        for(int j = 1; j < i; j++)
        {
            int k = j;
            // printf("%d\n", i);
            while(k > 0 && a[k] < a[k-1])
            {
                swap(&a[k], &a[k-1]);
                k--;
            }
        }
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += cpu_time_used;
        fprintf(fp, "%d, %f\n", i, cpu_time_used);
        
        printf("Sorted from 0 to %d in %.2fs\n", i, cpu_time_used);

        // for(int z = 0; z < i; z++) {
        //     printf("%d\n", a[z]);
        // }
        // getchar();
    }
    fclose(fp);
    fp = fopen("./insertion.txt", "w+");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    return totalTime;
}
    


int main()
{
    int n = 100000;
    int a[n],b[n];
    double timeToPopulate = populate(a, b, n);
    printf("Time taken to populate: %f\nSorting...\n", timeToPopulate);
    //first sort from 0 to 100 the 0 to 200 and so on upto n
    double timeToSortI = insertion(a, n);
    printf("Array sorted by insertion sort in %.2f\n", timeToSortI);
    double timeToSortS = selection(b, n);
    printf("Array sorted by selection sort in %.2f\n", timeToSortS);

    printf("Total time taken to sort: %f\n", timeToSortI + timeToSortS);
    
    return 0;
}
