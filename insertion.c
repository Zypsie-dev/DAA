// Insertion sort
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
void insertionSort(int array[], int size)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;

        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
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
    insertionSort(arr, n);
    end = clock();
    printf("\nTime=%lf sec\n",
           ((double)(end - start)) / CLOCKS_PER_SEC);
}