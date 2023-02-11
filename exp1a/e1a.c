#include <stdio.h>

#include <math.h>
// 11th func is n factorial for 0 to 20 (0,2,4,6,8,10)

void tableDouble(int start, int end, int incr, double (*f)())
{
    for (int i = start; i <= end; i += incr)
    {
        printf("\t%d\t| %f\n", i, f(i));
    }
}
void tableInt(int start, int end, int incr, int (*f)())
{
    for (int i = start; i <= end; i += incr)
    {
        printf("\t%d\t| %d\n", i, f(i));
    }
}
void tablelong(int start, int end, int incr, unsigned long long (*f)())
{
    for (int i = start; i <= end; i += incr)
    {
        printf("\t%d\t| %lld\n", i, f(i));
    }
}

int linear(int x)
{
    return x + 5; // linear function
}
double fun1(int x) { return pow(1.5, x); }
double ln(int x) { return log(x); }
double twon(int x) { return pow(2, x); }
double lnlnn(int x) { return log(log(x)); }
double rtln(int x) { return sqrt(log10(x)); }
double en(int x) { return exp(x); }
double logsqn(int x) { return pow(log2(x), 2); }

unsigned long long factorial(unsigned long f)
{
    if (f)
        return (f * factorial(f - 1));
    return 1;
}

double nloglogn(int x) { return pow(x, log2(log2(x))); }
double sqrt2logn(int x) { return pow(sqrt(2), log2(x)); }
// unsigned long long factorial (int x) {

// }
int (*fInt)(int);
double (*fDouble)(int);
unsigned long long (*fLong)(unsigned long f);
int main()
{
    printf("\tLinear(n+5)\n");
    fInt = linear;
    tableInt(0, 100, 10, fInt);
    printf("\t(3/2)^n\n");
    fDouble = fun1;
    tableDouble(0, 100, 10, fDouble);
    printf("\tln(n)\n");
    fDouble = ln;
    tableDouble(0, 100, 10, fDouble);
    printf("\t2^n\n");
    fDouble = twon;
    tableDouble(0, 100, 10, fDouble);
    printf("\tln ln n\n");
    fDouble = lnlnn;
    tableDouble(0, 100, 10, fDouble);
    printf("\tsqroot(log(n))\n");
    fDouble = rtln;
    tableDouble(0, 100, 10, fDouble);
    printf("\te^n\n");
    fDouble = en;
    tableDouble(0, 100, 10, fDouble);
    printf("\t(log n)^2\n");
    fDouble = logsqn;
    tableDouble(0, 100, 10, fDouble);
    printf("\tn^(log(log(n)))\n");
    fDouble = nloglogn;
    tableDouble(0, 100, 10, nloglogn);
    printf("\tsqrt(2)^logn\n");
    fDouble = sqrt2logn;
    tableDouble(0, 100, 10, fDouble);
    printf("\tFactorial\n");
    fLong = factorial;
    tablelong(0,20,2, fLong);
}
