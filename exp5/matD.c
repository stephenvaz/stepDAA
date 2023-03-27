#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MatrixChainOrder(int p[], int n)
{
	int m[n][n];
    memset(m, 0, sizeof(m[0][0]) * n * n);

	int i, j, k, L, q;

	for (i = 1; i < n; i++)
		m[i][i] = 0;

	for (L = 2; L < n; L++) {
		for (i = 1; i < n - L + 1; i++) {
			j = i + L - 1;
			m[i][j] = INT_MAX;
			for (k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}
    printf("m Table:\n");
    for (int i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

	return m[1][n - 1];
}

int main()
{
	int arr[] = { 2, 3, 2, 4 };
    //2*3 3*5 5*4
    // 2*5 5*4
    //2*4    
    // 2*3 3*2 2*4
    // 2*2 2*4
    // 2*4
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("min cost is %d ",
		MatrixChainOrder(arr, size));

	getchar();
	return 0;
}
