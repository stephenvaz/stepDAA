#include <stdio.h>

void uip(int a[2][2])
{
    int temp;
    printf("\nenter mat:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &temp);
            a[i][j] = temp;
        }
}

void printMat(int a[][2])
{
    printf("\n");
    for (int i = 0; i < 2; i++)
    {
        {
            for (int j = 0; j < 2; j++)
                printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[2][2], b[2][2], c[2][2];
    int p, q, r, s, t, u, v;
    uip(a);
    uip(b);
    p = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    q = b[0][0] * (a[1][0] + a[1][1]);
    r = a[0][0] * (b[0][1] - b[1][1]);
    s = a[1][1] * (b[1][0] - b[0][0]);
    t = b[1][1] * (a[0][0] + a[0][1]);
    u = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    v = (b[1][0] + b[1][1]) * (a[0][1] - a[1][1]);
    c[0][0] = p + s - t + v;
    c[0][1] = r + t;
    c[1][0] = q + s;
    c[1][1] = p + r - q + u;

    // printf("\n%d %d\n%d %d", p+s-t+v,r+t,q+s,p+r-q+u);
    // printMat(a);
    // printMat(b);
    // output from strassen
    printMat(c);
    int d[2][2] = {0};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                d[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    // int d[2][2] = {0};
    // // start = clock();
    // for (int i = 0; i < 2; i++)
    // {
    // 	for (int j = 0; j < 2; j++)
    // 	{
    // 		for (int k = 0; k < 2; k++)
    // 		{
    // 			d[i][j] += a[i][k] * b[k][j];
    // 		}
    // 	}
    // }
    // printMat(d);
    printMat(d);
}