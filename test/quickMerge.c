#include <stdio.h>


void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int a[], int l, int r) {
    // int pivot = a[r]; //choose a pivot
    // int i = l   ;//-1;
    // for(int j = l; j < r; j++) {
    //     if(a[j] < pivot) {
    //         // i++;
    //         swap(&a[j], &a[i]);
    //         i++;
    //     }
    // }
    // swap(&a[i], &a[r]);
    // // i++;
    // return i;
    // selecting first element as pivot i.e l
    int pivot = a[l];
    int i = l+1;
    int j = r;
    do {
        while(a[i] <= pivot)
            i++;
        while(a[j] > pivot)
            j--;
        if(i < j) {
            swap(&a[i], &a[j]);
        }
    } while(i < j);

    //swap low with j
    swap(&a[l], &a[j]);
    return j;
}

void quicksort(int a[], int l, int r) {
    if(l< r) {
        int pi = partition(a, l,r);
        quicksort(a, l, pi-1);
        quicksort(a, pi+1, r);
    }
}

void merge(int a[], int l, int m, int r) {
    // int i, j,k;
    // int i, k;
    int n1 = m - l +1; // size of left subarray
    int n2 = r - m; // size of right sub array
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
        {L[i] = a[l+i];} // fill with left elements of array
    for(int i = 0; i < n2; i++)
        {R[i] = a[m + 1 +i];} //fill with right elements of array
    // int i, j = 0;
    	int i = 0, j = 0, k = l;
    while(i <n1 && j <n2) {
        if(L[i] < R[j]) {
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[] = {3,8,2, 6,4,1, 5,9, 7,0};
    int r = sizeof(a)/sizeof(a[0]);
    for(int i = 0; i < r; i++) 
        printf("%d ", a[i]);
    // mergeSort(a, 0,r-1);
    quicksort(a,0,r-1);
    printf("\n");
    for(int i = 0; i < r; i++) 
        printf("%d ", a[i]);
}