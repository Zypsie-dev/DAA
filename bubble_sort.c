#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }  
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int n, x, result;
    printf("Enter the size of array:");
    scanf("%d", &n);
    int arr[n], randNum;
    for (int i = 0; i < n; i++)
    {
        randNum = rand() % n;
        arr[i] = randNum;
    }
    clock_t start, end;
    start = clock();
    int num = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, num);
    end = clock();
    printf("\nTime=%lf sec\n", 
    ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}
