#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{

    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {

        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
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
    heapSort(arr, num);
    end = clock();
    printf("\nTime=%lf sec\n",
           ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}