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
    FILE *fp = fopen("./selection.txt", "w+");
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
    return totalTime;
}


int main()
{
    clock_t start, end;
    double cpu_time_used;
    
    // code goes here
    // int n = 1000000;
       int n = 100000; 
         // 400000
    int a[n],b[n];
    //populate array with random integers
    // for(int i = 0; i < n; i++)
    // {
    //     int r = rand();
    //     a[i] = b[i] = r;
    // }
    double timeToPopulate = populate(a, b, n);
    printf("Time taken to populate: %f\nSorting...\n", timeToPopulate);
    
    // //sort array using insertion sort
    // for(int i = 1; i < n; i++)
    // {
    //     int j = i;
    //     printf("%d\n", i);
    //     while(j > 0 && a[j] < a[j-1])
    //     {
    //         int temp = a[j];
    //         a[j] = a[j-1];
    //         a[j-1] = temp;
    //         j--;
    //     }
    // }

    //selection sort
    //first sort from 0 to 100 the 0 to 200 and so on upto n
    double timeToSort = selection(b, n);
    printf("Array sorted in %.2f\n", timeToSort);
    // code ends here
    // end = clock();
    // cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("Time taken: %f\n", cpu_time_used);
    
    
    // print sorted array

    // for(int i = 0; i < 101; i++)
    // {
    //     // if(a[i] < 1000)
    //     printf("%d\n", a[i]);
    // }
    return 0;
}
