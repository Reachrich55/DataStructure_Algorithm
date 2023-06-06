#include <iostream>

using namespace std;

//直接插入排序
void InsertSort(int arr[], int n) {
    int i, j, tmp;
    for ( i = 1; i < n; i++)
    {
        tmp = arr[i];
        for ( j = i - 1; j >= 0; j--)
        {
            if (arr[j] > tmp) {
                arr[j + 1] = arr[j];
            }
            else break;
        }
        arr[j + 1] = tmp;
    }
}

//打印数组
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = { 49,38,65,97,76,13,27,49 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    printArray(arr, n);

    InsertSort(arr, n);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
