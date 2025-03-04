#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 10
#define N 100
int temp[N];

void initArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)

    {
        arr[i] = rand() % 20;
    }
}


void showArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n------------------\n");
}

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubSort(int arr[], int length)
{
    int flag = 1;
    while (length-- && flag)
    {
        flag = 0;
        for (int i = 0; i < length; i++)
        {

            if (arr[i + 1] < arr[i])
            {
                flag = 1;
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

void selectSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int k = i;
        for (int j = i + 1; j < length; j++)
            if (arr[j] < arr[k])
                k = j; // 更新最小位置
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
}

void insertSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int j = i; j >= 1 && arr[j] < arr[j - 1]; j--)
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

void shellSort(int arr[], int length)
{
    int h = 1;
    int t = length / 3;
    while (h < t)
        h = h * 3 + 1;
    while (h >= 1)
    {
        for (int i = h; i < length; i++)
        {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h)
            {
                int temp = arr[j];
                arr[j] = arr[j - h];
                arr[j - h] = temp;
            }
        }
        h /= 2;
    }
}

void quicksort(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int pivot = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
            j--;
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot)
            i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quicksort(arr, left, i - 1);
    quicksort(arr, i + 1, right);
}

void quicksort2(int arr[], int left, int right)
{
    if (left >= right)
        return;
    int pivot = arr[left];
    int i = left + 1;
    int j = left + 1;
    while (j <= right)
    {
        if (arr[j] < pivot)
        {
            swap(arr, i, j);
            i++;
        }
        j++;
    }
    swap(arr, left, i - 1);
    quicksort2(arr, left, i - 2);
    quicksort2(arr, i, right);
}

void mergeSort(int a[], int alen, int b[], int blen, int *temp)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < alen && j < blen)
    {
        if (a[i] < b[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < alen)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j < blen)
    {
        temp[k] = b[j];
        k++;
        j++;
    }
}

void merge(int arr[], int low, int mid, int height, int *temp)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= height)
        temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= height)
        temp[k++] = arr[j++];
    for (i = low; i <= height; i++)
        arr[i] = temp[i];
}

void merge_sort(int arr[], int low, int height, int *temp)
{
    if (low >= height)
        return;
    int mid = low + (height - low) / 2; //(low+height)/2
    merge_sort(arr, low, mid, temp);
    merge_sort(arr, mid + 1, height, temp);
    merge(arr, low, mid, height, temp);
}

void mergesort(int arr[], int length)
{
    int *temp = (int *)malloc(sizeof(int) * length);
    assert(temp);
    merge_sort(arr, 0, length - 1, temp);
    free(temp);
}

void heapify(int arr[], int length, int current)
{
    int rchild = 2 * current + 2;
    int large;
    while (rchild <= length)
    {
        large = rchild == length ? rchild - 1 : (arr[rchild - 1] > arr[rchild] ? rchild - 1 : rchild);
        if (arr[large] > arr[current])
        {
            swap(arr, large, current);
            current = large;
            rchild = 2 * current + 2;
        }
        else
            break;
    }
}

void heapSort2(int arr[], int length)
{
    int current = length / 2; // 拿到最后一个数
    while (current >= 0)
    {
        heapify(arr, length, current);
        current--;
    }
    // showArr(arr, length);
    while (length > 0)
    {
        swap(arr, 0, --length);
        heapify(arr, length, 0);
    }
}

int Temp[10][N];

void redixsort(int arr[], int length)
{
    int i;
    int j;
    int pos;
    for (int k = 10; k < 10000; k *= 10)
    {
        for (int i = 0; i < length; i++)
        {
            int j = 0;
            int pos = (arr[i] % k) / (k / 10);
            while (Temp[pos][j])
                j++;
            Temp[pos][j] = arr[i];
        }
        pos = 0;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < length && Temp[i][j] != 0; j++)
            {
                arr[pos++] = Temp[i][j];
                Temp[i][j] = 0;
            }
        }
    }
}

void countSort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        temp[arr[i]]++;
    }
    for (int i = 0, j = 0; i < N; i++)
    {
        while (temp[i]--)
            arr[j++] = i;
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));
    int arr[MAXSIZE];
    initArr(arr, MAXSIZE);
    printf("Original array:\n");
    showArr(arr, MAXSIZE);
    // // bubSort(arr, MAXSIZE);
    countSort(arr, MAXSIZE);
    printf("Sorted array:\n");
    showArr(arr, MAXSIZE);
    // insertSort(arr, MAXSIZE);
    // showArr(arr, MAXSIZE);
    // // shellSort(arr, MAXSIZE);
    // // showArr(arr, MAXSIZE);
    // // quicksort(arr, 0, MAXSIZE - 1);
    // // showArr(arr, MAXSIZE);
    // quicksort2(arr, 0, MAXSIZE - 1);
    // showArr(arr, MAXSIZE);

    // int a[5] = {1, 3, 5, 7, 9};
    // int b[3] = {2, 8, 10};
    // int temp[8];
    // mergeSort(a, 5, b, 3, temp);
    // showArr(temp, 8);
    system("pause");
    return 0;
}
