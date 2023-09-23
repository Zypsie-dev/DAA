#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n, x, result;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int array[n], randNum;
    for (int i = 0; i < n; i++)
    {
        randNum = rand() % n;
        array[i] = randNum;
    }
    printf("Enter the number to be searched:");
    scanf("%d", &x);
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            result = i;
    result = -1;
    end = clock();
    printf("Time=%lf nano seconds\n", 
    ((double)(end - start) * 1000000) / CLOCKS_PER_SEC);

    (result == -1) ? printf("Element not found") 
    : printf("Element found at index: %d", result);
}