#include<stdio.h>
#include<math.h>    
#include<stdlib.h>

void hash(int arr[]) {
    //first generate the number from arr to use in hashfunction
    int num = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("size: %d\n", size);
    for (int i = size - 1; i >= 0; i--)
    {

        // num = num*10 + arr[i];
        num += arr[i] * pow(10, size - i - 1);

    }
    
    printf("%d", num);
}

// void karp(int text[], int pattern[]) {
//     int prime = 101;
//     //hash for pattern
//     // int hash = 
//     //go throough the text
//     int pat_size = sizeof(pattern)/sizeof(pattern[0]);//gives number of digits to consider in text while hash check
//     int text_size = sizeof(text)/sizeof(text[0]);

//     for (int i = 0; i < text_size; i++)
//     {
//         //check hash
//         //if hash matches
//         //check for each digit
//         //if all digits match
//         //print the index
//     }
// }

int main()
{
    //robin karp
    //string matching

    // int text[100], pattern[100];
    int text[] = {3, 1, 4 , 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9,3};
    int pattern[] = {2, 6, 3};
    printf("size: %d\n", sizeof(pattern)/sizeof(pattern[0]));
    hash(pattern);
    return 0;

}