#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int n;

int check(int row, int col, int arr[][n])
{

    for (int i = 0; i < col; i++)
    {
        if (arr[row][i])
        {
            return 0;
        }
    }
    // loop through and check if no other queen is in same row
    

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (arr[i][j])
        {
            return 0;
        }
    }

    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (arr[i][j])
        {
            return 0;
        }
    }
    return 1;
}

int queens(int arr[n][n],int col)
{
    if (col >= n)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {

        if (check(i, col, arr))
        {

            arr[i][col] = 1;

            if (queens(arr,col + 1))
            {
                return 1;
            }

            arr[i][col] = 0;
        }
    }

    return 0;
}

void printBoard(int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\t%d ", arr[i][j]);
        }
        printf("\n\n");
    }
}

int main()
{
    printf("No. of Queens(n): ");
    scanf("%d", &n);
    int arr[n][n];
    memset(arr, 0, sizeof(arr[0][0])*n*n);
    if (queens(arr,0))
    {
        printf("\nSolution:\n");
        printBoard(arr);
    }
    else
    {
        printf("\nSolution doesn't exist.\n");
    }

    return 0;
}