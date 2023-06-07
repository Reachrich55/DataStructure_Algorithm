#include <iostream>

using namespace std;

//简单选择排序
void SimpleSelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        int tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
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

    SimpleSelectionSort(arr, n);

    printf("排序后的数组: ");
    printArray(arr, n);

    return 0;
}
