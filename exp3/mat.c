#include <stdio.h>
#include <time.h>

void printarr(int a[][2])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d    ", a[i][j]);
		}
		printf("\n\n");
	}
}

void userInput(int a[][2])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int input;
			scanf("%d", &input);
			a[i][j] = input;
		}
	}
}

int main()
{
	int mat1[2][2], mat2[2][2], matres[2][2];
	int m1, m2, m3, m4, m5, m6, m7;

	printf("Matrix 1:-\n");
	userInput(mat1);
	printf("Matrix 2:-\n");
	userInput(mat2);
	printf("\nMatrix 1:-\n");
	printarr(mat1);
	printf("Matrix 2:-\n");
	printarr(mat2);

	//strassen multiplication algorithm
	clock_t start, end;
	double cpu_time_used;
	start = clock();
	m1 = (mat1[0][0] + mat1[1][1]) * (mat2[0][0] + mat2[1][1]);
	m2 = (mat1[1][0] + mat1[1][1]) * mat2[0][0];
	m3 = mat1[0][0] * (mat2[0][1] - mat2[1][1]);
	m4 = mat1[1][1] * (mat2[1][0] - mat2[0][0]);
	m5 = (mat1[0][0] + mat1[0][1]) * mat2[1][1];
	m6 = (mat1[1][0] - mat1[0][0]) * (mat2[0][0] + mat2[0][1]);
	m7 = (mat1[0][1] - mat1[1][1]) * (mat2[1][0] + mat2[1][1]);

	matres[0][0] = m1 + m4 - m5 + m7;
	matres[0][1] = m3 + m5;
	matres[1][0] = m2 + m4;
	matres[1][1] = m1 - m2 + m3 + m6;
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Matrix1 X Matrix2:-\n");
	printf("Strassen(time): %f\n", cpu_time_used);
	printarr(matres);

	//itterative multiplication algorithm
	int res[2][2] = {0};
	start = clock();
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
	end = clock();
	cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Matrix1 X Matrix2:-\n");
	printf("Itterative(time): %f\n", cpu_time_used);
	printarr(res);
	return 0;
}
