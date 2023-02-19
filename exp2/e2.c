#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

double populate(int a[], int b[], int n) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    for(int i = 0; i < n; i++)
    {
        int r = rand();
        a[i] = b[i] = r;
    }
    end = clock();
    FILE *fp = fopen("./random.txt", "w+");
    if(!fp) {
        printf("Error opening file\n");
        return -1;
    }
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", a[i]);
    }
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}



void merge(int a[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    /* Merge the temp arrays back into arr[l..r]*/
    i = j = 0;
    k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    /* Copy the remaining elements of R[], if there
       are any */

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }   
}

void mergeSort(int a[], int l, int r) {
    // printf("\nl: %d, r: %d\n", l, r);
    //  printf("\nO l: %d, r: %d\n", l, r);
	if(l<r) {
		int m = (l+r)/2;
		//call for left array
        // printf("\nI l: %d, m: %d, r: %d\n", l, m, r);
		mergeSort(a, l, m);
        
        //call for right array
        mergeSort(a, m+1, r);
        //merge the two arrays
         merge(a, l, m, r);
	}
}

double mergeCalc(int a[], int n) {
    FILE *fp = fopen("./mergeSort.csv", "w+");
    // printf("File opened\n");
    double totalTime = 0;
    if(!fp) {
        printf("Error opening file\n");
        return -1;
    }
    fprintf(fp, "n, time\n");
    for (int i = 99; i <= n; i+=100)
    {
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        mergeSort(a, 0, i);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += cpu_time_used;
        fprintf(fp, "%d, %f\n", i+1, cpu_time_used);
        printf("Sorted from 0 to %d in %.2fs\n", i, cpu_time_used);
    }
    fclose(fp);
    fp = fopen("./mergeSort.txt", "w+");
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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i
        = (low
           - 1); // Index of smaller element and indicates
                 // the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quickSort(int a[], int low, int high)
{
    if (low < high) {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(a, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

double qC(int a[], int n) {
    FILE *fp = fopen("./quickSort.csv", "w+");
    // printf("File opened\n");
    double totalTime = 0;
    if(!fp) {
        printf("Error opening file\n");
        return -1;
    }
    fprintf(fp, "n, time\n");
    for (int i = 99; i <= n; i+=100)
    {
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        quickSort(a, 0, i);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += cpu_time_used;
        fprintf(fp, "%d, %f\n", i+1, cpu_time_used);
        printf("Sorted from 0 to %d in %.2fs\n", i, cpu_time_used);
    }
    fclose(fp);
    fp = fopen("./quickSort.txt", "w+");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    return totalTime;
}

void printArr(int a[], int n) {
	for (int i = 0; i <=n; i++)
		printf("%d\n", a[i]);
}

int main()
{
    int n = 100000;
    int a[n],b[n];
    double timeToPopulate = populate(a, b, n);
    printf("Time taken to populate: %f\nSorting...\n", timeToPopulate);
    //msort(a,n);
    //first sort from 0 to 100 the 0 to 200 and so on upto n
    // mergeSort(a,0,n);
    double mergeT = mergeCalc(a, n);
    double quickT = qC(b, n);
    printf("Time taken by  Merge Sort: %f\n", mergeT);
    printf("Time taken by  Quick Sort: %f\n", quickT);
    //printArr(a,n);
    return 0;
}
