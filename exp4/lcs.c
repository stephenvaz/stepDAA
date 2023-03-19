#include <stdio.h>
#include <string.h>

void lcs(char str1[], char str2[])
{
	int i, j, m, n, table[20][20];
	m = strlen(str1);
	n = strlen(str2);

	for (i = 0; i <= m; i++)
		table[i][0] = 0;
	for (i = 0; i <= n; i++)
		table[0][i] = 0;

	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				table[i][j] = table[i - 1][j - 1] + 1;
			}
			else if (table[i - 1][j] >= table[i][j - 1])
			{
				table[i][j] = table[i - 1][j];
			}
			else
			{
				table[i][j] = table[i][j - 1];
			}
		}

	int index = table[m][n];
	printf("\nLength of LCS: %d\n", index);
	char lcsAlgo[index];
	lcsAlgo[index] = '\0';

	i = m, j = n;
	while (i > 0 && j > 0)
	{
		if (str1[i - 1] == str2[j - 1])
		{
			lcsAlgo[index - 1] = str1[i - 1];
			i--;
			j--;
			index--;
		}
		else if (table[i - 1][j] > table[i][j - 1])
			i--;
		else
			j--;
	}
	printf("\nLCS: %s\n", lcsAlgo);
}

int main()
{
	char str1[20], str2[20];
	printf("String 1: ");
	scanf("%s", str1);
	printf("String 2: ");
	scanf("%s", str2);
	lcs(str1, str2);
}